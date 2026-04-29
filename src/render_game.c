// render_game.c

#include <stdio.h>
#include <ctype.h>

//----------------------------------------------------------------------
#include "match_check.h"
#include "render_game.h"
#include "defs.h"

//----------------------------------------------------------------------
void render_game(int player_attempts, char *word_guess, char *alphabet, char *selected_letterPtr, char *alphabetto_check_selected_lettersPtr, char *render_guess_letsPtr, int *player_attemptsPtr, bool *is_space_pressed_or_notPtr) {
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

    printf("%s", hangman[player_attempts]);

    // place for a word
    match_check(word_guess, selected_letterPtr, render_guess_letsPtr, player_attemptsPtr, is_space_pressed_or_notPtr);
    
    //----------------------------------------------------------------------
    // render english alphabet
    for (int i = 0; i < 26; i++) {
        if (!i) { printf(N N T "     "); }

        const char letter = *(alphabet + i);

        // для проверки буква уже выбрана или нет
        bool check_selected = false;

        for (int j = 0; j < 26; j++) {
        	if (*(alphabetto_check_selected_lettersPtr + j) == letter) { check_selected = true; }
        }

        if (*selected_letterPtr == letter) {
        	printf("\033[33m");
        } else if (check_selected) {
        	printf("\033[90m"); 
        }

        printf("%c " RESET, letter);

        if (letter == 'P') { printf(N T "      "); }
        if (letter == 'L') { printf(N T "        "); }
        if (i == 90) { printf("\n"); }
    }

    //----------------------------------------------------------------------
    // dividing line
    for (int i = 0; i < 19; i++) {
        if (!i) { printf("\n\n     "); }
        printf("- ");
    }

    //----------------------------------------------------------------------
    // instructions
    printf("\n\n\t  [esc] menu  [space] confirm");

}
