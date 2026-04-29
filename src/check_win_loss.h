// check_win_loss.h
// Functions for checking win or loss condition

#ifndef CHECK_WIN_LOSS_H
#define CHECK_WIN_LOSS_H

#include <stdbool.h>
#include <stddef.h>

// Shows win or loss message on screen
// win_loss                          - true if player won, false if player lost
void render_check_win_or_loss_text(bool win_loss);

// Resets game parameters for new round
// win_loss                          - true if player won
// player_attempts                   - lives to reset
// render_guess_lets                 - word display to reset
// running_menu                      - menu state
// selected_letter                   - current letter ot reset
// alphabetto_check_selected_letters - used letters to reset
void reset_parameters(bool win_loss, int *player_attempts, char *render_guess_lets, size_t render_guess_lets_size, bool *running_menu, char *selected_letter, char *alphabetto_check_selected_letters);

// Checks if game is finished
// Returns true if game continues, false if game is over
bool checking_finished(int *player_attempts, char *render_guess_lets, size_t render_guess_lets_size, bool *running_menu, char *selected_letter, char *alphabetto_check_selected_letters);

#endif