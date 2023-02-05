#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdint.h>
#include "tetromino.h"

struct tetromino *new_tetromino_create(void)
{
    uint8_t index = get_random_number();
    
    struct tetromino *new_block = malloc(sizeof(struct tetromino));
    new_block->next = NULL;
    new_block->color_pair = default_tetrominos[index].color_pair;
    memcpy(new_block->block_position, default_tetrominos[index].block_position, 4*2*sizeof(int16_t));
    new_block->type_of_block = default_tetrominos[index].type_of_block;
    return new_block;
}

void tetromino_rotate(struct tetromino *block)
{
    if (check_wall_collision(block, 'r')) {
        return;
    }

    if (check_wall_collision(block, 'l')) {
        return;
    }
    
    struct tetromino *temp_block = malloc(sizeof(struct tetromino));

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
    free(temp_block);
    return;
}

void tetromino_move(struct tetromino *block, uint8_t direction)
{
    switch (direction) {
        case 65:
            for (uint8_t i = 0; i < 4; i++) {
                block->block_position[i][1] = block->block_position[i][1] - 1;   
            }
            y_offset--;
        break;

        case 66:
            for (uint8_t i = 0; i < 4; i++) {
                block->block_position[i][1] = block->block_position[i][1] + 1;
            }
            y_offset++;
            break;

        case 67:
            if (check_wall_collision(block, 'r')) {
                break;
            }
            else {
                for (uint8_t i = 0; i < 4; i++) {
                    block->block_position[i][0] = block->block_position[i][0] + 2;
                }
            }
            x_offset = x_offset + 2;
            break;

        case 68:
            if (check_wall_collision(block, 'l')) {
                break;
            }
            else {
                for (uint8_t i = 0; i < 4; i++) {
                    block->block_position[i][0] = block->block_position[i][0] - 2;
                }
            }
            
            x_offset = x_offset - 2;
            break;

        default:
            break;
    }
}

/*void tetromino_display(struct tetris_game *game)
{
    attron(COLOR_PAIR(block->color_pair));
    for (uint8_t i = 0; i < 4; ++i) {
            mvprintw(block->block_position[i][1], block->block_position[i][0], "[]");
    }
    attroff(COLOR_PAIR(block->color_pair));
}*/




void tetromino_free(struct tetromino *block)
{
    free(block);
    return;
}

uint8_t get_random_number(void)
{
    uint8_t random_number = rand();
    return random_number % 7;
}

void tetromino_drop(struct tetromino *block)
{
    
}

bool check_wall_collision(struct tetromino *block, char wall)
{
    switch (wall) {
        case 'l':
            for (int i = 0; i < 4; i++) {
                if (block->block_position[i][0] == 1) {
                    return true;
                }
            }
            return false;
        
        case 'r':
            for (int i = 0; i < 4; i++) {
                if (block->block_position[i][0] == 47) {
                return true;
            }
        }
            return false;

        default:
            return true;
    }
}

void print_block(struct tetromino *block)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", block->block_position[i][j]);
        }
        printf("\n");
    }
}