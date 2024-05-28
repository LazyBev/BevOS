#include "vga.h"

uint16_t column = 0;
uint16_t line = 0;
uint16_t* const vga = (uint16_t* const) 0xb8000;
const uint16_t defaultColour = (COLOUR8_LIGHT_GREY << 8) | (COLOUR8_BLACK << 12);
uint16_t currentColour = defaultColour;

void Reset() {
    line = 0;
    column = 0;
    currentColour = defaultColour;

    for(uint16_t y = 0; y < height; ++y) {
        for(uint16_t x = 0; x < width; ++x) {
            vga[y * width + x] = ' ' | defaultColour;
        }
    }
}

void newLine() {
    if(line < height -1) {
        line++;
        column = 0;
    } else {
        scrollUp();
        column = 0;
    }
}

void scrollUp() {
    for(uint16_t y = 0; y < height; ++y) {
        for(uint16_t x = 0; x < width; ++x) {
            vga[(y-1) * width + x] = vga[y * width + x];
        } 
    }

    for(uint16_t x = 0; x < width; ++x) {
        vga[(height-1) * width + x] = ' ' | currentColour;
    }
}

void print(const char* s) {
    while(*s) {
        switch(*s) {
            case '\n':
                newLine();
                break;
            case '\r':
                column = 0;
                break;
            case '\t':
                if (column == width) {
                    newLine();
                }
                uint16_t tabLen = 4 - (column % 4);
                while(tabLen != 0) {
                    vga[line * width + (column++)] = ' ' | currentColour;
                    tabLen--;
                }
                break;
            default:
                if (column == width) {
                    newLine();
                }
                vga[line * width + (column++)] = *s | currentColour;
                break;
        }
        s++;
    }
}