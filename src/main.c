#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include "game.h"
#include "tetromino.h"

int main()
{
    srand(time(NULL));
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    colors_init();
    struct tetris_game *new_game = game_init();
    main_game_loop(new_game);   
    endwin();
    return 0;
}