#ifndef MATCH_CHECK_H
#define MATCH_CHECK_H

#include <stdbool.h>

void match_check(char *word_guess, char *selected_letterPtr, char *render_guess_letsPtr, int *player_attemptsPtr, bool *is_space_pressed_or_notPtr);

#endif