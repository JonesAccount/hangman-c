#include <ctype.h>

#include "handle_game_input.h"
#include "utils.h"

void handle_game_input(char *selected_letterPtr, char *alphabetto_check_selected_lettersPtr, bool *is_space_pressed_or_notPtr) {
    char ch = tolower(read_char());
    
    // для проверки буква уже нажата или нет
    bool check_selected = false;
    
    static int index_selected_letters = 0;
    
    switch (ch) {
        case 'q':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'q') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'Q'; }
            break;
        case 'w':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'w') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'W'; }
            break;
        case 'e':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'e') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'E'; }
            break;
        case 'r':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'r') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'R'; }
            break;
        case 't':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 't') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'T'; }
            break;
        case 'y':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'y') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'Y'; }
            break;
        case 'u':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'u') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'U'; }
            break;
        case 'i':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'i') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'I'; }
            break;
        case 'o':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'o') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'O'; }
            break;
        case 'p':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'p') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'P'; }
            break;
        case 'a':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'a') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'A'; }
            break;
        case 's':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 's') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'S'; }
            break;
        case 'd':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'd') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'D'; }
            break;
        case 'f':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'f') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'F'; }
            break;
        case 'g':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'g') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'G'; }
            break;
        case 'h':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'h') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'H'; }
            break;
        case 'j':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'j') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'J'; }
            break;
        case 'k':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'k') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'K'; }
            break;
        case 'l':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'l') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'L'; }
            break;
        case 'z':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'z') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'Z'; }
            break;
        case 'x':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'x') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'X'; }
            break;
        case 'c':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'c') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'C'; }
            break;
        case 'v':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'v') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'V'; }
            break;
        case 'b':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'b') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'B'; }
            break;
        case 'n':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'n') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'N'; }
            break;
        case 'm':
            for (int i = 0; i < 26; i++) {
                if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == 'm') { check_selected = true; }
            }
            if (!check_selected) { *selected_letterPtr = 'M'; }
            break;
        case ' ':
            *is_space_pressed_or_notPtr = true;
            if (*selected_letterPtr != '0') {
                for (int i = 0; i < 26; i++) {
                    if (tolower(*(alphabetto_check_selected_lettersPtr + i)) == *selected_letterPtr) { check_selected = true; }
                }
                if (!check_selected) {
                    alphabetto_check_selected_lettersPtr[index_selected_letters] = *selected_letterPtr;
                    index_selected_letters++;
                }
            }
    }
    
}