#include "tetromino.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct tetromino {
    //Default fall position for all tetromino blocks
    // int startPositionX;
    // int startPositionY;
    
    //Location of cells of each tetromino block
    // int firstCellPosition;
    // int secondCellPosition;
    // int thirdCellPosition;
    // int fourthCellPosition;

    //Difference kinds of tetromino i.e. I, O, T, S, Z J, and L
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
    free(block->typeOfBlock);
    free(block);
}

void printContentsOfTetromino(tetromino* block) {
    printf("This is an %s.\n", block->typeOfBlock);
}