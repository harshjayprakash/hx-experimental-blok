#ifndef _BLOK_VIEWPORT_H_
#define _BLOK_VIEWPORT_H_

#include "frame/window.h"
#include <Windows.h>

typedef struct _Viewport {
    Window window;
} Viewport;

void BlokViewportInit(Viewport *viewport);

void BlokViewportFree(Viewport *viewport);

#endif // _BLOK_VIEWPORT_H_