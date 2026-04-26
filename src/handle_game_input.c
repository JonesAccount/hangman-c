#include <ctype.h>

#include "handle_game_input.h"
#include "utils.h"

void handle_game_input(char *selected_letterPtr, char *alphabetto_check_selected_lettersPtr, bool *is_space_pressed_or_notPtr) {
	char ch = tolower(read_char());

    // check for the letter pressed or not
    bool check_selected = false;
    static int index_selected_letters = 0;

    if (isalpha(ch)) {
   		for (int i = 0; i < 26; i++) {
       		if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == ch) { check_selected = true; }
       	}
       	if (!check_selected) { *selected_letterPtr = toupper(ch); }
    }

    if (ch == ' ') {
    	//check_selected = false;
    	*is_space_pressed_or_notPtr = true;
        if (isalpha(*selected_letterPtr)) {
            for (int i = 0; i < 26; i++) {
                if (*(alphabetto_check_selected_lettersPtr + i) == *selected_letterPtr) { check_selected = true; }
            }
            if (!check_selected) {
                alphabetto_check_selected_lettersPtr[index_selected_letters] = *selected_letterPtr;
                index_selected_letters++;
            }
        }
    }

}
