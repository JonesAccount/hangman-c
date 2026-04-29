// render_game.h
// Functions for rendering the game screen

#ifndef RENDER_GAME_H
#define RENDER_GAME_H

#include <stdbool.h>

// Renders the full game screen - hangman, word, alphabet, instructions
// player_attempts 		 			    - how many lives left
// word_guess 						    - the secret word
// alphabet     					    - keyboard layout for display
// selected_letterPtr 	                - letter player currently selected
// alphabetto_check_selected_lettersPtr - letters already used
// render_guess_letsPtr 		        - what player sees (letters and underscores)
// player_attemptsPtr 					- pointer to lives count
// is_space_pressed_or_notPtr			- true if player pressed space
void render_game(int player_attempts, char *word_guess, char *alphabet, char *selected_letterPtr, char *alphabetto_check_selected_lettersPtr, char *render_guess_letsPtr, int *player_attemptsPtr, bool *is_space_pressed_or_notPtr);

#endif