#include <stdbool.h>
#include <stdio.h>

#include "render_menu.h"
#include "defs.h"

void render_menu(bool selected_option) {
    const char *TITLE[] = {
 " _                                     ",
 "| |_  __ _ _ _  __ _ _ __  __ _ _ _   ",
 "| ' \\/ _` | ' \\/ _` | '  \\/ _` | ' \\  ",
 "|_||_\\__,_|_||_\\__, |_||_|\\__,_|_||_| ",
 "                |___/       |         ",
 "                           (_)        ",
 "                           /|\\        ",
 "                            |         ",
 "                           | |        "
 };
        
    for (int i = 0; i < 9; i++) {
        if (!i) { printf("\n    "); }
        printf(BOLD "%s\n    " RESET, *(TITLE + i));
    }
    
    printf("\n\n\t\t%sStart", (selected_option) ? "==> " : "    ");
    printf("\n\n\t\t%sQuit\n\n", (!selected_option) ? "==> " : "    ");
    
    // разделительная линия
    // dividing line
    for (int i = 0; i < 19; i++) {
        if (!i) { printf("\n     "); }
        printf("- ");
    }
    
    printf("\n\n\t [w/s] navigate   [y] confirm");
    
}
