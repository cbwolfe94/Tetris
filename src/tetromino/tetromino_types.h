#ifndef TETROMINO_TYPES_H
#define TETROMINO_TYPES_H
#include <stdint.h>

typedef enum {
    TETROMINO_TYPE_START,
    TETROMINO_TYPE_I = TETROMINO_TYPE_START,
    TETROMINO_TYPE_O,
    TETROMINO_TYPE_T,
    TETROMINO_TYPE_S,
    TETROMINO_TYPE_Z,
    TETROMINO_TYPE_J,
    TETROMINO_TYPE_L,
    TETROMINO_TYPE_COUNT,
    TETROMINO_TYPE_INVALID,
} TetrominoType_t;

typedef enum
{
    TETROMINO_DIRECTION_START = 0,
    TETROMINO_DIRECTION_UP = TETROMINO_DIRECTION_START,
    TETROMINO_DIRECTION_DOWN,
    TETROMINO_DIRECTION_LEFT,
    TETROMINO_DIRECTION_RIGHT,
} TetrominoDirection_t;

typedef struct
{
    TetrominoType_t type;
    uint8_t colorPair;
    int16_t blockPositions[4][2]; // Investigate to see if this needs to be a signed int
} Tetromino_t;


#endif