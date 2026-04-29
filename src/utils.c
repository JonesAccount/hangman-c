// utils.c
// Utility functions used across the game

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#include "utils.h"

// Clears the terminal screen
void clear_screen(void) {
    fputs("\033[2J\033[H", stdout); // ANSI escape - clear screen and cursor to top
    fflush(stdout);                 // fflush output buffer
}

// Reads one character from keyboard without waiting for Enter
// Returns the pressed character
char read_char(void) {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);       
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);    
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    return ch;
}
