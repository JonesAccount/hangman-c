// check_lifes.c

#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// This function checks if player guess is correct or wrong
// and updates lives if player made mistake
void check_lifes_func(
	bool *is_space_pressed_or_notPtr, // true if player pressed space
	char *word_guess,                 // the secret word
	char *selected_letterPtr,         // letter player chose
	char *render_guess_letsPtr,       // what player sees on screen
	int *player_attemptsPtr           // how many lives player has left
) {
	int word_length = strlen(word_guess); // get length of secret word
	
	// only run if player pressed space
	if (*is_space_pressed_or_notPtr) {
		*is_space_pressed_or_notPtr = false; // reset space press
		
		// check every letter in word
		// if letter matches - show it to player
    	for (int i = 0; i < word_length; i++) {
        	if (*(word_guess + i) == tolower(*selected_letterPtr)) {
            	*(render_guess_letsPtr + i) = *selected_letterPtr;
         	}
     	}
     
     	// count how many letters do NOT match
       	int is_the_choice_mistake = 0;
        for (int i = 0; i < word_length; i++) {
         	if (*(word_guess + i) != tolower(*selected_letterPtr)) {
             	is_the_choice_mistake++;
         	}
        }
        
        // if no letter matched - player made mistake
        // remove one life and reset selected letter
        if (is_the_choice_mistake == word_length && isalpha(*selected_letterPtr)) {
        	(*player_attemptsPtr)--;
         	*selected_letterPtr = '0';
        }
	}
}
