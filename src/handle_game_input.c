// handle_game_input.c
// Handles keyboard input during the game

#include <stdbool.h>
#include <ctype.h>

#include "handle_game_input.h"
#include "utils.h"

// If player presses ESC - exit game and go to menu
void pressed_esc(char ch, bool *running_game, bool *running_menu) {
	if (ch == 27) {
		*running_game = false;
		*running_menu = true;
	}
}

// Reads keyboard input and updates game state
// selected_letterPtr                   - letter player currently selected
// alphabetto_check_selected_lettersPtr - letters already used
// is_space_pressed_or_notPtr           - true if player pressed space
// index_selected_letters               - how many letters used so far
// running_game                         - true if game is running
// running_menu							- true if menu is running
void handle_game_input(char *selected_letterPtr, char *alphabetto_check_selected_lettersPtr, bool *is_space_pressed_or_notPtr, int *index_selected_letters, bool *running_game, bool *running_menu) {
	char ch = tolower(read_char());

    bool check_selected = false; // true if letter was already used
 
    // if player pressed a letter - select it if not used before
    if (isalpha(ch)) {
   		for (int i = 0; i < 26; i++) {
       		if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == ch) { check_selected = true; }
       	}
       	if (!check_selected) { *selected_letterPtr = toupper(ch); }
    }

    // if player pressed space - confirm selected letter
    if (ch == ' ') {
    	*is_space_pressed_or_notPtr = true;
     
     	// add letter to used letters if not already there
        if (isalpha(*selected_letterPtr)) {
            for (int i = 0; i < 26; i++) {
                if (*(alphabetto_check_selected_lettersPtr + i) == *selected_letterPtr) { check_selected = true; }
            }
            if (!check_selected) {
                alphabetto_check_selected_lettersPtr[*index_selected_letters] = *selected_letterPtr;
                (*index_selected_letters)++;
            }
        }
    }

    // check if player pressed ESC
    pressed_esc(ch, running_game, running_menu);

}
