// render_menu.c
// Renders the main menu screen

#include <stdbool.h>
#include <stdio.h>

#include "render_menu.h"
#include "defs.h"

// Randers the main menu with title and options
// selected_option - true if "Start" selected, false if "Quit" selected
void render_menu(bool selected_option) {
    
	// ASKII art title
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
       
   // print title
   for (int i = 0; i < 9; i++) {
   		if (!i) { printf("\n    "); }
        printf(BOLD "%s\n    " RESET, *(TITLE + i));
   }
    
   // print Start option - yellow and arrow if selected
   printf("\n\n\t\t%s%sStart" RESET, (selected_option) ? "==> " : "    ", (selected_option) ? YELLOW : "");
   
   // print Quit option - yellow and arrow if selected
   printf("\n\n\t\t%s%sQuit\n\n" RESET, (!selected_option) ? "==> " : "    ", (!selected_option) ? YELLOW : "");
    
   // print dividing line
   for (int i = 0; i < 19; i++) {
        if (!i) { printf("\n     "); }
        printf("- ");
   }
    
   // print instructions at bottom
   printf("\n\n\t[w/s] navigate  [space] confirm");
}
