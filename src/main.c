#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "render_menu.h"
#include "handle_menu_input.h"

#include "handle_game_input.h"
#include "match_check.h"
#include "render_game.h"

#include "utils.h"

int main(void) {
    printf("\033[?25l");

    bool running_menu = true;
    bool running_game = false;
    bool selected_option = true;

    bool *menuPtr = &running_menu;
    bool *gamePtr = &running_game;
    bool *selectedPtr = &selected_option;

    while (running_menu) {
        render_menu(selected_option);
        handle_menu_input(menuPtr, gamePtr, selectedPtr);
        clear_screen();
    }

    int player_attempts = 11;
    int *player_attemptsPtr = &player_attempts;

    bool is_space_pressed_or_not = false;
    bool *is_space_pressed_or_notPtr = &is_space_pressed_or_not;

    char alphabet[] = {"QWERTYUIOPASDFGHJKLZXCVBNM"};
    char alphabetto_check_selected_letters[26];
    char selected_letter = '0';


    char *words[] = {"bird", "dord", "buhe"};
    int choice_word = rand() % 3;

    char word_guess[strlen(*(words + choice_word))];
    strcpy(word_guess, words[choice_word]);
    char render_guess_lets[strlen(*(words + choice_word))];

    for (int i = 0; i < strlen(*(words + choice_word)); i++) {
        render_guess_lets[i] = '_';
    }


    char *alphabetto_check_selected_lettersPtr = alphabetto_check_selected_letters;
    char *selected_letterPtr = &selected_letter;
    char *render_guess_letsPtr = render_guess_lets;

    while (running_game) {
        render_game(player_attempts, word_guess, alphabet, selected_letterPtr, alphabetto_check_selected_lettersPtr, render_guess_letsPtr, player_attemptsPtr, is_space_pressed_or_notPtr);
        handle_game_input(selected_letterPtr, alphabetto_check_selected_lettersPtr, is_space_pressed_or_notPtr);
        clear_screen();
    }

    return 0;
}




/*

 ____
|/   |
|   (_)
|   /|\
|    |
|   | |
|
|_





 */

/*
 'ant baboon badger bat bear beaver camel cat clam cobra cougar '
         'coyote crow deer dog donkey duck eagle ferret fox frog goat '
         'goose hawk lion lizard llama mole monkey moose mouse mule newt '
         'otter owl panda parrot pigeon python rabbit ram rat raven '
         'rhino salmon seal shark sheep skunk sloth snake spider '
         'stork swan tiger toad trout turkey turtle weasel whale wolf '
         'wombat zebra ').split()
 */
