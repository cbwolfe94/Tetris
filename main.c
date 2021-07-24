#include <unistd.h>
#include <stdio.h>
#include "game.h"
#include "tetromino.h"

int main()
{
    int start_x, start_y, y_max, x_max;
	start_x = start_y = 0;
    /*
    int ch;
    default_tetrominos_create();
    struct tetromino *test_block = new_tetromino_create();
    printf("Original Tetromino\n");
    print_tetromino(test_block);
    printf("\n");
    while(true) {
        ch = getchar();
        if (ch == 32) {
            x_offset--;
            printf("%f\n", x_offset);
        }
        if (ch == 'a'){
            tetromino_move(test_block, 67);
            tetromino_rotate(test_block);
            printf("%f\n", x_offset);
            //print_tetromino(test_block);
        }
    }*/
    
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

    default_tetrominos_create();

    struct tetromino *block = new_tetromino_create();

    int ch;

    while(true) {
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