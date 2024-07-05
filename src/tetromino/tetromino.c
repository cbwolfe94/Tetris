#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "game_types.h"
#include "windows_defs.h"
#include "tetromino_types.h"
#include "helpers.h"
#include "tetromino.h"

static uint16_t globalOffsetX = 25;
static uint16_t globalOffsetY = 6;

static const Tetromino_t defaultTetrominos[7] = {
    [TETROMINO_TYPE_I] = {
        .type = TETROMINO_TYPE_I,
        .colorPair = COLOR_RED, 
        .blockPositions = {
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE - 2}, 
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE - 1},
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE},
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE + 1}
            }
    },
    
    [TETROMINO_TYPE_O] = {
        .type = TETROMINO_TYPE_O,
        .colorPair = COLOR_GREEN,
        .blockPositions = {
            {DEFAULT_X_COORDINATE - 2, DEFAULT_Y_COORDINATE},
            {DEFAULT_X_COORDINATE + 2, DEFAULT_Y_COORDINATE},
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE},
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE + 1}
            }
    },
    
    [TETROMINO_TYPE_T] = {
        .type = TETROMINO_TYPE_T,
        .colorPair = COLOR_YELLOW,
        .blockPositions = {
            {DEFAULT_X_COORDINATE + 2, DEFAULT_Y_COORDINATE - 1},
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE - 1},
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE},
            {DEFAULT_X_COORDINATE - 2, DEFAULT_Y_COORDINATE}
            },
    },

    [TETROMINO_TYPE_S] = {
        .type = TETROMINO_TYPE_S,
        .colorPair = COLOR_MAGENTA,
        .blockPositions = {
            {DEFAULT_X_COORDINATE - 2, DEFAULT_Y_COORDINATE - 1},
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE - 1},
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE},
            {DEFAULT_X_COORDINATE + 2, DEFAULT_Y_COORDINATE}
            },
        },
    
    [TETROMINO_TYPE_Z] = {
        .type = TETROMINO_TYPE_Z,
        .colorPair = COLOR_CYAN, 
        .blockPositions = {
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE - 2},
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE - 1},
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE},
            {DEFAULT_X_COORDINATE - 2, DEFAULT_Y_COORDINATE}
            }
        },
    
    [TETROMINO_TYPE_J] = {
        .type = TETROMINO_TYPE_J,
        .colorPair = COLOR_WHITE,
        .blockPositions = {
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE - 2},
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE - 1},
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE},
            {DEFAULT_X_COORDINATE + 2, DEFAULT_Y_COORDINATE}
            }
        },
    
    [TETROMINO_TYPE_L] = {
        .type = TETROMINO_TYPE_L,
        .colorPair = COLOR_GREEN,
        .blockPositions = {
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE - 1},
            {DEFAULT_X_COORDINATE + 2, DEFAULT_Y_COORDINATE - 1},
            {DEFAULT_X_COORDINATE, DEFAULT_Y_COORDINATE},
            {DEFAULT_X_COORDINATE + 2, DEFAULT_Y_COORDINATE}
        }
    },
};

Tetromino_t getNewTetromino(void)
{
    TetrominoType_t type = getRandomNumber();
    Tetromino_t newTetromino;

    memcpy(&newTetromino, &defaultTetrominos[type], sizeof(Tetromino_t));
    return newTetromino;
}

void rotateTetromino(Tetromino_t *tetromino)
{
    if (tetromino->type == TETROMINO_TYPE_O)
    {
        return;
    }
    
    if (checkWallCollision(tetromino, GAME_WALL_RIGHT) || checkWallCollision(tetromino, GAME_WALL_LEFT))
    {
        return;
    }
    
    // TODO: Investigate this

    /* struct tetromino *temp_block = malloc(sizeof(struct tetromino));

    if (block->type_of_block == 'O') {
        return;
    }

    for (int i = 0; i < 4; i++) {
        temp_block->block_position[i][0] = (block->block_position[i][0] - x_offset)*0 + (block->block_position[i][1] - y_offset)*(-2);
        temp_block->block_position[i][1] = ((block->block_position[i][0] - x_offset)*2)/4 + (block->block_position[i][1] - y_offset)*(0);
    }
    for (int i = 0; i < 4; i++) {
        block->block_position[i][0] = temp_block->block_position[i][0] + x_offset;
        block->block_position[i][1] = temp_block->block_position[i][1] + y_offset;
    }
     */
    return;
}

/**
 * @brief Moves a given tetromino horizontally
 * 
 * @param tetromino Tetromino pointer
 * @param pixelTranslationDistance Distance of pixel to be translated 
 */
static void moveTetrominoHorizontal(Tetromino_t *tetromino, const int8_t pixelTranslationDistance)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        tetromino->blockPositions[i][1] += pixelTranslationDistance;   
    }
    globalOffsetX += pixelTranslationDistance;
}

/**
 * @brief Moves a given tetromino vertically
 * 
 * @param tetromino Tetromino pointer
 * @param pixelTranslationDistance Distance of pixel to be translated 
 */
static void moveTetrominoVertical(Tetromino_t *tetromino, const int8_t pixelTranslationDistance)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        tetromino->blockPositions[i][0] += pixelTranslationDistance;   
    }
    globalOffsetY += pixelTranslationDistance;
}

/**
 * @brief Moves tetromino one unit
 * 
 * @param tetromino Tetromino pointer
 * @param direction Direction to move tetromino
 */
void moveTetromino(Tetromino_t *tetromino, const TetrominoDirection_t direction)
{
    switch (direction) {
        case TETROMINO_DIRECTION_DOWN:
            if (checkWallCollision(tetromino, GAME_WALL_BOTTOM) /* OR(||) check for collision with filled game grid */)
            {
                // Place piece on game grid
                // Generate event
                return;
            }
            else
            {
                moveTetrominoVertical(tetromino, -1);
            }
        break;

        // This is for testing
        case TETROMINO_DIRECTION_UP:
            if (checkWallCollision(tetromino, GAME_WALL_TOP))
            {
                return;
            }
            else
            {
                moveTetrominoVertical(tetromino, 1);
            }
            break;

        case TETROMINO_DIRECTION_RIGHT:
            if (checkWallCollision(tetromino, GAME_WALL_RIGHT))
            {
                return;
            }
            else
            {
                moveTetrominoHorizontal(tetromino, -2);
            }
            break;

        case TETROMINO_DIRECTION_LEFT:
            if (checkWallCollision(tetromino, GAME_WALL_LEFT))
            {
                break;
            }
            else
            {
                moveTetrominoHorizontal(tetromino, 2);
            }
            
            break;

        default:
            break;
    }
}

/**
 * @brief Drops tetromino by one vertical unit down
 * 
 * @param tetromino 
 */
void dropTetromino(Tetromino_t *tetromino)
{
    moveTetromino(tetromino, TETROMINO_DIRECTION_DOWN);
}
/**
 * @brief Checks to see if a given tetromino is going to collide with a given coordinate along the Y axis
 * 
 * @param tetromino Tetromino pointer
 * @param collisionCoordinate Coordinate to check collision against
 * @return true If tetromino is going to collide with given collision coordinate 
 * @return false If tetromino is not going to collide with given collision coordinate
 */
static bool checkVerticalBlockCollision(const Tetromino_t *tetromino, const uint16_t collisionCoordinate_Y)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        if (tetromino->blockPositions[0][i] == collisionCoordinate_Y)
        {
            return true;
        }
    }
    
    return false;
}

/**
 * @brief Checks to see if a tetromino is going to collide with a given coordinate along the X axis
 * 
 * @param tetromino Tetromino pointer
 * @param collisionCoordinate Coordinate to check collision against
 * @return true If tetromino is going to collide with given collision coordinate 
 * @return false If tetromino is not going to collide with given collision coordinate
 */
static bool checkHorizontalTetrominoCollision(const Tetromino_t *tetromino, const uint16_t collisionCoordinate_X)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        if (tetromino->blockPositions[i][0] == collisionCoordinate_X)
        {
            return true;
        }
    }
    
    return false;
}

/**
 * @brief Checks collision between tetromino and specified wall
 * 
 * @param tetromino 
 * @param wall 
 * @return true 
 * @return false 
 */
bool checkWallCollision(const Tetromino_t *tetromino, const GameWall_t wall)
{
    switch (wall) {
        case GAME_WALL_LEFT:
            return checkHorizontalTetrominoCollision(tetromino, 1);
            break;
        
        case GAME_WALL_RIGHT:
            return checkHorizontalTetrominoCollision(tetromino, 47);
            break;

        case GAME_WALL_TOP:
            return checkVerticalBlockCollision(tetromino, 1);
            break;

        case GAME_WALL_BOTTOM:
            return checkVerticalBlockCollision(tetromino, 100);
            break;

        default:
            return true;
    }
}

void printTetromino(const Tetromino_t *tetromino)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        for (uint8_t j = 0; j < 2; j++)
        {
            printf("%d ", tetromino->blockPositions[i][j]);
        }
        printf("\n");
    }
}