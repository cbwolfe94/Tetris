#include "tetromino.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct tetromino {
    //Default fall position for all tetromino blocks
    // int startPositionX;
    // int startPositionY;
    
    //Location of cells of each tetromino block
    int cellPositions;

    //Difference kinds of tetromino i.e. I, O, T, S, Z, J, and L
    char* typeOfBlock;

    //int fallSpeed;

};

tetromino* createTetromino(char* typeOfBlock) {
    
    tetromino* block = (tetromino*)malloc(sizeof(tetromino));
    block->typeOfBlock = (char*)malloc(strlen(typeOfBlock));
    strcpy(block->typeOfBlock, typeOfBlock);
    return block;
}


void rotateTetromino(tetromino* block, char* direction) {

    return;
}

void moveTetromino(tetromino* block, char* direction) {
    return;
}

void displayTetromino(tetromino* block) {
    return;

}

void freeTetromino(tetromino* block) {
    return;
}
