#include "tetromino.h"


void create_tetrominos(void)
{
    tetrominos[0].color_pair = I_BLOCK_COLOR;
    tetrominos[1].color_pair = O_BLOCK_COLOR;
    tetrominos[2].color_pair = T_BLOCK_COLOR;
    tetrominos[3].color_pair = S_BLOCK_COLOR;
    tetrominos[4].color_pair = Z_BLOCK_COLOR;
    tetrominos[5].color_pair = J_BLOCK_COLOR;
    tetrominos[6].color_pair = L_BLOCK_COLOR;
    memcpy(tetrominos[0].block_position, I_BLOCK_COORDINATES, 4*2*sizeof(int));
    memcpy(tetrominos[1].block_position, O_BLOCK_COORDINATES, 4*2*sizeof(int));
    memcpy(tetrominos[2].block_position, T_BLOCK_COORDINATES, 4*2*sizeof(int));
    memcpy(tetrominos[3].block_position, S_BLOCK_COORDINATES, 4*2*sizeof(int));
    memcpy(tetrominos[4].block_position, Z_BLOCK_COORDINATES, 4*2*sizeof(int));
    memcpy(tetrominos[5].block_position, J_BLOCK_COORDINATES, 4*2*sizeof(int));
    memcpy(tetrominos[6].block_position, L_BLOCK_COORDINATES, 4*2*sizeof(int));
}

void rotate_tetromino(struct tetromino *block, char direction)
{

    return;
}

void move_tetromino(struct tetromino *block, char direction)
{
    return;
}

void display_tetromino(struct tetromino block)
{
    attron(COLOR_PAIR(block.color_pair));
    for (int i = 0; i < 4; ++i) {
            mvaddstr(block.block_position[i][0], block.block_position[i][1], "[]");
    }
    attroff(COLOR_PAIR(block.color_pair));
}

void display_all_tetrominos(struct tetromino *list_of_blocks) {
    for (int i = 0; i < 6; ++i) {
        display_tetromino(list_of_blocks[i]);
    }
}

void free_tetromino(struct tetromino *block) {
    return;
}
