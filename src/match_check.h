// match_check.h
// Functions for rendering the word display

#ifndef MATCH_CHECK_H
#define MATCH_CHECK_H

#include <stdbool.h>

// Prints the current state of the word on screen
// word_guess 				  - the secret word
// selected_letterPtr 	      - letter player currently selected
// render_guess_letsPtr 	  - what player sees (letters and underscores)
// player_attemptsPtr 		  - how many lives left
// is_space_pressed_or_notPtr - true if player pressed space
void match_check(char *word_guess, char *selected_letterPtr, char *render_guess_letsPtr, int *player_attemptsPtr, bool *is_space_pressed_or_notPtr);

#endif