#include "drawing.h"

#define ___BLOK_FREE_WINGDI_OBJECT(winGdiObject) \
    if (winGdiObject != NULL)                    \
    {                                            \
        (void) DeleteObject(winGdiObject);       \
    }

void BlokDrawingInit(Drawing *drawing, const SelectColours *colours)
{
    if (!drawing) { return; }
    if (!colours) { return; }

    drawing->backgroundBrush = CreateSolidBrush(colours->background);
    drawing->foregroundBrush = CreateSolidBrush(colours->foreground);
    drawing->accentBrush = CreateSolidBrush(colours->accent);
}

void BlokDrawingFree(Drawing *drawing)
{
    ___BLOK_FREE_WINGDI_OBJECT(drawing->backgroundBrush);
    ___BLOK_FREE_WINGDI_OBJECT(drawing->foregroundBrush);
    ___BLOK_FREE_WINGDI_OBJECT(drawing->accentBrush);
}