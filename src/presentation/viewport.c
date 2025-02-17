#include "viewport.h"
#include <strsafe.h>
#include <time.h>

void BlokViewportInit(Viewport *viewport, HINSTANCE instance)
{
    if (!viewport) { return; }

    srand((unsigned int) time(0));

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

    COORD panelSize = {500, 40};
    COORD panelMargin = {0, 0};
    BlokPanelUpdateEx(&viewport->panel, &viewport->region, &panelSize, &panelMargin);
    BlokCanvasUpdate(&viewport->canvas, &viewport->region);

    POINT coordTextPos = {viewport->panel.region.left +10, viewport->panel.region.top +10};
    SIZE coordTextMgn = {0, 0};
    SIZE coordTextSize = {100, 20};
    BlokTextUpdateEx(
        &viewport->coordinatesText, &coordTextPos, &coordTextSize, &coordTextMgn);
    (void) StringCbPrintfW(viewport->coordinatesText.data, 60, L"(0, 0)");

    POINT clearBtnPos = {
        viewport->coordinatesText.region.right+10, 
        viewport->coordinatesText.region.top
    };
    SIZE clearBtnMgn = {0, 0};
    SIZE clearBtnSz = {60, 20};
    BlokButtonUpdateEx(
        &viewport->clearAllButton, &clearBtnPos, &clearBtnSz, &clearBtnMgn);
    (void) StringCbPrintfW(viewport->clearAllButton.text, 60, L"&Clear All");

    POINT genBtnPos = {
        viewport->clearAllButton.region.right+10, 
        viewport->clearAllButton.region.top
    };
    SIZE genBtnSz = {130, 20};
    BlokButtonUpdateEx(&viewport->generateButton, &genBtnPos, &genBtnSz, &clearBtnMgn);
    (void) StringCbPrintfW(viewport->generateButton.text, 60, L"Generate &Obstructive");
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