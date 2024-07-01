##########################
# Main Application CMake #
##########################
# Application files only.

add_executable(${APP_NAME})

target_link_libraries(${APP_NAME}
    ${CURSES_LIBRARIES}
)

# These compile options are only applied to our source files.
# Applying -Wall and -Werror globally via add_compile_options() in the top-level
# CMakeLists file can lead to issues with compile warnings in vendor-supplied
# device files or in third-party libraries.
target_compile_options(${APP_NAME}
    PRIVATE
    -Wall
    -Wextra
    -Wno-missing-field-initializers
    -Wno-unused-variable
    -Wno-unused-parameter
    -Wno-unused-function
    -Wno-unused-but-set-variable
    -funsigned-char
)

target_sources(${APP_NAME}
    PRIVATE
    main.c
    game/game.c
    tetromino/tetromino.c
)

target_include_directories(${APP_NAME}
    PUBLIC
    ${CURSES_INCLUDE_PATH}
    game/
    tetromino/
)
