#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "match_check.h"
#include "defs.h"

void match_check(char *word_guess, char *selected_letterPtr, char *render_guess_letsPtr, int *player_attemptsPtr, bool *is_space_pressed_or_notPtr) {
    int word_length = strlen(word_guess);
    char indents[10];
    
    switch (word_length) {
        case 3: strcpy(indents, N N N T T "    "); break;
        case 4: strcpy(indents, N N N T T "   "); break;
        case 5: strcpy(indents, N N N T T "  "); break;
        case 6: strcpy(indents, N N N T T " "); break;
    }
    
    // check if there is such a letter, if so, show the letter, otherwise minus life
    if (*is_space_pressed_or_notPtr) {
        for (int i = 0; i < word_length; i++) {
            if (*(word_guess + i) == tolower(*selected_letterPtr)) {
                *(render_guess_letsPtr + i) = *selected_letterPtr;
            }
        }
        auto int is_the_choice_mistake = true;
        for (int i = 0; i < word_length; i++) {
            if (*(word_guess + i) != tolower(*selected_letterPtr)) {
                is_the_choice_mistake = false;
            }
        }
    
        if (!is_the_choice_mistake) { (*player_attemptsPtr)--; }
        
        *is_space_pressed_or_notPtr = false;
        
    }
    
    for (int i = 0; i < word_length; i++) {
         if (!i) { printf("%s", indents); }
         printf("%c ", *(render_guess_letsPtr + i));
     }
}
