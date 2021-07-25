#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "game.h"
#include "tetromino.h"

int main()
{
    int ch;
    int start_x, start_y, y_max, x_max;
	start_x = start_y = 0;
    clock_t start_time, current_time;
    double time_elapsed;

    initscr();
    //cbreak();
    noecho();
    clear();
    curs_set(false);
	getmaxyx(stdscr, y_max, x_max);
	WINDOW* window = newwin(y_max, x_max, start_y, start_x);
    wrefresh(window);
    nodelay(window, true);
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
    init_pair(7, COLOR_WHITE, COLOR_WHITE);

    struct tetromino *block = new_tetromino_create();
    
    
    start_time = clock(); 
    while(true) {
        current_time = clock();
        time_elapsed = (double)(current_time - start_time) / CLOCKS_PER_SEC;
        if (time_elapsed > 0.5) {
            tetromino_drop(block);
            start_time = clock();
        }
        erase();
        ch = wgetch(window);
        //printw("   %i", ch);
        if (ch == 32) {
            tetromino_rotate(block);
        }
        else {
            tetromino_move(block, ch);
        }
        
        tetromino_display(block);
        refresh();
        //wrefresh(stdscr);
        
    }
    endwin();
    return 0;
}