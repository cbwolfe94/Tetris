OBJECTS = main.o tetromino.o game.o
CXX = gcc
FLAGS = -Wall
LL = -lncurses

tetris: $(OBJECTS)
	$(CC) -o tetris $(OBJECTS) $(FLAGS) $(LL)

game.o: game.c tetromino.h
	$(CC) -c game.c $(FLAGS)


tetromino.o: tetromino.c tetromino.h
	$(CC) -c tetromino.c $(FLAGS)

main.o: main.c game.h
	$(CC) -c main.c $(FLAGS)

.PHONY = clean

clean:
	rm -f tetris *.o
