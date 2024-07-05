#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "game.h"
#include "tetromino.h"

/**
 * @brief Entry point of application
 * 
 * @return int 
 */
int main(void)
{
    srand(time(NULL));
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    colorsInit();
    gameInit();
    gameLoop();   
    endwin();

    return 0;
}