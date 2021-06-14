#ifndef TETROMINO_H
#define TETROMINO_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>



#define I_BLOCK_COLOR COLOR_RED
#define O_BLOCK_COLOR COLOR_GREEN
#define T_BLOCK_COLOR COLOR_YELLOW
#define S_BLOCK_COLOR COLOR_BLUE
#define Z_BLOCK_COLOR COLOR_MAGENTA
#define J_BLOCK_COLOR COLOR_CYAN
#define L_BLOCK_COLOR COLOR_WHITE



static int I_BLOCK_COORDINATES[4][2] = {{4, 35}, {5, 35}, {6, 35}, {7, 35}};

static int O_BLOCK_COORDINATES[4][2] = {{9, 35}, {9, 37}, {10, 35}, {10, 37}};

static int T_BLOCK_COORDINATES[4][2] = {{12, 33}, {12, 35}, {12, 37}, {13, 35}};

static int S_BLOCK_COORDINATES[4][2] = {{15, 37}, {15, 35}, {16, 35}, {16, 33}};

static int Z_BLOCK_COORDINATES[4][2] = {{18, 33}, {18, 35}, {19, 35}, {19, 37}};

static int J_BLOCK_COORDINATES[4][2] = {{21, 35}, {22, 35}, {23, 35}, {23, 33}};

static int L_BLOCK_COORDINATES[4][2] = {{25, 35}, {26, 35}, {27, 35}, {27, 37}};

struct tetromino {
    int color_pair;
    int block_position[4][2];
};

struct tetromino tetrominos[7];

void create_tetrominos(void);

void rotate_tetromino(struct tetromino *block, char direction);

void move_tetromino(struct tetromino *block, char direction);

void display_tetromino(struct tetromino block);

void display_all_tetrominos(struct tetromino *list_of_blocks);

void free_tetromino(struct tetromino *block);

#endif