#ifndef INTROSCREEN_H
#define INTROSCREEN_H
#include <ncurses.h>
#include "gameScreen.h"
#include "highScoresScreen.h"
#include "creditsScreen.h"

class introScreen {
private:
	WINDOW* window;
	//gameScreen* gameScreen;
	//highScoreScreen* highScoreScreen;
	//creditsScreen* creditsScreen;
	void createWindow();
	void loadAssets();
	void loadMenu();
public:
	introScreen();

};


#endif 
