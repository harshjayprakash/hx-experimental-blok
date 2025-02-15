#include "canvas.h"

void BlokCanvasUpdate(Canvas *canvas, const RECT *windowRegion)
{
    if (!canvas) { return; }
    if (!windowRegion) { return; }

    (void) CopyRect(&canvas->region, windowRegion);

    VectorII size = {
        canvas->region.right - canvas->region.left, 
        canvas->region.bottom - canvas->region.top
    };

    BlokVectorIICopy(&canvas->size, size);
}