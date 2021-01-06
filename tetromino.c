
#include "tetromino.h"
const int L_PIECE_COORDINATES[4][2] = {{4, 35}, {5, 35}, {6, 35}, {7,35}};
const int O_PIECE_COORDINATES[4][2] = {{9, 35}, {10, 35}, {9, 37}, {10, 37}}; 



struct tetromino {
    //Default fall position for all tetromino blocks
    // int startPositionX;
    // int startPositionY;
    
    //Location of cells of each tetromino block
    //int blockPosition[4][2];

    //int fallSpeed;

};

tetromino* createTetromino() {
    
    tetromino* block = (tetromino*)malloc(sizeof(tetromino));
    //block->blockPosition = DEFAULT_STARTING_COORDINATE;
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
    for (int row = 0; row < 4; row++) {
        mvaddstr(O_PIECE_COORDINATES[row][0], O_PIECE_COORDINATES[row][1], "[]");
    }
}

void freeTetromino(tetromino* block) {
    return;
}
