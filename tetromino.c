
#include "tetromino.h"


struct tetromino {
    //Default fall position for all tetromino blocks
    // int startPositionX;
    // int startPositionY;
    
    //Location of cells of each tetromino block
    int blockPosition;

    //int fallSpeed;

};

tetromino* createTetromino() {
    
    tetromino* block = (tetromino*)malloc(sizeof(tetromino));
    // block->typeOfBlock = (char*)malloc(strlen(typeOfBlock));
    // strcpy(block->typeOfBlock, typeOfBlock);
    return block;
}


void rotateTetromino(tetromino* block, char* direction) {

    return;
}

void moveTetromino(tetromino* block, char* direction) {
    return;
}

void displayTetromino(tetromino* block) {
    for (int row = 0; row < 3; row++) {
        mvaddstr(block->blockPosition[row][0], block->blockPosition[row][1], "[]");
    }
}

void freeTetromino(tetromino* block) {
    return;
}
