#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"

#define NONE          "\033[m"
#define RED           "\033[0;32;31m"
#define LIGHT_RED     "\033[1;31m"
#define GREEN         "\033[0;32;32m"
#define LIGHT_GREEN   "\033[1;32m"
#define BLUE          "\033[0;32;34m"
#define LIGHT_BLUE    "\033[1;34m"
#define DARY_GRAY     "\033[1;30m"
#define CYAN          "\033[0;36m"
#define LIGHT_CYAN    "\033[1;36m"
#define PURPLE        "\033[0;35m"
#define LIGHT_PURPLE  "\033[1;35m"
#define BROWN         "\033[0;33m"
#define YELLOW        "\033[1;33m"
#define LIGHT_GRAY    "\033[0;37m"
#define WHITE         "\033[1;37m"

enum color {red,
            light_red,
            green,
            light_green,
            blue,
            light_blue,
            dary_gray,
            cyan,
            light_cyan,
            purple,
            light_purple,
            brown,
            yellow,
            light_gray,
            white};

int color_id(const char *color) {
    char **color_name = {"red", "light_red", "green", "light_green", "blue", "light_blue", "dary_gray", "cyan", "light_cyan", "purple", "light_purple", "brown", "yellow", "light_gray", "white"};
    int id = -1;
    for (int i = 0; i < 15; ++i) {
        id = strcmp(color, *(color_name+i));
        if (id == 0) {
            return i;
        } else {
            id = -1;
            continue;
        }
    }
    return -1;
}

int cprintf(const char *color, const char *fmt, ...) {
    int id = -1;
    id = color_id(color);
    switch(id) {
        case red:
            printf(RED);
            break;
        case light_red:
            printf(LIGHT_RED);
            break;
        case green:
            printf(GREEN);
            break;
        case light_green:
            printf(LIGHT_GREEN);
            break;
        case blue:
            printf(BLUE);
            break;
        case light_blue:
            printf(LIGHT_BLUE);
            break;
        case dary_gray:
            printf(DARY_GRAY);
            break;
        case cyan:
            printf(CYAN);
            break;
        case light_cyan:
            printf(LIGHT_CYAN);
            break;
        case purple:
            printf(PURPLE);
            break;
        case light_purple:
            printf(LIGHT_PURPLE);
            break;
        case brown:
            printf(BROWN);
            break;
        case yellow:
            printf(YELLOW);
            break;
        case light_gray:
            printf(LIGHT_GRAY);
            break;
        case white:
            printf(WHITE);
            break;
        default:
            printf(NONE);
    }
    printf(fmt);
    printf(NONE);
}


int main() {
    cprintf("red", "%s", "edony?");
}
