#ifndef _BLOK_CONTEXT_H_
#define _BLOK_CONTEXT_H_

#include "../presentation/viewport.h"
#include "gfx/graphics.h"
#include <Windows.h>

typedef struct _Context {
    HINSTANCE instance;
    LPWSTR commandLine;
    DWORD showFlag;
    // TODO: Replace LPVOID with actual types.
    Graphics graphics;
    Viewport viewport;
    void *result;
    void *state;
} Context;

Context *BlokContextGet(void);

Graphics *BlokContextGetGraphics(void);

Viewport *BlokContextGetViewport(void);

#endif // _BLOK_CONTEXT_H_