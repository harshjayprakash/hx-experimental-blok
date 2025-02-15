#include "viewport.h"

void BlokViewportInit(Viewport *viewport, HINSTANCE instance)
{
    if (!viewport) { return; }

    BlokWindowInit(&viewport->window, instance);

    (void) GetClientRect(viewport->window.handle, &viewport->window.region);

    VectorII panelSize = {100, 40}, panelMargin = {0, 0};
    BlokPanelUpdateEx(&viewport->panel, &viewport->window.region, &panelSize, &panelMargin);
    BlokCanvasUpdate(&viewport->canvas, &viewport->window.region);
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