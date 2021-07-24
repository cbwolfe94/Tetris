#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdint.h>
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
    int index = get_random_number();
    struct tetromino *new_block = malloc(sizeof(struct tetromino));
    new_block->color_pair = tetrominos[index].color_pair;
    memcpy(new_block->block_position, tetrominos[index].block_position, 4*2*sizeof(float));
    new_block->type_of_block = types_of_blocks[index];
    return new_block;
}

void tetromino_initialize(int color, float coordinates[4][2])
{
    tetrominos[color - 1].color_pair = color;
    memcpy(tetrominos[color - 1].block_position, coordinates, 4*2*sizeof(float));
    tetrominos[color - 1].type_of_block = types_of_blocks[color - 1];
}

void tetromino_rotate(struct tetromino *block)
{
    struct tetromino *temp_block = malloc(sizeof(struct tetromino));

    if (block->type_of_block == 'O') {
        return;
    }

    for (int i = 0; i < 4; i++) {
        temp_block->block_position[i][0] = (block->block_position[i][0] - x_offset)*0 + (block->block_position[i][1] - y_offset)*(-2);
        temp_block->block_position[i][1] = (block->block_position[i][0] - x_offset)*(0.5) + (block->block_position[i][1] - y_offset)*(0);
        block->block_position[i][0] = temp_block->block_position[i][0] + x_offset;
        block->block_position[i][1] = temp_block->block_position[i][1] + y_offset;
    }

    free(temp_block);
    return;
}

void tetromino_move(struct tetromino *block, int direction)
{
    //char direction = direction;
    switch (direction) {
        case 65:
            for (int i = 0; i < 4; i++) {
                block->block_position[i][1] = block->block_position[i][1] - 1;   
            }
            y_offset--;
        break;

        case 66:
            for (int i = 0; i < 4; i++) {
                block->block_position[i][1] = block->block_position[i][1] + 1;
            }
            y_offset++;
            break;

        case 67:
            for (int i = 0; i < 4; i++) {
                
                block->block_position[i][0] = block->block_position[i][0] + 2;
            } 
            x_offset = x_offset + 2;
            break;

        case 68:
            for (int i = 0; i < 4; i++) {
                block->block_position[i][0] = block->block_position[i][0] - 2;
                
            } 
            x_offset = x_offset - 2;
            break;

        default:
            break;
    }
}

void tetromino_display(struct tetromino *block)
{
    attron(COLOR_PAIR(block->color_pair));
    for (int i = 0; i < 4; ++i) {
            mvprintw(block->block_position[i][1], block->block_position[i][0], "[]");
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
    int random_number = rand();
    return random_number % 7;
}

void print_tetromino(struct tetromino *block) {

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++) {
            printf("%f ", block->block_position[i][j]);
        }
        printf("\n");
    }
}