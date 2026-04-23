#include <ctype.h>

#include "utils.h"

void handle_menu_input(bool *menuPtr, bool *gamePtr, bool *selectedPtr) {
    char ch = tolower(read_char());
    
    switch (ch) {
        case 'w': *selectedPtr = true; break;
        case 's': *selectedPtr = false; break;
        case 'y':
            *menuPtr = false;
            if (*selectedPtr) { *gamePtr = true; }
    }
    
}