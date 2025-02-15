#include "theme.h"

#define __BLOK_SINGLE_COLOUR_TEST 1

#if __BLOK_SINGLE_COLOUR_TEST
#define __BLOK_LIGHT_DARK(light, dark) \
    (theme == BLOK_THEME_LIGHT) ? light : light
#else

#define __BLOK_LIGHT_DARK(light, dark) \
    (theme == BLOK_THEME_LIGHT) ? light : dark

#endif 

void BlokColoursSet(ColourSpace *colours, const Theme theme)
{
    if (!colours) { return; }

    colours->background = __BLOK_LIGHT_DARK(BLOK_COLOUR_WHITE, BLOK_COLOUR_BLACK);
    colours->foreground = __BLOK_LIGHT_DARK(BLOK_COLOUR_BLACK, BLOK_COLOUR_WHITE);
    colours->accent = __BLOK_LIGHT_DARK(BLOK_COLOUR_BLUE, BLOK_COLOUR_AQUA);

    colours->surface = __BLOK_LIGHT_DARK(BLOK_COLOUR_AZUREISH_WHITE, 0);
    colours->surfaceVariant = __BLOK_LIGHT_DARK(BLOK_COLOUR_ALICE_BLUE, 0);
    colours->onSurface = __BLOK_LIGHT_DARK(BLOK_COLOUR_BLACK, 0);
    colours->onSurfaceVariant = __BLOK_LIGHT_DARK(BLOK_COLOUR_LAVENDER_GREY, 0);
    colours->primary = __BLOK_LIGHT_DARK(BLOK_COLOUR_BLUE, BLOK_COLOUR_AQUA);
    colours->primaryVariant = __BLOK_LIGHT_DARK(0, 0);
    colours->secondary = __BLOK_LIGHT_DARK(BLOK_COLOUR_PASTEL_BROWN, 0);
    colours->secondaryVariant = __BLOK_LIGHT_DARK(BLOK_COLOUR_PALE_SLIVER, 0);
}