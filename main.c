#include <unistd.h>
#include <stdio.h>
#include "game.h"


int main() {
    initscr();
    cbreak();
    noecho();
    clear();

	int startY, startX, yMax, xMax;
	startY = startX = 0;
	getmaxyx(stdscr, yMax, xMax);
	WINDOW* window = newwin(yMax, xMax, startY, startX);
    wrefresh(window);

    start_color();

    init_pair(1, COLOR_RED, COLOR_RED);
    // init_pair(2, COLOR_GREEN, COLOR_GREEN);
    // init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    // init_pair(4, COLOR_BLUE, COLOR_BLUE);
    // init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    // init_pair(6, COLOR_CYAN, COLOR_CYAN);
    // init_pair(7, COLOR_WHITE, COLOR_WHITE);
    //tetromino* O_Block = createTetromino("O Block");

    tetromino piece = {5};
    //piece->blockPosition = {4, 35}, {5, 35}, {6, 35}, {7,35};
    
    attron(COLOR_PAIR(1));
    // mvaddstr(4, 35, "[]");
    // mvaddstr(5, 35, "[]");
    // mvaddstr(6, 35, "[]");
    // mvaddstr(7, 35, "[]");
    attroff(COLOR_PAIR(1));


    // attron(COLOR_PAIR(2));
    // mvaddstr(9, 35, "[][]");
    // mvaddstr(10, 35, "[][]");
    // attroff(COLOR_PAIR(2));

    // attron(COLOR_PAIR(3));
    // mvaddstr(12, 33, "[][][]");
    // mvaddstr(13, 35, "[]");
    // attroff(COLOR_PAIR(3));

    // attron(COLOR_PAIR(4));

    // mvaddstr(15, 37, "[][]");
    // mvaddstr(16, 35, "[][]");

    // attroff(COLOR_PAIR(4));

    // attron(COLOR_PAIR(5));

    // mvaddstr(18, 33, "[][]");
    // mvaddstr(19, 35, "[][]");

    // attroff(COLOR_PAIR(5));

    // attron(COLOR_PAIR(6));

    // mvaddstr(21, 37, "[]");
    // mvaddstr(22, 37, "[]");
    // mvaddstr(23, 35, "[][]");

    // attroff(COLOR_PAIR(6));

    // attron(COLOR_PAIR(7));

    // mvaddstr(25, 35, "[]");
    // mvaddstr(26, 35, "[]");
    // mvaddstr(27, 35, "[][]");

    // attroff(COLOR_PAIR(7));

    refresh();
    sleep(5);
    endwin();
    
    

    return 0;
}