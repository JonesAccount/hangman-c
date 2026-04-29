// match_check.c
// Renders the word display with guessed letters and underscores

#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "match_check.h"
#include "defs.h"

// Prints the current state of the word on screen
// word_guess 				  - the secret word
// selected_letterPtr 	      - letter player currently selected
// render_guess_letsPtr 	  - what player sees (letters and underscores)
// player_attemptsPtr 		  - how many lives left
// is_space_pressed_or_notPtr - true if player pressed space
void match_check(char *word_guess, char *selected_letterPtr, char *render_guess_letsPtr, int *player_attemptsPtr, bool *is_space_pressed_or_notPtr) {
    int word_length = strlen(word_guess);
    int indent = 7 - word_length; // shorter word = more indent = word stays centered
    
    printf(N N N T T); // move to new line and add tab
    
    // print spaces to center the word
    for (int i = 0; i < indent; i++) {
    	printf(" ");
    }
    
    // print each letter or underscores
    for (int i = 0; i < word_length; i++) {
         printf("%c ", *(render_guess_letsPtr + i));
     }
}
