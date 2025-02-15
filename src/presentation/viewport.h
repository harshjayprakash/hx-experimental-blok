#ifndef _BLOK_VIEWPORT_H_
#define _BLOK_VIEWPORT_H_

#include "components/canvas.h"
#include "components/panel.h"
#include "frame/window.h"
#include <Windows.h>

typedef struct _Viewport {
    Window window;
    Canvas canvas;
    Panel panel;
    int isCanvasLocked;
    int isGridVisible;
} Viewport;

void BlokViewportInit(Viewport *viewport, HINSTANCE instance);

void BlokViewportShow(Viewport *viewport, DWORD showFlag);

void BlokViewportFree(Viewport *viewport, HINSTANCE instance);

#endif // _BLOK_VIEWPORT_H_