#ifndef _BLOK_CONTEXT_H_
#define _BLOK_CONTEXT_H_

#include "gfx/graphics.h"
#include <Windows.h>

typedef struct _Context {
    HINSTANCE instance;
    LPWSTR commandLine;
    DWORD showFlag;
    // TODO: Replace LPVOID with actual types.
    Graphics graphics;
    void *result;
    void *uiviewport;
    void *state;
} Context;

Context *BlokContextGet(void);

#endif // _BLOK_CONTEXT_H_