#include "theme.h"

#define __BLOK_LIGHT_DARK(light, dark) \
    (theme == BLOK_THEME_LIGHT) ? light : dark

void BlokColoursSet(ColourSpace *colours, const Theme theme)
{
    if (!colours) { return; }

    colours->background = __BLOK_LIGHT_DARK(BLOK_COLOUR_WHITE, BLOK_COLOUR_BLACK);
    colours->foreground = __BLOK_LIGHT_DARK(BLOK_COLOUR_BLACK, BLOK_COLOUR_WHITE);
    colours->accent = __BLOK_LIGHT_DARK(BLOK_COLOUR_BLUE, BLOK_COLOUR_AQUA);
}