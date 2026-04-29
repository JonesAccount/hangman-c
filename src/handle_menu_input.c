// handle_menu_input.c
// Handles keyboard input in the main menu

#include <stdbool.h>
#include <ctype.h>

#include "handle_menu_input.h"
#include "utils.h"

// Reads keyboard input and updates game state
// running_menu - true if menu is running
// running_game - set to true if player starts game
// selectedPtr  - true if "Start" selected, false if "Quit" selected 
void handle_menu_input(bool *running_menu, bool *running_game, bool *selectedPtr) {
    char ch = tolower(read_char());
    
    switch (ch) {
        case 'w': *selectedPtr = true; break; 			// select "Start"
        case 's': *selectedPtr = false; break; 			// select "Quit"
        case ' ':
            *running_menu = false;                      // close menu
            if (*selectedPtr) { *running_game = true; } // start game if "Start" selected
    }
    
}