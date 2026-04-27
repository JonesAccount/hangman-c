 #include <stdbool.h>
 #include <stddef.h>
 #include <stdio.h>
 #include <ctype.h>

 #include "utils.h"
 #include "defs.h"

//----------------------------------------------------------------------
 void render_check_win_or_loss_text(bool win_loss);
 void reset_parameters(bool win_loss, int *player_attempts, char *render_guess_lets, size_t render_guess_lets_size, bool *running_menu, char *selected_letter, char *alphabetto_check_selected_letters);

 //----------------------------------------------------------------------
 bool checking_finished(int *player_attempts, char *render_guess_lets, size_t render_guess_lets_size, bool *running_menu, char *selected_letter, char *alphabetto_check_selected_letters) {
 	bool win_loss = false;
 	{ // check loss
  		if (*player_attempts == 0) {
    		render_check_win_or_loss_text(win_loss);
   			*running_menu = true;
        	return false;
   		}
  	}

   //----------------------------------------------------------------------
   { // check win
   		int check_correct_letters = 0;
     	for (int i = 0; i < render_guess_lets_size; i++) {
      		if (isalpha(*(render_guess_lets + i))) { check_correct_letters++; }
      	}

      	if (check_correct_letters == render_guess_lets_size - 1) {
       		win_loss = true;
         	render_check_win_or_loss_text(win_loss);
        	*running_menu = true;
            return false;
       	}
   }

   return true;
}

//----------------------------------------------------------------------
void render_check_win_or_loss_text(bool win_loss) {
	for (int i = 14; i <= 30; i++) {
		printf("\033[%d;1H", i);
		printf("\033[2K");
    }

    printf("\033[15;19H");
    printf(BOLD "%s!!!" RESET, (win_loss) ? "WINNER" : "LOOSER");

    // dividing line
    printf("\033[16;1H");
    for (int i = 0; i < 19; i++) {
    	if (!i) { printf("\n\n     "); }
        printf("- ");
    }

    // instructions
    printf("\n\n\t       [spase] confirm");

    while (1) { char ch = read_char(); if (ch == ' ') { break; } }
}
