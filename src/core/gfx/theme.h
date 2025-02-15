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
    BLOK_COLOUR_WHITE = RGB(255, 255, 255),
    BLOK_COLOUR_BLACK = RGB(0, 0, 0),
    BLOK_COLOUR_BLUE = RGB(0, 0, 255),
    BLOK_COLOUR_AQUA = RGB(0, 255, 255),

    BLOK_COLOUR_PASTEL_BROWN = RGB(127, 103, 86),
    BLOK_COLOUR_PALE_SLIVER = RGB(201, 196, 184),
    BLOK_COLOUR_AZUREISH_WHITE = RGB(221, 221, 236),
    BLOK_COLOUR_ALICE_BLUE = RGB(243, 245, 255),
    BLOK_COLOUR_LAVENDER_GREY = RGB(196, 195, 203),
} Colours;

typedef struct _ColourSpace {
    COLORREF background;
    COLORREF foreground;
    COLORREF accent;

    COLORREF surface;
    COLORREF surfaceVariant;
    COLORREF onSurface;
    COLORREF onSurfaceVariant;
    COLORREF primary;
    COLORREF primaryVariant;
    COLORREF secondary;
    COLORREF secondaryVariant;
} ColourSpace;

void BlokColoursSet(ColourSpace *colours, const Theme theme);

#endif // _BLOK_THEME_H_