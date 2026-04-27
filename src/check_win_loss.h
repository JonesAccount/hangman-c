#ifndef CHECK_WIN_LOSS_H
#define CHECK_WIN_LOSS_H

#include <stdbool.h>
#include <stddef.h>

void render_check_win_or_loss_text(bool win_loss);
void reset_parameters(bool win_loss, int *player_attempts, char *render_guess_lets, size_t render_guess_lets_size, bool *running_menu, char *selected_letter, char *alphabetto_check_selected_letters);
bool checking_finished(int *player_attempts, char *render_guess_lets, size_t render_guess_lets_size, bool *running_menu, char *selected_letter, char *alphabetto_check_selected_letters);

#endif