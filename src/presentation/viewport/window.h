#ifndef __BLOK_WINDOW_H_
#define __BLOK_WINDOW_H_

#include <Windows.h>

typedef struct Window__ {
    HWND handle;
    WNDCLASSEXW klass;
    LPCWSTR klassName;
    ATOM klassAtomRef;
    LPWSTR caption;
} Window;

void BlokWindowInit(Window *window, HINSTANCE instanceHandle);

void BlokWindowShow(Window *window, DWORD showFlag);

void BlokWindowFree(Window *window, HINSTANCE instanceHandle);

#endif // !__BLOK_WINDOW_H_