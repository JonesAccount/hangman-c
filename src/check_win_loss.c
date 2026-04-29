// check_win_loss.c
// Checks if player won or lost the game

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
 
#include "utils.h"
#include "defs.h"

// forward declarations
void render_check_win_or_loss_text(bool win_loss);
void reset_parameters(bool win_loss, int *player_attempts, char *render_guess_lets, size_t render_guess_lets_size, bool *running_menu, char *selected_letter, char *alphabetto_check_selected_letters);

// Checks if game is finished - win or loss
// Returns true if game continues, false if game is over
// player_attempts                   - how many lives left
// render_guess_lets                 - what player sees on screen
// render_guess_lets_size            - length of word
// running_menu                      - true if game is running
// selected_letter                   - letter player chose
// aplhabetto_check_selected_letters - letters already used 
bool checking_finished(int *player_attempts, char *render_guess_lets, size_t render_guess_lets_size, bool *running_menu, char *selected_letter, char *alphabetto_check_selected_letters) {
	bool win_loss = false;
	
 	{ // check loss - if no lives left, player loses
  		if (*player_attempts == 0) {
    		render_check_win_or_loss_text(win_loss);
   			*running_menu = true;
        	return false;
   		}
  }

  { // check win - if all letters guessed, player wins
   		int check_correct_letters = 0;
     
     	// count how many letters player guessed correctly
     	for (int i = 0; i < render_guess_lets_size; i++) {
      		if (isalpha(*(render_guess_lets + i))) { check_correct_letters++; }
      	}
      
      	// if all letters guessed - player wins
      	if (check_correct_letters == render_guess_lets_size - 1) {
       		win_loss = true;
         	render_check_win_or_loss_text(win_loss);
        	*running_menu = true;
            return false;
       	}
  }

   return true; // game continues
}

// Shows win or loss message on screen
// win_loss - true if player won, false if player lost
void render_check_win_or_loss_text(bool win_loss) {
	// clear lines 14 to 30 on screen
	for (int i = 14; i <= 30; i++) {
		printf("\033[%d;1H", i);
		printf("\033[2K");
    }
	
	// print WINNER or LOOSER in bold
    printf("\033[15;19H");
    printf(BOLD "%s!!!" RESET, (win_loss) ? "WINNER" : "LOOSER");

    // print dividing line
    printf("\033[16;1H");
    for (int i = 0; i < 19; i++) {
    	if (!i) { printf("\n\n     "); }
        printf("- ");
    }

    // print instructions
    printf("\n\n\t       [spase] confirm");

    // wait until player pressed space
    while (1) { char ch = read_char(); if (ch == ' ') { break; } }
}
