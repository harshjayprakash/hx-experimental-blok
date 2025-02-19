#ifndef _BLOK_CONTEXT_H_
#define _BLOK_CONTEXT_H_

#include "../presentation/viewport.h"
#include "../model/state.h"
#include "gfx/graphics.h"
#include "debug/console.h"
#include <Windows.h>

typedef struct _Context {
    HINSTANCE instance;
    LPWSTR commandLine;
    DWORD showFlag;
    Console console;
    Graphics graphics;
    Viewport viewport;
    State state;
    void *result;
} Context;

Context *BlokContextGet(void);

Graphics *BlokContextGetGraphics(void);

Viewport *BlokContextGetViewport(void);

State *BlokContextGetState(void);

#endif // _BLOK_CONTEXT_H_