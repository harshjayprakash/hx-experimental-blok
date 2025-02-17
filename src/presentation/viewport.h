#ifndef _BLOK_VIEWPORT_H_
#define _BLOK_VIEWPORT_H_

#include "controls/button.h"
#include "controls/text.h"
#include "components/canvas.h"
#include "components/panel.h"
#include "frame/window.h"
#include <Windows.h>

typedef struct _Viewport {
    Window window;
    RECT region;
    COORD mousePos;
    HFONT font;

    Canvas canvas;
    int isCanvasLocked;
    int isGridVisible;

    Panel panel;
    int isInterfaceVisible;
    Text coordinatesText;
    Button clearAllButton;
    Button generateButton;

    int x, y;
} Viewport;

void BlokViewportInit(Viewport *viewport, HINSTANCE instance);

void BlokViewportShow(Viewport *viewport, DWORD showFlag);

void BlokViewportFree(Viewport *viewport, HINSTANCE instance);

#endif // _BLOK_VIEWPORT_H_