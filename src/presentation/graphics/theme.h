#ifndef __BLOK_THEME_H_
#define __BLOK_THEME_H_

#include <Windows.h>

typedef enum Theme__ {
    BLOK_THEME_UNSET = 0,
    BLOK_THEME_DARK = 1,
    BLOK_THEME_LIGHT = 2,
} Theme;

#define BLOK_THEME_MIN_BOUND 0
#define BLOK_THEME_MAX_BOUND 2

typedef enum Colour__ {
    BLOK_COLOUR_WHITE = RGB(0xFF, 0xFF, 0xFF),
    BLOK_COLOUR_BLACK = RGB(0x00, 0x00, 0x00),
    BLOK_COLOUR_AQUA = RGB(0x00, 0xFF, 0xFF),
    BLOK_COLOUR_BLUE = RGB(0x00, 0x00, 0xFF),
    BLOK_COLOUR_GREEN = RGB(0x00, 0xFF, 0xA8),
    BLOK_COLOUR_ROSE = RGB(0xFF, 0x00, 0x71),
} Colour;

typedef struct SelectColours__ {
    COLORREF background;
    COLORREF foreground;
    COLORREF accent;
} SelectColours;

void BlokThemeSet(SelectColours *colours, const Theme theme);


#endif // !__BLOK_THEME_H_