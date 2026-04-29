// handle_menu_input.h
// Functions for handling keyboard input in the main menu

#ifndef HANDLE_MENU_INPUT_H
#define HANDLE_MENU_INPUT_H

#include <stdbool.h>

// Reads keyboard input and updates game state
// running_menu - true if menu is running
// running_game - set to true if player starts game
// selectedPtr  - true if "Start" selected, false if "Quit" selected 
void handle_menu_input(bool *running_menu, bool *running_game, bool *selectedPtr);

#endif