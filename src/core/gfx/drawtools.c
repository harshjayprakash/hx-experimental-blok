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

    tools->surfaceBrush = CreateSolidBrush(colours->surface);
    tools->surfaceVariantBrush = CreateSolidBrush(colours->surfaceVariant);
    tools->primaryBrush = CreateSolidBrush(colours->primary);
    tools->primaryVariantBrush = CreateSolidBrush(colours->primaryVariant);
    tools->secondaryBrush = CreateSolidBrush(colours->secondary);
    tools->secondaryVariantBrush = CreateSolidBrush(colours->secondaryVariant);
    tools->onSurfacePen = CreatePen(PS_SOLID, 1, colours->onSurface);
    tools->onSurfaceVariantPen = CreatePen(PS_SOLID, 1, colours->onSurfaceVariant);
}

void BlokDrawingToolsFree(DrawingTools *tools)
{
    if (!tools) { return; }

    __BLOK_FREE_WINGDI_OBJECT(tools->backgroundBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->foregroundBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->accentBrush);

    __BLOK_FREE_WINGDI_OBJECT(tools->surfaceBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->surfaceVariantBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->primaryBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->primaryVariantBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->secondaryBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->secondaryVariantBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->onSurfacePen);
    __BLOK_FREE_WINGDI_OBJECT(tools->onSurfaceVariantPen);
}