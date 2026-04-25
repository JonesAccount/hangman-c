#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#include "utils.h"

void clear_screen(void) {
    fputs("\033[2J\033[H", stdout);
    fflush(stdout);
}

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
