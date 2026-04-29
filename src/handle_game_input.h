// handle_game_input.h
// Functions for handling keyboard input during the game

#ifndef HANDLE_GAME_INPUT_H
#define HANDLE_GAME_INPUT_H

#include <stdbool.h>

// If player presses ESC - exit game and go to menu
// ch                                   - pressed key
// running_game                         - set to false is ESC pressed
// running_menu                         - set to true if ESC pressed
void pressed_esc(char ch, bool *running_game, bool *running_menu);


// Reads keyboard input and updates game state
// selected_letterPtr                   - letter player currently selected
// alphabetto_check_selected_lettersPtr - letters already used
// is_space_pressed_or_notPtr           - true if player pressed space
// index_selected_letters               - how many letters used so far
// running_game                         - true if game is running
// running_menu							- true if menu is running
void handle_game_input(char *selected_letterPtr, char *alphabetto_check_selected_lettersPtr, bool *is_space_pressed_or_notPtr, int *index_selected_letters, bool *running_game, bool *running_menu);

#endif