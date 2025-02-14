#ifndef _BLOK_DRAWTOOLS_H_
#define _BLOK_DRAWTOOLS_H_

#include "theme.h"
#include <Windows.h>

typedef struct _DrawingTools {
    HBRUSH backgroundBrush;
    HBRUSH foregroundBrush;
    HBRUSH accentBrush;

    HBRUSH surfaceBrush;
    HBRUSH surfaceVariantBrush;
    HBRUSH primaryBrush;
    HBRUSH primaryVariantBrush;
    HBRUSH secondaryBrush;
    HBRUSH secondaryVariantBrush;
    HPEN onSurfacePen;
    HPEN onSurfaceVariantPen;
} DrawingTools;

void BlokDrawingToolsInit(DrawingTools *tools, const ColourSpace *colours);

void BlokDrawingToolsFree(DrawingTools *tools);

#endif // _BLOK_DRAWTOOLS_H_