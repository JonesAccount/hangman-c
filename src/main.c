#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "check_lifes.h"

#include "render_menu.h"
#include "handle_menu_input.h"

#include "handle_game_input.h"
#include "render_game.h"

#include "utils.h"

int main(void) {
    printf("\033[?25l");
    srand(time(NULL));

    bool running_menu = true;
    bool running_game = false;
    bool selected_option = true;

    while (running_menu) {
        render_menu(selected_option);
        handle_menu_input(&running_menu, &running_game, &selected_option);
        clear_screen();
    }

    //----------------------------------------------------------------------
    int player_attempts = 11;
    bool is_space_pressed_or_not = false;
    char alphabet[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char alphabetto_check_selected_letters[26] = {0};
    char selected_letter = '0';

    //----------------------------------------------------------------------
    char *words[] = {"bird", "bird", "bird"};
    int choice_word = rand() % 3;
    int word_guess_length = strlen(*(words + choice_word)) + 1;
    char word_guess[word_guess_length];
    strcpy(word_guess, words[choice_word]);
    char render_guess_lets[word_guess_length];

    for (int i = 0; i < word_guess_length - 1; i++) {
        render_guess_lets[i] = '_';
    }

    //----------------------------------------------------------------------
    while (running_game) {
    	check_lifes_func(&is_space_pressed_or_not, word_guess, &selected_letter, render_guess_lets, &player_attempts);
        render_game(player_attempts, word_guess, alphabet, &selected_letter, alphabetto_check_selected_letters, render_guess_lets, &player_attempts, &is_space_pressed_or_not);
        handle_game_input(&selected_letter, alphabetto_check_selected_letters, &is_space_pressed_or_not);
        clear_screen();
    }

    //----------------------------------------------------------------------

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
