#pragma once
#include "stdint.h"

#define COLOUR8_BLACK 0
#define COLOUR8_BLUE 1
#define COLOUR8_GREEN 2
#define COLOUR8_CYAN 3
#define COLOUR8_RED 4
#define COLOUR8_MAGENTA 5
#define COLOUR8_BROWN 6
#define COLOUR8_LIGHT_GREY 7
#define COLOUR8_DARK_GREY 8
#define COLOUR8_LIGHT_BLUE 9
#define COLOUR8_LIGHT_GREEN 10
#define COLOUR8_LIGHT_CYAN 11
#define COLOUR8_LIGHT_RED 12
#define COLOUR8_LIGHT_MAGENTA 13
#define COLOUR8_LIGHT_BROWN 14
#define COLOUR8_WHITE 15


#define width 80
#define height 25

void print(const char* s);
void scrollUp();
void newLine();
void Reset();