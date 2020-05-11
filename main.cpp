#include <iostream>
#include <string>
#include <ncurses.h>
#include "introScreen.h"

//std::wstring tetromino[7];
//int fieldWidth = 12;
//int fieldHeight = 18;
//unsigned char* playingField = nullptr;

int main(){
	
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	introScreen newGame;
		

	endwin();

	return 0;
}
