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
    float block_position[4][2];
    char type_of_block;
};

static float x_offset = 100;
static float y_offset = 6;

static float I_BLOCK_COORDINATES[4][2] = {{100, 4}, 
                                        {100, 5}, 
                                        {100, 6}, 
                                        {100, 7}
                                        };

static float O_BLOCK_COORDINATES[4][2] = {{100, 5}, 
                                        {102, 5}, 
                                        {100, 6}, 
                                        {102, 6}
                                        };

static float T_BLOCK_COORDINATES[4][2] = {{98, 6}, 
                                        {102, 6}, 
                                        {100, 6}, 
                                        {100, 7}
                                        };

static float S_BLOCK_COORDINATES[4][2] = {{102, 5}, 
                                        {100, 5},
                                        {100, 6}, 
                                        {98, 6}
                                        };

static float Z_BLOCK_COORDINATES[4][2] = {{98, 5}, 
                                        {100, 5}, 
                                        {100, 6}, 
                                        {102, 6}
                                        };

static float J_BLOCK_COORDINATES[4][2] = {{100, 4}, 
                                        {100, 5}, 
                                        {100, 6}, 
                                        {98, 6}
                                        };

static float L_BLOCK_COORDINATES[4][2] = {{100, 4}, 
                                        {100, 5}, 
                                        {100, 6}, 
                                        {102, 6}
                                        };


static char types_of_blocks[7] = {'I', 'O', 'T', 'S', 'Z', 'J', 'L'};


struct tetromino tetrominos[7];

void default_tetrominos_create(void);

void tetromino_initialize(int color, float coordinates[4][2]);

struct tetromino* new_tetromino_create(void);

void tetromino_rotate(struct tetromino *block);

void tetromino_move(struct tetromino *block, int direction);

void tetromino_display(struct tetromino *block);

/*void display_all_tetrominos(struct tetromino *list_of_blocks);*/

void tetromino_free(struct tetromino *block);

int get_random_number(void);

void print_tetromino(struct tetromino *block);

#endif