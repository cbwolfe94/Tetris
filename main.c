#include <ncurses.h>
#include <stdio.h>
#include "tetromino.h"



int main() {
    tetromino* listOfBlocks[7];

    tetromino* O_Block = createTetromino("O Block");
    tetromino* I_Block = createTetromino("I Block");
    tetromino* T_Block = createTetromino("T Block");
    tetromino* S_Block = createTetromino("S Block");
    tetromino* Z_Block = createTetromino("Z Block");
    tetromino* J_Block = createTetromino("J Block");
    tetromino* L_Block = createTetromino("L Block");

    listOfBlocks[0] = O_Block;
    listOfBlocks[1] = L_Block;
    listOfBlocks[2] = T_Block;
    listOfBlocks[3] = Z_Block;
    listOfBlocks[4] = S_Block;
    listOfBlocks[5] = I_Block;
    listOfBlocks[6] = J_Block;


    for (int i = 0; i < 7; i++) {
        printContentsOfTetromino(listOfBlocks[i]);
    }

   for (int i = 0; i < 7; i++) {
       freeTetromino(listOfBlocks[i]);
   }

    return 0;
}