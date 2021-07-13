#ifndef TETROMINO_H
#define TETROMINO_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

enum Colors {
    I_BLOCK = COLOR_RED,
    O_BLOCK = COLOR_GREEN,
    T_BLOCK = COLOR_YELLOW,
    S_BLOCK = COLOR_BLUE,
    Z_BLOCK = COLOR_MAGENTA,
    J_BLOCK = COLOR_CYAN,
    L_BLOCK = COLOR_WHITE
};

struct tetromino {
    int color_pair;
    int block_position[4][2];
};

static int I_BLOCK_COORDINATES[4][2] = {{4, 35}, {5, 35}, {6, 35}, {7, 35}};

static int O_BLOCK_COORDINATES[4][2] = {{9, 35}, {9, 37}, {10, 35}, {10, 37}};

static int T_BLOCK_COORDINATES[4][2] = {{12, 33}, {12, 35}, {12, 37}, {13, 35}};

static int S_BLOCK_COORDINATES[4][2] = {{15, 37}, {15, 35}, {16, 35}, {16, 33}};

static int Z_BLOCK_COORDINATES[4][2] = {{18, 33}, {18, 35}, {19, 35}, {19, 37}};

static int J_BLOCK_COORDINATES[4][2] = {{21, 35}, {22, 35}, {23, 35}, {23, 33}};

static int L_BLOCK_COORDINATES[4][2] = {{25, 35}, {26, 35}, {27, 35}, {27, 37}};



struct tetromino tetrominos[7];

void default_tetrominos_create(void);

void tetromino_initialize(int color, int coordinates[4][2]);

void new_tetromino_create(void);

void tetromino_rotate(struct tetromino *block, char direction);

void tetromino_move(struct tetromino *block, char direction);

void tetromino_display(struct tetromino block);

void display_all_tetrominos(struct tetromino *list_of_blocks);

void tetromino_free(struct tetromino *block);

int get_random_number(void);

#endif