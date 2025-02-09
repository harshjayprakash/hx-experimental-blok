#include "theme.h"

#define ___BLOK_LIGHT_DARK(light, dark) \
    (theme == BLOK_THEME_DARK) ? dark : light

void BlokThemeSet(SelectColours *colours, const Theme theme)
{
    if (!colours) { return; }

    colours->background = ___BLOK_LIGHT_DARK(BLOK_COLOUR_WHITE, BLOK_COLOUR_BLACK);
    colours->foreground = ___BLOK_LIGHT_DARK(BLOK_COLOUR_BLACK, BLOK_COLOUR_WHITE);
    colours->accent = ___BLOK_LIGHT_DARK(BLOK_COLOUR_BLUE, BLOK_COLOUR_AQUA);
}