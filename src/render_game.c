// render_game.c
// Renders the game screen - hangman, word, alphabet, and intructions

#include <stdio.h>
#include <ctype.h>

#include "match_check.h"
#include "render_game.h"
#include "defs.h"

// Renders the full game screen
// player_attempts 		 			    - how many lives left
// word_guess 						    - the secret word
// alphabet     					    - keyboard layout for display
// selected_letterPtr 	                - letter player currently selected
// alphabetto_check_selected_lettersPtr - letters already used
// render_guess_letsPtr 		        - what player sees (letters and underscores)
// player_attemptsPtr 					- pointer to lives count
// is_space_pressed_or_notPtr			- true if player pressed space
void render_game(int player_attempts, char *word_guess, char *alphabet, char *selected_letterPtr, char *alphabetto_check_selected_lettersPtr, char *render_guess_letsPtr, int *player_attemptsPtr, bool *is_space_pressed_or_notPtr) {

	// hangman stages - index 0 is full figure, index 11 is empty gallows	
	const char hangman[12][100] = {
    	N T T "    ____" N T T "   |/   |" N T T "   |   (_) " N T T "   |   /|\\" N T T "   |    |" N T T "   |   | |" N T T "   |" N T T "   |____",
     	N T T "    ____" N T T "   |/   |" N T T "   |   (_) " N T T "   |   \\|/" N T T "   |    |" N T T "   |   / \\" N T T "   |" N T T "   |____",
      	N T T "    ____" N T T "   |/   |" N T T "   |   (_) " N T T "   |   \\|/" N T T "   |    |" N T T "   |   /" N T T "   |" N T T "   |____",
       	N T T "    ____" N T T "   |/   |" N T T "   |   (_) " N T T "   |   \\|/" N T T "   |    |" N T T "   |" N T T "   |" N T T "   |____",
        N T T "    ____" N T T "   |/   |" N T T "   |   (_) " N T T "   |   \\|" N T T "   |    |" N T T "   |" N T T "   |" N T T "   |____",
        N T T "    ____" N T T "   |/   |" N T T "   |   (_) " N T T "   |    |" N T T "   |    |" N T T "   |" N T T "   |" N T T "   |____",
        N T T "    ____" N T T "   |/   |" N T T "   |   (_) " N T T "   |" N T T "   |" N T T "   |" N T T "   |" N T T "   |____",
        N T T "    ____" N T T "   |/   |" N T T "   |   (" N T T "   |" N T T "   |" N T T "   |" N T T "   |" N T T "   |____",
        N T T "    ____" N T T "   |/   |" N T T "   |" N T T "   |" N T T "   |" N T T "   |" N T T "   |" N T T "   |____",
        N T T "    _" N T T "   |/" N T T "   |" N T T "   |" N T T "   |" N T T "   |" N T T "   |" N T T "   |____",
        N N N N N T T "   |" N T T "   |" N T T "   |" N T T "   |____",
        N N N N N N N N T T "   |____"
	};
	
	// print hangman for current attempts
    printf("%s", hangman[player_attempts]);

    // print word with guessed letters and underscores
    match_check(word_guess, selected_letterPtr, render_guess_letsPtr, player_attemptsPtr, is_space_pressed_or_notPtr);
    
    // print alphabet - yellow if selected, gray if already used
    for (int i = 0; i < 26; i++) {
        if (!i) { printf(N N T "     "); } // indent before first letter

        const char letter = *(alphabet + i);

        // check if letter was already used
        bool check_selected = false;
        for (int j = 0; j < 26; j++) {
        	if (*(alphabetto_check_selected_lettersPtr + j) == letter) { check_selected = true; }
        }
        
        // yellow if currently selected, gray if already used
        if (*selected_letterPtr == letter) {
        	printf("\033[33m");
        } else if (check_selected) {
        	printf("\033[90m"); 
        }

        printf("%c " RESET, letter);

        // line breaks to show alphabet in keyboard layout
        if (letter == 'P') { printf(N T "      "); }
        if (letter == 'L') { printf(N T "        "); }
        if (i == 90) { printf("\n"); }
    }

    // print dividing line
    for (int i = 0; i < 19; i++) {
        if (!i) { printf("\n\n     "); }
        printf("- ");
    }

    // print intructions at bottom
    printf("\n\n\t  [esc] menu  [space] confirm");
}
