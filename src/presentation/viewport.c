#include "viewport.h"

void BlokViewportInit(Viewport *viewport, HINSTANCE instance)
{
    if (!viewport) { return; }

    BlokWindowInit(&viewport->window, instance);

    viewport->isInterfaceVisible = 1;
    viewport->isGridVisible = 0;
    viewport->isCanvasLocked = 0;

    viewport->font = CreateFontW(
        16, 0, GM_COMPATIBLE, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, CLEARTYPE_QUALITY, FF_DONTCARE, 
        L"Segoe UI");
    
    if (!viewport->font)
    {
        (void) MessageBoxW(0, L"Font Loading Failed.", L"Blok", MB_OK | MB_ICONERROR);
    }

    (void) GetClientRect(viewport->window.handle, &viewport->region);

    COORD panelSize = {300, 40};
    COORD panelMargin = {0, 0};
    BlokPanelUpdateEx(&viewport->panel, &viewport->region, &panelSize, &panelMargin);
    BlokCanvasUpdate(&viewport->canvas, &viewport->region);
}

void BlokViewportShow(Viewport *viewport, DWORD showFlag)
{
    if (!viewport) { return; }

    BlokWindowShow(&viewport->window, showFlag);
}

void BlokViewportFree(Viewport *viewport, HINSTANCE instance)
{
    if (!viewport) { return; }

    if (viewport->font != (HFONT) 0)
    {
        (void) DeleteObject(viewport->font);
    }

    BlokWindowFree(&viewport->window, instance);
}