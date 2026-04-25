#include <stdio.h>
#include <ctype.h>

#include "match_check.h"
#include "render_game.h"
#include "defs.h"

void render_game(int player_attempts, char *word_guess, char *alphabet, char *selected_letterPtr, char *alphabetto_check_selected_lettersPtr, char *render_guess_letsPtr, int *player_attemptsPtr, bool *is_space_pressed_or_notPtr) {
    const char HANGMAN[11][80] = {
    	"|" N "|" N "|" N "|___                                                         ",
     	" __" N "|/" N "|" N "|" N "|" N "|" N "|" N "|___                              ",
      	" __" N "|/   |" N "|" N "|" N "|" N "|" N "|" N "|___                          ",
        " __" N "|/   |" N "|   (" N "|" N "|" N "|" N "|" N "|___                      ",
        " __" N "|/   |" N "|   (_) " N "|" N "|" N "|" N "|" N "|___                   ",
        " __" N "|/   |" N "|   (_) " N "|    |" N "|    |" N "|" N "|" N "|___         ",
        " __" N "|/   |" N "|   (_) " N "|   \\|" N "|    |" N "|" N "|" N "|___        ",
        " __" N "|/   |" N "|   (_) " N "|   \\|/" N "|    |" N "|" N "|" N "|___       ",
        " __" N "|/   |" N "|   (_) " N "|   \\|/" N "|    |" N "|   /" N "|" N "|___   ",
        " __" N "|/   |" N "|   (_) " N "|   \\|/" N "|    |" N "|   / \\" N "|" N "|___",
        " __" N "|/   |" N "|   (_) " N "|   /|\\" N "|    |" N "|   | |" N "|" N "|___ "
    };

    if (player_attempts <= 9) { printf(N T T); }

    switch (player_attempts) {
        case 11: printf(N N N N N N N N T T "   |___"); break;
        default: printf("   %s", HANGMAN[player_attempts]);
    }

    if (player_attempts <= 10) { printf(N T T); }

    // place for a word
    match_check(word_guess, selected_letterPtr, render_guess_letsPtr, player_attemptsPtr, is_space_pressed_or_notPtr);

    // english alphabet
    for (int i = 0; i < 26; i++) {
        if (!i) { printf(N N T "     "); }

        const char letter = *(alphabet + i);

        // для проверки буква уже выбрана или нет
        bool check_selected = false;

        for (int j = 0; j < 26; j++) {
        	if (tolower(*(alphabetto_check_selected_lettersPtr + j)) == letter) { check_selected = true; }
        }

        if (*selected_letterPtr == letter) { printf("%s", (!check_selected) ? "\033[33m" : "\033[90m"); }

        printf("%c " RESET, letter);

        if (letter == 'P') { printf(N T "      "); }
        if (letter == 'L') { printf(N T "        "); }
        if (i == 90) { printf("\n"); }
    }

    // dividing line
    for (int i = 0; i < 19; i++) {
        if (!i) { printf("\n\n     "); }
        printf("- ");
    }

    // instructions
    printf("\n\n\t       [space] confirm");

}
