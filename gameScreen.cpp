#include <ncurses.h>
#include "gameScreen.h"

GameScreen::GameScreen() {
	WINDOW* mainWindow;
	createMainWindow();
	createStatisticsWindow();
	createLinesClearedWindow();
	createPlayingFieldWindow();
	createScoreWindow();
	createNextPieceWindow();
	createLevelWindow();
}

void GameScreen::createMainWindow() {
	int startY, startX, yMax, xMax;
	startY = startX = 0;
	getmaxyx(stdscr, yMax, xMax);
	mainWindow = newwin(yMax, xMax, startY, startX);
	refresh();
	box(mainWindow, 0, 0);
	wrefresh(mainWindow);
}

void GameScreen::createStatisticsWindow() {
	
}

void GameScreen::createLinesClearedWindow() {

}

void GameScreen::createPlayingFieldWindow(){

}

void GameScreen::createScoreWindow(){

}

void GameScreen::createNextPieceWindow() {

}

void GameScreen::createLevelWindow() {

}

void GameScreen::eventLoop() {
	while(1) {
		refresh();
		int choice = wgetch(mainWindow);
		if (choice == (int)'p'){
			delwin(mainWindow);
			return;
		}
		
	}
}
