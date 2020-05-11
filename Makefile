OBJECTS = main.o introScreen.o gameScreen.o highScoresScreen.o creditsScreen.o
CXX = g++
FLAGS = -Wall 
LL = -lncurses
tetris: $(OBJECTS)
	$(CXX) -o tetris $(OBJECTS) $(FLAGS) $(LL)

creditsScreen.o: creditsScreen.cpp creditsScreen.h
	$(CXX) -c creditsScreen.cpp $(FLAGS)

highScoresScreen.o: highScoresScreen.cpp highScoresScreen.h
	$(CXX) -c highScoresScreen.cpp $(FLAGS)

gameScreen.o: gameScreen.cpp gameScreen.h
	$(CXX) -c gameScreen.cpp $(FLAGS)

introScreen.o: introScreen.cpp introScreen.h
	$(CXX) -c introScreen.cpp $(FLAGS)

main.o: main.cpp introScreen.h
	$(CXX) -c main.cpp $(FLAGS)
.PHONY = clean
clean:
	rm -f tetris *.o
