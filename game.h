#ifndef GAME_H
#define GAME_H
#include "tetromino.h"

#define GAME_WINDOW_HEIGHT 50
#define GAME_WINDOW_WIDTH 50
#define GAME_WINDOW_START_X 70
#define GAME_WINDOW_START_Y 5

#define SCORE_WINDOW_HEIGHT 15
#define SCORE_WINDOW_WIDTH 30
#define SCORE_WINDOW_START_X 120
#define SCORE_WINDOW_START_Y 1

#define CURRENT_LEVEL_WINDOW_HEIGHT 5
#define CURRENT_LEVEL_WINDOW_WIDTH 30
#define CURRENT_LEVEL_WINDOW_START_X 120
#define CURRENT_LEVEL_WINDOW_START_Y 29

#define NEXT_BLOCK_WINDOW_HEIGHT 13
#define NEXT_BLOCK_WINDOW_WIDTH 30
#define NEXT_BLOCK_WINDOW_START_X 120
#define NEXT_BLOCK_WINDOW_START_Y 16

#define LINES_CLEARED_WINDOW_HEIGHT 4
#define LINES_CLEARED_WINDOW_WIDTH 50
#define LINES_CLEARED_WINDOW_START_X 70
#define LINES_CLEARED_WINDOW_START_Y 1

#define STATISTICS_WINDOW_WIDTH 30
#define STATISTICS_WINDOW_HEIGHT 43
#define STATISTICS_WINDOW_START_X 40
#define STATISTICS_WINDOW_START_Y 12

struct tetris_game {
    WINDOW *game_window;
    WINDOW *score_window; 
    WINDOW *current_level_window;
    WINDOW *next_block_window;
    WINDOW *lines_cleared_window;
    WINDOW *statistics_window;
    struct tetromino *current_block;
    struct tetromino *next_block;
    int block_statistics[7];
    int lines_cleared;
    int current_level;
    int current_score;
    int top_score;
};

void game_window_display(struct tetris_game *game);

void score_window_display(struct tetris_game *game);

void current_level_window_display(struct tetris_game *game);

void next_block_window_display(struct tetris_game *game);

void lines_cleared_window_display(struct tetris_game *game);

void statistics_window_display(struct tetris_game *game);

void colors_init(void);

struct tetris_game *game_init(void);

void main_game_loop(struct tetris_game *game);

WINDOW *create_new_window(int height, int width, int start_y, int start_x);


#endif