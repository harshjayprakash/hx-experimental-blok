#ifndef _BLOK_PROCESS_H_
#define _BLOK_PROCESS_H_

#include <Windows.h>

void BlokProcessEventOnCreate();

void BlokProcessEventOnDestroy();

void BlokProcessEventOnPaint(HWND window);

void BlokProcessEventOnKeyDown(HWND window, WPARAM infoWord);

void BlokProcessEventOnLeftMouseDown(HWND window, LPARAM dataLong);

void BlokProcessEventOnResize(HWND window);

void BlokProcessEventOnMouseHover(HWND window, LPARAM dataLong);

#endif // _BLOK_PROCESS_H_