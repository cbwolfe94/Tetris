#ifndef TETROMINO_H
#define TETROMINO_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#define DEFAULT_X  100
#define DEFAULT_Y  6

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
    struct tetromino *next;
    int color_pair;
    int16_t block_position[4][2];
    char type_of_block;
};

struct tetrominos_in_play {
    struct tetromino *head_tetromino;
};

static int x_offset = 100;
static int y_offset = 6;

static struct tetromino default_tetrominos[7] = {
    [0] = {.next = NULL, .color_pair = I_BLOCK, .block_position = {{DEFAULT_X, DEFAULT_Y - 2}, {DEFAULT_X, DEFAULT_Y - 1}, {DEFAULT_X, DEFAULT_Y}, {DEFAULT_X, DEFAULT_Y + 1}}, .type_of_block = 'I'},
    [1] = {.next = NULL, .color_pair = O_BLOCK, .block_position = {{DEFAULT_X, DEFAULT_Y - 1}, {DEFAULT_X + 2, DEFAULT_Y - 1}, {DEFAULT_X, DEFAULT_Y}, {DEFAULT_X + 2, DEFAULT_Y}}, .type_of_block = 'O'},
    [2] = {.next = NULL, .color_pair = T_BLOCK, .block_position = {{DEFAULT_X - 2, DEFAULT_Y}, {DEFAULT_X + 2, DEFAULT_Y}, {DEFAULT_X, DEFAULT_Y}, {DEFAULT_X, DEFAULT_Y + 1}}, .type_of_block = 'T'},
    [3] = {.next = NULL, .color_pair = S_BLOCK, .block_position = {{DEFAULT_X + 2, DEFAULT_Y - 1}, {DEFAULT_X, DEFAULT_Y - 1}, {DEFAULT_X, DEFAULT_Y}, {DEFAULT_X - 2, DEFAULT_Y}}, .type_of_block = 'S'},
    [4] = {.next = NULL, .color_pair = Z_BLOCK, .block_position = {{DEFAULT_X - 2, DEFAULT_Y - 1}, {DEFAULT_X, DEFAULT_Y - 1}, {DEFAULT_X, DEFAULT_Y}, {DEFAULT_X + 2, DEFAULT_Y}}, .type_of_block = 'Z'},
    [5] = {.next = NULL, .color_pair = J_BLOCK, .block_position = {{DEFAULT_X, DEFAULT_Y - 2}, {DEFAULT_X, DEFAULT_Y - 1}, {DEFAULT_X, DEFAULT_Y}, {DEFAULT_X - 2, DEFAULT_Y}}, .type_of_block = 'J'},
    [6] = {.next = NULL, .color_pair = L_BLOCK, .block_position = {{DEFAULT_X, DEFAULT_Y - 2}, {DEFAULT_X, DEFAULT_Y - 1}, {DEFAULT_X, DEFAULT_Y}, {DEFAULT_X + 2, DEFAULT_Y}}, .type_of_block = 'L'},
};

struct tetromino* new_tetromino_create(void);

void tetromino_rotate(struct tetromino *block);

void tetromino_move(struct tetromino *block, uint8_t direction);

void tetromino_display(struct tetromino *block);

void tetromino_free(struct tetromino *block);

uint8_t get_random_number(void);

void tetromino_drop(struct tetromino *block);

#endif