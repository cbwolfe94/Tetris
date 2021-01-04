#include <stdio.h>
#include "game.h"



int main() {
    initscr();
    cbreak();
    noecho();
    clear();
    start_color();

    //init_pair()

    //tetromino* O_Block = createTetromino("O Block");
    
    endwin();
    
    

    return 0;
}