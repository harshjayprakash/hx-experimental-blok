#ifndef __BLOK_CONTEXT_H_
#define __BLOK_CONTEXT_H_

#include <Windows.h>

typedef struct Context__ {
    HINSTANCE instanceHandle;
    LPCWSTR commandLine;
    DWORD showFlag;
} Context;

void BlokContextInit(
    Context *context, HINSTANCE instanceHandle, LPCWSTR commandLine, DWORD showFlag);

void BlokContextRun(Context *context);

void BlokContextTerminate(Context *context);

#endif // !__BLOK_CONTEXT_H_