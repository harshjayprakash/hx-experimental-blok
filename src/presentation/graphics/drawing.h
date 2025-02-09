#ifndef __BLOK_DRAWING_H_
#define __BLOK_DRAWING_H_

#include "theme.h"
#include <Windows.h>

typedef struct Drawing__ {
    HBRUSH backgroundBrush;
    HBRUSH foregroundBrush;
    HBRUSH accentBrush;
} Drawing;

void BlokDrawingInit(Drawing *drawing, const SelectColours *colours);

void BlokDrawingFree(Drawing *drawing);

#endif // !__BLOK_DRAWING_H_