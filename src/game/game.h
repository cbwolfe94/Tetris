#ifndef GAME_H
#define GAME_H
#include "tetromino_types.h"

static const int GRAVITY_LEVEL[20] = {
// 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
  50, 48, 46, 44, 42, 40, 38, 36, 34, 32,
//10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
  30, 28, 26, 24, 22, 20, 16, 12,  8,  4
};

typedef struct  
{
    WINDOW *gameWindow;
    WINDOW *scoreWindow; 
    WINDOW *currentLevelWindow;
    WINDOW *nextBlockWindow;
    WINDOW *linesClearedWindow;
    WINDOW *statisticsWindow;

    Tetromino_t currentBlock;
    Tetromino_t nextBlock;

    uint32_t block_statistics[7];
    uint32_t lines_cleared;
    uint8_t current_level;
    uint32_t currentScore;
    uint32_t topScore;
    int gravity;
} TetrisGame_t;

void colorsInit(void);
void gameInit(void);
void gameLoop(void);
#endif