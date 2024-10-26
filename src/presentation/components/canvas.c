/**
 * \file canvas.c
 * \date 18-08-2024
 * \brief Implementation for the canvas component.
 *
 * This contains the implementation of the canvas component (initialisation, rendering and
 * releasing resources).
 */

#include "canvas.h"
#include "../objects/block.h"
#include "../objects/obstructables.h"

static int mLocked = 0;

void BlokInitCanvasComponent(void)
{
    BlokInitBlockObject();
    BlokInitObstructables();
}

void BlokRenderCanvasComponent(HDC displayContext)
{
    BlokRenderObstructables(displayContext);
    BlokRenderBlock(displayContext);
}

int BlokIsCanvasLocked(void)
{
    return mLocked;
}

void BlokToggleCanvasLock(void)
{
    mLocked = (mLocked == 0) ? 1 : 0;
}

void BlokFreeCanvasComponent(void)
{
    BlokFreeBlockObject();
    BlokFreeObstructables();
}