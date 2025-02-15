#ifndef _BLOK_CANVAS_H_
#define _BLOK_CANVAS_H_

#include "../../model/maths/vector.h"
#include <Windows.h>

typedef struct _Canvas {
    RECT region;
    VectorII size;
} Canvas;

void BlokCanvasUpdate(Canvas *canvas, const RECT *windowRegion);

#endif // _BLOK_CANVAS_H_