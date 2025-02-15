#ifndef _BLOK_CONSOLE_H_
#define _BLOK_CONSOLE_H_

#include <stdio.h>

typedef struct _DebugConsole {
    int conResult;
    int fileResult;
    FILE *output;
} DebugConsole;

void BlokConsoleInit(DebugConsole *con);

void BlokConsoleFree(DebugConsole *con);

#endif // _BLOK_CONSOLE_H_