#ifndef INTROSCREEN_H
#define INTROSCREEN_H
#include <ncurses.h>
#include "gameScreen.h"
#include "highScoresScreen.h"
#include "creditsScreen.h"

class introScreen {
private:
	WINDOW* window;
	void createMainWindow();
	void loadAssets();
	void loadMenu();
public:
	introScreen();
	void eventLoop();
};


#endif 
