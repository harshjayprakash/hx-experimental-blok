#include "theme.h"

#define __BLOK_LIGHT_DARK(light, dark) \
    (theme == BLOK_THEME_LIGHT) ? light : dark

void BlokColoursSet(ColourSpace *colours, const Theme theme)
{
    if (!colours) { return; }

    colours->background = __BLOK_LIGHT_DARK(BLOK_COLOUR_WHITE, BLOK_COLOUR_BLACK);
    colours->foreground = __BLOK_LIGHT_DARK(BLOK_COLOUR_BLACK, BLOK_COLOUR_WHITE);
    colours->accent = __BLOK_LIGHT_DARK(BLOK_COLOUR_BLUE, BLOK_COLOUR_AQUA);

    colours->surface = __BLOK_LIGHT_DARK(BLOK_COLOUR_CULTERED, BLOK_COLOUR_EERIE_BLACK);
    colours->surfaceVariant = __BLOK_LIGHT_DARK(BLOK_COLOUR_CULTERED, BLOK_COLOUR_ARSENIC);
    colours->onSurface = __BLOK_LIGHT_DARK(BLOK_COLOUR_EERIE_BLACK, BLOK_COLOUR_CULTERED);
    colours->onSurfaceVariant = __BLOK_LIGHT_DARK(BLOK_COLOUR_LIGHT_GREY, BLOK_COLOUR_SONIC_SILVER);
    colours->primary = __BLOK_LIGHT_DARK(BLOK_COLOUR_ROSE, BLOK_COLOUR_TEAL);
    colours->primaryVariant = __BLOK_LIGHT_DARK(0, 0);
    colours->secondary = __BLOK_LIGHT_DARK(BLOK_COLOUR_SONIC_SILVER, BLOK_COLOUR_LIGHT_GREY);
    colours->secondaryVariant = __BLOK_LIGHT_DARK(BLOK_COLOUR_PALE_SLIVER, 0);
}