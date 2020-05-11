#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include <ncurses.h>


class GameScreen {
	WINDOW* mainWindow;
	WINDOW* statisticsWindow;
	WINDOW* linesClearedWindow;
	WINDOW* playingFieldWindow;
	WINDOW* scoreWindow;
	WINDOW* nextPieceWindow;
	WINDOW* levelWindow;
	
	void createMainWindow();
	void createStatisticsWindow();
	void createPlayingFieldWindow();
	void createLinesClearedWindow();
	void createScoreWindow();
	void createNextPieceWindow();
	void createLevelWindow();
	
	
public:
	void eventLoop();
	GameScreen();	


};

#endif
