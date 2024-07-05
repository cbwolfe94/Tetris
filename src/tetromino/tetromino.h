#ifndef TETROMINO_H
#define TETROMINO_H

#include <stdbool.h>
#include "tetromino_types.h"
#include "game_types.h"

Tetromino_t getNewTetromino(void);
void rotateTetromino(Tetromino_t *tetromino);
void moveTetromino(Tetromino_t *tetromino, const TetrominoDirection_t direction);
bool checkWallCollision(const Tetromino_t *tetromino, const GameWall_t wall);
void dropTetromino(Tetromino_t *tetromino);
void printTetromino(const Tetromino_t *tetromino);

#endif