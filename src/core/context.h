#ifndef BLOK_CONTEXT_H_
#define BLOK_CONTEXT_H_

#include <Windows.h>

typedef struct _Context {
    HINSTANCE instance;
    LPWSTR commandLine;
    DWORD showFlag;
    // TODO: Replace LPVOID with actual types.
    void *result;
    void *uiviewport;
    void *graphics;
    void *state;
} Context;

Context *BlokContextGet(void);

#endif // BLOK_CONTEXT_H_