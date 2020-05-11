#include <unistd.h>
#include <string>
#include <ncurses.h>
#include "introScreen.h"
#include "gameScreen.h"

introScreen::introScreen() {
	WINDOW* window;
	createMainWindow();
	loadAssets();
	loadMenu();
}
void introScreen::createMainWindow() {
	int startY, startX, yMax, xMax;
	startY = startX = 0;
	getmaxyx(stdscr, yMax, xMax);
	window = newwin(yMax, xMax, startY, startX);
	refresh();
	box(window, 0, 0);
	wrefresh(window);
}	

void introScreen::loadAssets(){
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	
	move(yMax/2 - 12,xMax/2 - 59);
	addstr("-------------------");
	move(yMax/2 - 11,xMax/2 - 59);
	addstr("|                 |");
	move(yMax/2 - 10,xMax/2 - 59);
	addstr("|                 |");
	move(yMax/2 - 9,xMax/2 - 59);
	addstr("------       ------");
	move(yMax/2 - 8,xMax/2 - 59);
	addstr("      |     |");
	move(yMax/2 - 7,xMax/2 - 59);
	addstr("      |     |");
	move(yMax/2 - 6,xMax/2 - 59);
	addstr("      |     |");
	move(yMax/2 - 5,xMax/2 - 59);
	addstr("      |     |");
	move(yMax/2 - 4,xMax/2 - 59);
	addstr("      |     |");
	move(yMax/2 - 3,xMax/2 - 59);
	addstr("      |     |");
	move(yMax/2 - 2,xMax/2 - 59);
	addstr("      -------");
	
	
	move(yMax/2 - 12,xMax/2 - 38);
	addstr("--------------");
	move(yMax/2 - 11,xMax/2 - 38);
	addstr("|             |");
	move(yMax/2 - 10,xMax/2 - 38);
	addstr("|     --------");
	move(yMax/2 - 9,xMax/2 - 38);
	addstr("|     |");
	move(yMax/2 - 8,xMax/2 - 38);
	addstr("|     --------");
	move(yMax/2 - 7,xMax/2 - 38);
	addstr("|             |");
	move(yMax/2 - 6,xMax/2 - 38);
	addstr("|     --------");
	move(yMax/2 - 5,xMax/2 - 38);
	addstr("|      |");
	move(yMax/2 - 4,xMax/2 - 38);
	addstr("|     --------");
	move(yMax/2 - 3,xMax/2 - 38);
	addstr("|             |");
	move(yMax/2 - 2,xMax/2 - 38);
	addstr("--------------");

	move(yMax/2 - 12,xMax/2 - 21);
	addstr("-------------------");
	move(yMax/2 - 11,xMax/2 - 21);
	addstr("|                 |");
	move(yMax/2 - 10,xMax/2 - 21);
	addstr("|                 |");
	move(yMax/2 - 9,xMax/2 - 21);
	addstr("------       ------");
	move(yMax/2 - 8,xMax/2 - 21);
	addstr("      |     |");
	move(yMax/2 - 7,xMax/2 - 21);
	addstr("      |     |");
	move(yMax/2 - 6,xMax/2 - 21);
	addstr("      |     |");
	move(yMax/2 - 5,xMax/2 - 21);
	addstr("      |     |");
	move(yMax/2 - 4,xMax/2 - 21);
	addstr("      |     |");
	move(yMax/2 - 3,xMax/2 - 21);
	addstr("      |     |");
	move(yMax/2 - 2,xMax/2 - 21);
	addstr("      -------");
	


	move(yMax/2 - 12,xMax/2);
	addstr("---------------");
	move(yMax/2 - 11,xMax/2);
	addstr("|     ----     |");
	move(yMax/2 - 10,xMax/2);
	addstr("|    |    |    |");
	move(yMax/2 - 9,xMax/2);
	addstr("|    |    |    |");
	move(yMax/2 - 8,xMax/2);
	addstr("|     ----     |");
	move(yMax/2 - 7,xMax/2);
	addstr("|    -----------");
	move(yMax/2 - 6,xMax/2);
	addstr("|    |     |     |");
	move(yMax/2 - 5,xMax/2);
	addstr("|    |     |     |");
	move(yMax/2 - 4,xMax/2);
	addstr("|    |     |     |");
	move(yMax/2 - 3,xMax/2);
	addstr("|    |     |     |");
	move(yMax/2 - 2,xMax/2);
	addstr("------     ------");
	

	move(yMax/2 - 12,xMax/2 + 20);
	addstr("-------------------");
	move(yMax/2 - 11,xMax/2 + 20);
	addstr("|                 |");
	move(yMax/2 - 10,xMax/2 + 20);
	addstr("|                 |");
	move(yMax/2 - 9,xMax/2 + 20);
	addstr("------       ------");
	move(yMax/2 - 8,xMax/2 + 20);
	addstr("      |     |");
	move(yMax/2 - 7,xMax/2 + 20);
	addstr("      |     |");
	move(yMax/2 - 6,xMax/2 + 20);
	addstr("      |     |");
	move(yMax/2 - 5,xMax/2 + 20);
	addstr("------       ------");
	move(yMax/2 - 4,xMax/2 + 20);
	addstr("|                 |");
	move(yMax/2 - 3,xMax/2 + 20);
	addstr("|                 |");
	move(yMax/2 - 2,xMax/2 + 20);
	addstr("-------------------");
	

	move(yMax/2 - 12,xMax/2 + 40);
	addstr(" -----------");
	move(yMax/2 - 11,xMax/2 + 40);
	addstr(" |          |");
	move(yMax/2 - 10,xMax/2 + 40);
	addstr(" |    ------");
	move(yMax/2 - 9,xMax/2 + 40);
	addstr(" |    |");
	move(yMax/2 - 8,xMax/2 + 40);
	addstr(" |    ------");
	move(yMax/2 - 7,xMax/2 + 40);
	addstr(" |          |");
	move(yMax/2 - 6,xMax/2 + 40);
	addstr(" -------    |");
	move(yMax/2 - 5,xMax/2 + 40);
	addstr("        |   |");
	move(yMax/2 - 4,xMax/2 + 40);
	addstr(" -------    |");
	move(yMax/2 - 3,xMax/2 + 40);
	addstr(" |          |");
	move(yMax/2 - 2,xMax/2 + 40);
	addstr(" ------------");
	refresh();
}

void introScreen::loadMenu() {
	int  yMax, xMax, option;
	option = -1;
	//height = 50;
	//width = 70;

	//startY = startX = 0;
	getmaxyx(stdscr, yMax, xMax);
	move(yMax/2, xMax/2);
	keypad(window, true);
	std::string choices[4] = {"Start Game", "Quit Game", "High Scores", "Credits"};
	int choice;
	int highlight = 0;
	while(1) {
		//choice = 0;
		//wrefresh(window);
		refresh();
		for (int i = 0; i < 4; i++) {
			if (i == highlight) {
				wattron(window, A_REVERSE);
				
			}
			mvwprintw(window, i + yMax/2, xMax/2 - 10, choices[i].c_str());
			wattroff(window, A_REVERSE);

}		//printw(" Choice before: %d ", choice);
		choice = wgetch(window);
		//printw(" Choice after: %d ", choice);
	
		switch (choice) {
			case KEY_UP:
				//printw(" In key up ");
				highlight--;
				if (highlight == -1) {
					highlight = 0;
				}
				break;
			
			case KEY_DOWN:
				highlight++;
				if (highlight == 4) {
					highlight = 3;
				}
				break;
			case 10:
				option = highlight;
				break;
		
			default:
				break;
			
		}
		if (option == 0) {
			printw(" %d ", highlight);
			GameScreen* newGame = new GameScreen();
			newGame->eventLoop();
			delete newGame;
			createMainWindow();
			loadAssets();
			keypad(window, true);
		//	wrefresh(window);
			option = -1;
		}
		if (option == 1) {
			option = -1;
			return;
		}

		if (option == 2) {
			
		}

		if (option == 3) {
			
		}
}
}



