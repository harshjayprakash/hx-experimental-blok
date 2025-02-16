#include "viewport.h"

void BlokViewportInit(Viewport *viewport, HINSTANCE instance)
{
    if (!viewport) { return; }

    BlokWindowInit(&viewport->window, instance);

    viewport->isInterfaceVisible = 1;
    viewport->isGridVisible = 0;
    viewport->isCanvasLocked = 0;
}

void BlokViewportShow(Viewport *viewport, DWORD showFlag)
{
    if (!viewport) { return; }

    BlokWindowShow(&viewport->window, showFlag);
}

void BlokViewportFree(Viewport *viewport, HINSTANCE instance)
{
    if (!viewport) { return; }

    BlokWindowFree(&viewport->window, instance);
}