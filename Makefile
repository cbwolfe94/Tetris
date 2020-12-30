OBJECTS = main.o
CXX = gcc
FLAGS = -Wall 
LL = -lncurses

tetris: $(OBJECTS)
	$(CC) -o tetris $(OBJECTS) $(FLAGS) $(LL)

main.o: main.c
	$(CC) -c main.c $(FLAGS)

.PHONY = clean
clean:
	rm -f tetris *.o
