#ifndef __BLOK_CONTEXT_H_
#define __BLOK_CONTEXT_H_

#include <Windows.h>

typedef struct Context__ {
    HINSTANCE instanceHandle;
    LPCWSTR commandLine;
    DWORD showFlag;
} Context;


#endif // !__BLOK_CONTEXT_H_