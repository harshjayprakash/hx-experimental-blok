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

#endif // !__BLOK_WINDOW_H_