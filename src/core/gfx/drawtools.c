#include "drawtools.h"

#define __BLOK_FREE_WINGDI_OBJECT(winGdiObject) \
    if (winGdiObject)                           \
    {                                           \
        (void) DeleteObject(winGdiObject);      \
    }                                           

void BlokDrawingToolsInit(DrawingTools *tools, const ColourSpace *colours)
{
    if (!tools) { return; }
    if (!colours) { return; }

    tools->backgroundBrush = CreateSolidBrush(colours->background);
    tools->foregroundBrush = CreateSolidBrush(colours->foreground);
    tools->accentBrush = CreateSolidBrush(colours->accent);
}

void BlokDrawingToolsFree(DrawingTools *tools)
{
    if (!tools) { return; }

    __BLOK_FREE_WINGDI_OBJECT(tools->backgroundBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->foregroundBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->accentBrush);
}