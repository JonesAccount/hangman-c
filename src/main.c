// main.c
// Hangman game - main entry point

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "handle_menu_input.h"
#include "render_menu.h"
#include "handle_game_input.h"
#include "render_game.h"
#include "check_win_loss.h"
#include "check_lifes.h"
#include "utils.h"

int main(void) {
    printf("\033[?25l"); // hide cursor
    srand(time(NULL));   // random seed for word selection

    // game state
    bool running_menu = true;
    bool running_game = false;
    bool selected_option = true;

    // list of words for the game
    const char *words[] = {
        "ant", "baboon", "badger", "bat", "bear", "beaver", "camel", "cat",
        "clam", "cobra", "cougar", "coyote", "crow", "deer", "dog", "donkey",
        "duck", "eagle", "ferret", "fox", "frog", "goat", "goose", "hawk",
        "lion", "lizard", "llama", "mole", "monkey", "moose", "mouse", "mule",
        "newt", "otter", "owl", "panda", "parrot", "pigeon", "python", "rabbit",
        "ram", "rat", "raven", "rhino", "salmon", "seal", "shark", "sheep",
        "skunk", "sloth", "snake", "spider", "stork", "swan", "tiger", "toad",
        "trout", "turkey", "turtle", "weasel", "whale", "wolf", "wombat", "zebra"
    };
    const int words_count = sizeof(words) / sizeof(words[0]);
    char alphabet[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // keyboard layout for display

    // menu loop - runs until player exits
    while (running_menu) { 
        render_menu(selected_option);
        handle_menu_input(&running_menu, &running_game, &selected_option);
        clear_screen();

        // reset game parameters for new round
        char alphabetto_check_selected_letters[26] = {0}; // used letters
        bool is_space_pressed_or_not = false;
        int index_selected_letters = 0;
        char selected_letter = '0';
        int player_attempts = 11; // max wrong guesses

        // pick random word
        int choice_word = rand() % words_count;
        int word_guess_length = strlen(*(words + choice_word)) + 1;
        char word_guess[word_guess_length];
        strcpy(word_guess, words[choice_word]);
        
        // fill display word with underscores
        char render_guess_lets[word_guess_length];
        for (int i = 0; i < word_guess_length - 1; i++) {
            render_guess_lets[i] = '_';
        }
        render_guess_lets[word_guess_length - 1] = '\0';
        size_t render_guess_lets_size = sizeof(render_guess_lets) / sizeof(render_guess_lets[0]);

        // game loop - runs until win or loss
        while (running_game) {
        	check_lifes_func(&is_space_pressed_or_not, word_guess, &selected_letter, render_guess_lets, &player_attempts);
            render_game(player_attempts, word_guess, alphabet, &selected_letter, alphabetto_check_selected_letters, render_guess_lets, &player_attempts, &is_space_pressed_or_not);
            running_game = checking_finished(&player_attempts, render_guess_lets, render_guess_lets_size, &running_menu, &selected_letter, alphabetto_check_selected_letters);
            if (running_game) { handle_game_input(&selected_letter, alphabetto_check_selected_letters, &is_space_pressed_or_not, &index_selected_letters, &running_game, &running_menu); }
            clear_screen();
        }
    }
    
    return 0;
}
