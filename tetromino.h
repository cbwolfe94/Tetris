#ifndef TETROMINO_H
#define TETROMINO_H
#include <ncurses.h> 


// #define I_BLOCK_COLOR = COLOR_RED;
// #define O_BLOCK_COLOR = COLOR_GREEN;
// #define T_BLOCK_COLOR = COLOR_YELLOW;
// #define S_BLOCK_COLOR = COLOR_BLUE;
// #define Z_BLOCK_COLOR = COLOR_MAGENTA;
// #define J_BLOCK_COLOR = COLOR_CYAN;
// #define L_BLOCK_COLOR = COLOR_WHITE;


// const int DEFAULT_STARTING_COORDINATE;
// const int I_BLOCK_COORDINATES = ;
// const int O_BLOCK_COORDINATES;
// const int T_BLOCK_COORDINATES;
// const int S_BLOCK_COORDINATES;
// const int Z_BLOCK_COORDINATES;
// const int J_BLOCK_COORDINATES;


typedef struct tetromino tetromino;

tetromino* createTetromino(char* typeOfBlock);

void rotateTetromino(tetromino* block, char* direction);

void moveTetromino(tetromino* block, char* direction);

void displayTetromino(tetromino* block);

void freeTetromino(tetromino* block);

#endif