#define _POSIX_C_SOURCE 199309L
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "game.h"
#include "tetromino.h"

void sleep_milli(int milliseconds)
{
  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = milliseconds * 1000 * 1000;
  nanosleep(&ts, NULL);
}

struct tetris_game *game_init(void)
{
    struct tetris_game *new_game = malloc(sizeof(struct tetris_game));
    new_game->game_window = create_new_window(GAME_WINDOW_HEIGHT, GAME_WINDOW_WIDTH, GAME_WINDOW_START_Y, GAME_WINDOW_START_X);
    new_game->score_window = create_new_window(SCORE_WINDOW_HEIGHT, SCORE_WINDOW_WIDTH, SCORE_WINDOW_START_Y, SCORE_WINDOW_START_X);
    new_game->current_level_window = create_new_window(CURRENT_LEVEL_WINDOW_HEIGHT, CURRENT_LEVEL_WINDOW_WIDTH, CURRENT_LEVEL_WINDOW_START_Y, CURRENT_LEVEL_WINDOW_START_X);
    new_game->next_block_window = create_new_window(NEXT_BLOCK_WINDOW_HEIGHT, NEXT_BLOCK_WINDOW_WIDTH, NEXT_BLOCK_WINDOW_START_Y, NEXT_BLOCK_WINDOW_START_X);
    new_game->lines_cleared_window = create_new_window(LINES_CLEARED_WINDOW_HEIGHT, LINES_CLEARED_WINDOW_WIDTH, LINES_CLEARED_WINDOW_START_Y, LINES_CLEARED_WINDOW_START_X);
    new_game->statistics_window = create_new_window(STATISTICS_WINDOW_HEIGHT, STATISTICS_WINDOW_WIDTH, STATISTICS_WINDOW_START_Y, STATISTICS_WINDOW_START_X);

    for (int i = 0; i < 7; i++) {
        new_game->block_statistics[i] = 0;
    }

    new_game->lines_cleared = 0;
    new_game->current_level = 0;
    new_game->top_score = 0;
    new_game->current_score = 0;
    new_game->gravity = GRAVITY_LEVEL[0];

    return new_game;
}

void colors_init(void)
{
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
    init_pair(7, COLOR_WHITE, COLOR_WHITE);
}

WINDOW *create_new_window(int height, int width, int start_y, int start_x)
{	
    WINDOW *new_window = newwin(height, width, start_y, start_x);
    box(new_window, 0, 0);
	wrefresh(new_window);
	return new_window;
}

void game_window_display(struct tetris_game *game)
{
    struct tetromino *block = game->current_block;
    box(game->game_window, 0, 0);
    for (int i = 0; i < 4; ++i) {
            wmove(game->game_window, block->block_position[i][1], block->block_position[i][0]);
            waddch(game->game_window, '['|COLOR_PAIR(block->color_pair));
            wmove(game->game_window, block->block_position[i][1], block->block_position[i][0] + 1);
            waddch(game->game_window, ']'|COLOR_PAIR(block->color_pair));
    }
    wnoutrefresh(game->game_window);

}

void score_window_display(struct tetris_game *game)
{
    char top_score[7];
    char current_score[7];

    sprintf(top_score, "%0*d", 6, game->top_score);
    sprintf(current_score, "%0*d", 6, game->current_score);

    box(game->score_window, 0, 0);
    wmove(game->score_window, 2, 10);
    waddstr(game->score_window, "TOP SCORE");
    wmove(game->score_window, 4, 12);
    waddstr(game->score_window, top_score);
    wmove(game->score_window, 8, 8);
    waddstr(game->score_window, "CURRENT SCORE");
    wmove(game->score_window, 10, 12);
    waddstr(game->score_window, current_score);
    wnoutrefresh(game->score_window);
}

void current_level_window_display(struct tetris_game *game)
{
    char current_level[3];
    sprintf(current_level, "%0*d", 2, game->current_level);

    box(game->current_level_window, 0, 0);
    wmove(game->current_level_window, 2, 10);
    waddstr(game->current_level_window, "LEVEL");
    wmove(game->current_level_window, 2, 17);
    waddstr(game->current_level_window, current_level);
    wnoutrefresh(game->current_level_window);

}

void next_block_window_display(struct tetris_game *game)
{
    struct tetromino *block = game->next_block;
    box(game->next_block_window, 0, 0);
    wmove(game->next_block_window, 2, 10);
    waddstr(game->next_block_window, "NEXT BLOCK");

    for (int i = 0; i < 4; ++i) {
            wmove(game->next_block_window, block->block_position[i][1] + 1, block->block_position[i][0] - 11);
            waddch(game->next_block_window, '['|COLOR_PAIR(block->color_pair));
            wmove(game->next_block_window, block->block_position[i][1] + 1, block->block_position[i][0] - 10);
            waddch(game->next_block_window, ']'|COLOR_PAIR(block->color_pair));
    }

    wnoutrefresh(game->next_block_window);
}

void lines_cleared_window_display(struct tetris_game *game)
{
    char lines_cleared[4];
    sprintf(lines_cleared, "%0*d", 3, game->lines_cleared);

    box(game->lines_cleared_window, 0, 0);
    wmove(game->lines_cleared_window, 1, 12);
    waddstr(game->lines_cleared_window, "LINES CLEARED");
    wmove(game->lines_cleared_window, 1, 32);
    waddstr(game->lines_cleared_window, lines_cleared);
    wnoutrefresh(game->lines_cleared_window);
}

void statistics_window_display(struct tetris_game *game)
{
    char statistics[4];

    box(game->statistics_window, 0, 0);
    wmove(game->statistics_window, 1, 10);
    waddstr(game->statistics_window, "STATISTICS");

    wmove(game->statistics_window, 0, 10);


    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            wmove(game->statistics_window, default_tetrominos[i].block_position[j][1] + (5 * i), default_tetrominos[i].block_position[j][0] - 20);
            waddch(game->statistics_window, '['|COLOR_PAIR(default_tetrominos[i].color_pair));
            wmove(game->statistics_window, default_tetrominos[i].block_position[j][1] + (5 * i), default_tetrominos[i].block_position[j][0] - 19);
            waddch(game->statistics_window, ']'|COLOR_PAIR(default_tetrominos[i].color_pair));
        }
        wmove(game->statistics_window, (5 * (i + 1) + 1), 20);
        sprintf(statistics, "%0*d", 3, game->block_statistics[i]);
        waddstr(game->statistics_window, statistics);
    }



    wnoutrefresh(game->statistics_window);
}

void main_game_loop(struct tetris_game *game)
{
    int ch;
    int current_tick;
    double time_elapsed;
    game->current_block = new_tetromino_create();
    game->next_block = new_tetromino_create();

    //game->game_window = create_new_window(50, 50, 2, 70); 
    nodelay(game->game_window, true);
    notimeout(game->game_window, TRUE);

    while(true) {
        current_tick = get_gravity_tick(game);
        if (current_tick == 0) {
            tetromino_move(game->current_block, 66);
        }
        //gravity_tick(game);
        game_window_display(game);
        score_window_display(game);
        current_level_window_display(game);
        lines_cleared_window_display(game);
        next_block_window_display(game);
        statistics_window_display(game);
        doupdate();
        sleep_milli(10);
        ch = wgetch(game->game_window);
        if (ch == 32) {
            tetromino_rotate(game->current_block);

        }
        else {
            tetromino_move(game->current_block, ch);
        }
        werase(game->game_window);

    }
    endwin();
}

int get_gravity_tick(struct tetris_game *game) {
    int gravity;
    gravity = game->gravity;
    if (gravity == 0) {
        game->gravity = GRAVITY_LEVEL[game->current_level];
        return 0;
    }
    else {
        game->gravity -= 1;
        return gravity;
    }
}