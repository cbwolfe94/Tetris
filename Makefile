OBJECTS = main.o tetromino.o
CXX = gcc
FLAGS = -Wall
LL = -lncurses

tetris: $(OBJECTS)
	$(CC) -o tetris $(OBJECTS) $(FLAGS) $(LL)

tetromino.o: tetromino.c tetromino.h
	$(CC) -c tetromino.c $(FLAGS)

main.o: main.c tetromino.h
	$(CC) -c main.c $(FLAGS)

.PHONY = clean
clean:
	rm -f tetris *.o
