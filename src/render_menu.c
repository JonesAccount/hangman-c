// render_menu.c

#include <stdbool.h>
#include <stdio.h>

//----------------------------------------------------------------------
#include "render_menu.h"
#include "defs.h"

//----------------------------------------------------------------------
void render_menu(bool selected_option) {
    const char *TITLE[] = {
    	" _                                      ",
     	"| |_  __ _ _ _  __ _ _ __  __ _ _ _     ",
      	"| ' \\/ _` | ' \\/ _` | '  \\/ _` | ' \\",
       	"|_||_\\__,_|_||_\\__, |_||_|\\__,_|_||_|",
       	"                |___/       |           ",
        "                           (_)          ",
        "                           /|\\         ",
        "                            |           ",
        "                           | |          "
 };
       
   //---------------------------------------------------------------------- 
    for (int i = 0; i < 9; i++) {
        if (!i) { printf("\n    "); }
        printf(BOLD "%s\n    " RESET, *(TITLE + i));
    }
    
    //----------------------------------------------------------------------
    printf("\n\n\t\t%s%sStart" RESET, (selected_option) ? "==> " : "    ", (selected_option) ? YELLOW : "");
    printf("\n\n\t\t%s%sQuit\n\n" RESET, (!selected_option) ? "==> " : "    ", (!selected_option) ? YELLOW : "");
    
    //----------------------------------------------------------------------
    // dividing line
    for (int i = 0; i < 19; i++) {
        if (!i) { printf("\n     "); }
        printf("- ");
    }
    
    //----------------------------------------------------------------------
    // instructions
    printf("\n\n\t[w/s] navigate  [space] confirm");
    
}
