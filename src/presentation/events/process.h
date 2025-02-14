#ifndef _BLOK_PROCESS_H_
#define _BLOK_PROCESS_H_

#include <Windows.h>

void BlokProcessEventOnCreate();

void BlokProcessEventOnDestroy();

void BlokProcessEventOnPaint(HWND window);

void BlokProcessEventOnKeyDown();

void BlokProcessEventOnLeftMouseDown();

void BlokProcessEventOnResize();

#endif // _BLOK_PROCESS_H_