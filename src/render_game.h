#ifndef RENDER_GAME_H
#define RENDER_GAME_H

#include <stdbool.h>

void render_game(int player_attempts, char *word_guess, char *alphabet, char *selected_letterPtr, char *alphabetto_check_selected_lettersPtr, char *render_guess_letsPtr, int *player_attemptsPtr, bool *is_space_pressed_or_notPtr);

#endif