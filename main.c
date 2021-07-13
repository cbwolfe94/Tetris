#include <unistd.h>
#include <stdio.h>
#include "game.h"
#include "tetromino.h"

int main()
{
    int start_x, start_y, y_max, x_max;
	start_x = start_y = 0;

    initscr();
    cbreak();
    noecho();
    clear();
	getmaxyx(stdscr, y_max, x_max);
	WINDOW* window = newwin(y_max, x_max, start_y, start_x);
    wrefresh(window);
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
    init_pair(7, COLOR_WHITE, COLOR_WHITE);

    default_tetrominos_create();
    //display_tetromino(&tetrominos[1]);
    display_all_tetrominos(tetrominos);    
    refresh();
    sleep(5);
    endwin();

    /*for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d ", tetrominos[0].cell_positions[i][j]);
        }
        printf("\n");
    }*/
    
    return 0;
}