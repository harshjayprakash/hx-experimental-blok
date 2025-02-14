#ifndef _BLOK_THEME_H_
#define _BLOK_THEME_H_

#include <Windows.h>

typedef enum _Theme {
    BLOK_THEME_UNSET = 0,
    BLOK_THEME_DARK = 1,
    BLOK_THEME_LIGHT = 2,
} Theme;

#define BLOK_THEME_MIN 0
#define BLOK_THEME_MAX 2

typedef enum _Colours {
    BLOK_COLOUR_WHITE,
    BLOK_COLOUR_BLACK,
    BLOK_COLOUR_BLUE,
    BLOK_COLOUR_AQUA,
} Colours;

typedef struct _ColourSpace {
    COLORREF background;
    COLORREF foreground;
    COLORREF accent;
} ColourSpace;

void BlokColoursSet(ColourSpace *colours, const Theme theme);

#endif // _BLOK_THEME_H_