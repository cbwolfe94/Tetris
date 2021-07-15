#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include "tetromino.h"


void default_tetrominos_create(void)
{
    tetromino_initialize(I_BLOCK, I_BLOCK_COORDINATES);
    tetromino_initialize(O_BLOCK, O_BLOCK_COORDINATES);
    tetromino_initialize(T_BLOCK, T_BLOCK_COORDINATES);
    tetromino_initialize(S_BLOCK, S_BLOCK_COORDINATES);
    tetromino_initialize(Z_BLOCK, Z_BLOCK_COORDINATES);
    tetromino_initialize(J_BLOCK, J_BLOCK_COORDINATES);
    tetromino_initialize(L_BLOCK, L_BLOCK_COORDINATES);
}

struct tetromino* new_tetromino_create(void)
{
    struct tetromino *new_block = malloc(sizeof(struct tetromino));
    new_block->color_pair = tetrominos[get_random_number()].color_pair;
    memcpy(new_block->block_position, tetrominos[get_random_number()].block_position, 4*2*sizeof(int));
    return new_block;
}

void tetromino_initialize(int color, int coordinates[4][2])
{
    
    tetrominos[color - 1].color_pair = color;
    memcpy(tetrominos[color - 1].block_position, coordinates, 4*2*sizeof(int));
}

void tetromino_rotate(struct tetromino *block)
{
    
    return;
}

void tetromino_move(struct tetromino *block, int direction)
{
    //char direction = direction;
    switch (direction) {
        case 65:
            for (int i = 0; i < 4; i++) {
                block->block_position[i][0] = block->block_position[i][0] - 1;
            }
        break;

        case 66:
            for (int i = 0; i < 4; i++) {
                block->block_position[i][0] = block->block_position[i][0] + 1;
            }
            break;

        case 67:
            for (int i = 0; i < 4; i++) {
                block->block_position[i][1] = block->block_position[i][1] + 1;
            }
            break;

        case 68:
            for (int i = 0; i < 4; i++) {
                block->block_position[i][1] = block->block_position[i][1] - 1;
            }
            break;

        default:
            break;
    }
}

void tetromino_display(struct tetromino *block)
{
    attron(COLOR_PAIR(block->color_pair));
    for (int i = 0; i < 4; ++i) {
            mvprintw(block->block_position[i][0], block->block_position[i][1], "[]");
    }
    attroff(COLOR_PAIR(block->color_pair));
}

/*
void display_all_tetrominos(struct tetromino *list_of_blocks)
{
    for (int i = 0; i < 7; ++i) {
        tetromino_display(list_of_blocks[i]);
    }
}*/

void tetromino_free(struct tetromino *block)
{
    return;
}

int get_random_number(void)
{
    srand(time(NULL));
    return rand() & 6;
}