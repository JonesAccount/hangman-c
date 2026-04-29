// check_lifes.h
// Checks if player guess is correct and updates lives

#ifndef CHECK_LIFES_H
#define CHECK_LIFES_H

#include <stdbool.h>

// Checks player guess and updates game state
// is_space_pressed_or_notPtr - true if player pressed space
// word_guess                 - the secret word
// selected_letterPtr         - letter player chose
// render_guess_letsPtr       - what player sees on screen
// player_attemptsPtr         - how many lives player has left

void check_lifes_func(bool *is_space_pressed_or_notPtr, char *word_guess, char *selected_letterPtr, char *render_guess_letsPtr, int *player_attemptsPtr);

#endif