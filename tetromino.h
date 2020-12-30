#ifndef TETROMINO_H
#define TETROMINO_H

typedef struct tetromino tetromino;

tetromino* createTetromino(char* typeOfBlock);

void rotateTetromino(tetromino* block, char* direction);

void moveTetromino(tetromino* block, char* direction);

void displayTetromino(tetromino* block);

void freeTetromino(tetromino* block);

void printContentsOfTetromino(tetromino* block);

#endif