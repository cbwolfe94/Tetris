SHELL := /bin/bash

.PHONY: run
run: 
	./build/src/application

.PHONY: build
build:
	cmake --build build

.PHONY: removebuild
removebuild:
	rm -rf build

.PHONY: test
test:
	ceedling test:all

.PHONY: clean
clean: clean-build clean-test

.PHONY: clean-build
clean-build:
	cmake --build build --target clean

clean-test:
	ceedling clean

.PHONY: rebuild
rebuild: clean-build build

.PHONY: regenerate
regenerate: remove-build generate build

.PHONY: generate
generate:
	cmake -G Ninja -B build

.PHONY: remove-build
remove-build:
	rm -rf build/**

.PHONY: format-check
format-check: have-clang-19
	git ls-files -- 'src/**' | grep -E '\.(c|h)$$' | xargs clang-format-19 --style=file:knowledge_base/coding/.clang-format -n --Werror

.PHONY: git-is-clean
git-is-clean:
	@git diff --quiet --exit-code || (echo "There are unstaged changes, it is not safe to run this command"; exit 1)

.PHONY: format-all
format-all: have-clang-19 git-is-clean
	@git ls-files -- 'src/**' | grep -E '\.(c|h)$$' | xargs clang-format-19 --style=file:knowledge_base/coding/.clang-format -i
	@echo "If happy with the changes you can ammend your last commit with git commit --ammend --no-edit to apply changes without an new commit"

.PHONY: have-clang-19
have-clang-19:
	@which clang-format-19 &> /dev/null || (echo "Missing clang-format 'sudo make get-clang'"; exit 1)
	@which clang-tidy-19 &> /dev/null || (echo "Missing clang-tidy 'sudo make get-clang'"; exit 1)

.PHONY: get-clang
get-clang:
	wget https://apt.llvm.org/llvm.sh
	chmod +x llvm.sh
	./llvm.sh 19
	apt install clang-format-19 clang-tidy-19
	rm llvm.sh

.PHONY: tools
tools:
	@echo "Downloading tools..."
	apt-get update
	apt-get -y install make cmake build-essential ruby ccache ninja-build
	gem install ceedling

.PHONY: clang-tidy
clang-tidy:
	./knowledge_base/scripts/parse_compile_commands_for_clang.py ./build_debug/compile_commands.json
	mv ./build_debug/compile_commands.json.mod ./build_debug/compile_commands.json
	run-clang-tidy-19 -j `nproc --all` -use-color -extra-arg=-Wno-implicit-function-declaration -config-file ./knowledge_base/.clang-tidy -p build_debug -source-filter `pwd`/src/ -header-filter `pwd`/src/ 2>/dev/null
#	run-clang-tidy -j 1 -use-color -config-file ./knowledge_base/.clang-tidy -p build_debug -source-filter src/ -header-filter \'^((?!/knowledge_base/).)*$\' 2>/dev/null

.PHONY: clang-tidy-fix
clang-tidy-fix: git-is-clean
	./knowledge_base/scripts/parse_compile_commands_for_clang.py ./build_debug/compile_commands.json
	mv ./build_debug/compile_commands.json.mod ./build_debug/compile_commands.json
	run-clang-tidy-19 -j `nproc --all` -fix -use-color -extra-arg=-Wno-implicit-function-declaration -config-file ./knowledge_base/.clang-tidy -p build_debug -source-filter `pwd`/src/ -header-filter `pwd`/src/ 2>/dev/null
	@echo "If happy with the changes you can ammend your last commit with git commit --ammend --no-edit to apply changes without a new commit"
