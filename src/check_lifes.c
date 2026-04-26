#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void check_lifes_func(bool *is_space_pressed_or_notPtr, char *word_guess, char *selected_letterPtr, char *render_guess_letsPtr, int *player_attemptsPtr) {
	int word_length = strlen(word_guess);

	if (*is_space_pressed_or_notPtr) {
		*is_space_pressed_or_notPtr = false;

    	for (int i = 0; i < word_length; i++) {
        	if (*(word_guess + i) == tolower(*selected_letterPtr)) {
            	*(render_guess_letsPtr + i) = *selected_letterPtr;
         	}
     	}

       	int is_the_choice_mistake = 0;
        for (int i = 0; i < word_length; i++) {
         	if (tolower(*(word_guess + i)) != tolower(*selected_letterPtr)) {
             	is_the_choice_mistake++;
         	}
        }

        if (is_the_choice_mistake == word_length && isalpha(*selected_letterPtr)) {
        	(*player_attemptsPtr)--;
         	*selected_letterPtr = '0';
        }
	}
}
