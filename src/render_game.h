#include <stdio.h>
#include <ctype.h>

#include "match_check.h"
#include "defs.h"

void render_game(int player_attempts, char *word_guess, char *alphabet, char *selected_letterPtr, char *alphabetto_check_selected_lettersPtr, char *render_guess_letsPtr, int *player_attemptsPtr, bool *is_space_pressed_or_notPtr) {

const char *HANGMAN_10[] = {"|", "|", "|", "|___"};
    const char *HANGMAN_9[] = {" __", "|/", "|", "|", "|", "|", "|", "|___"};
    const char *HANGMAN_8[] = {" __", "|/   |", "|", "|", "|", "|", "|", "|___"};
    const char *HANGMAN_7[] = {" __", "|/   |", "|   (", "|", "|", "|", "|", "|___"};
    const char *HANGMAN_6[] = {" __", "|/   |", "|   (_) ", "|", "|", "|", "|", "|___"};
    const char *HANGMAN_5[] = {" __", "|/   |", "|   (_) ", "|    |", "|    |", "|", "|", "|___"};
    const char *HANGMAN_4[] = {" __", "|/   |", "|   (_) ", "|   \\|", "|    |", "|", "|", "|___"};
    const char *HANGMAN_3[] = {" __", "|/   |", "|   (_) ", "|   \\|/", "|    |", "|", "|", "|___"};
    const char *HANGMAN_2[] = {" __", "|/   |", "|   (_) ", "|   \\|/", "|    |", "|   /", "|", "|___"};
    const char *HANGMAN_1[] = {" __", "|/   |", "|   (_) ", "|   \\|/", "|    |", "|   / \\", "|", "|___"};
    const char *HANGMAN_0[] = {" __", "|/   |", "|   (_) ", "|   /|\\", "|    |", "|   | |", "|", "|___"};
            
    switch (player_attempts) {
        case 11:
            printf(N N N N N N N N T T "   |___");
            break; 
        case 10:
            for (int i = 0; i < 4; i++) {
                if (!i) { printf(N N N N N T T); }
                printf("   %s" N T T, *(HANGMAN_10 + i));
            }
            break; 
        case 9:
            for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_9 + i));
            }
            break; 
        case 8:
            for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_8 + i));
            }
            break;
        case 7:
             for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_7 + i));
            }
            break;
        case 6:
            for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_6 + i));
            }
            break;
        case 5:
            for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_5 + i));
            }
            break;
        case 4:
            for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_4 + i));
            }
            break;
        case 3:
             for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_3 + i));
            }
            break;
        case 2:
             for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_2 + i));
            }
            break;
        case 1:
            for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_1 + i));
            }
            break;
        case 0:
            for (int i = 0; i < 8; i++) {
                if (!i) { printf(N T T); }
                printf("   %s" N T T, *(HANGMAN_0 + i));
            }
            break;
        }
    
        // место для слова
        // place for a word
        match_check(word_guess, selected_letterPtr, render_guess_letsPtr, player_attemptsPtr, is_space_pressed_or_notPtr);
    
        // английски алфавит
        // english alphabet
        for (int i = 0; i < 26; i++) {
            if (!i) { printf(N N T "     "); }
            
            // для проверки буква уже выбрана или нет
            bool check_selected = false;
    
            for (int j = 0; j < 26; j++) {

            if (tolower(*(alphabetto_check_selected_lettersPtr + j)) == *(alphabet + i)) { check_selected = true; }
            }
            
            if (!check_selected) {
                printf("%s", (*selected_letterPtr == *(alphabet + i)) ? "\033[33m" : "");
            } else {
                printf("%s", (*selected_letterPtr == *(alphabet + i)) ? "\033[90m" : "");
            }
            
            printf("%c " RESET, *(alphabet + i));
            
            if (*(alphabet + i) == 'P') { printf(N T "      "); }
            if (*(alphabet + i) == 'L') { printf(N T "        "); }
            if (i == 90) { printf("\n"); }
        }
    
        // разделительная линия
        // dividing line
        for (int i = 0; i < 19; i++) {
            if (!i) { printf("\n\n     "); }
            printf("- ");
        }
    
        // инструкция
        // instructions
        printf("\n\n\t       [space] confirm");
    
}
