#include "console.h"
#include <Windows.h>

void BlokConsoleInit(DebugConsole *con)
{
    if (!con) { return; }

    con->conResult = AllocConsole();

    if (con->conResult == 0)
    {
        (void) MessageBoxW(
            0, L"Console Initialisation Failed.", L"Blok", MB_OK | MB_ICONERROR);
        return;
    }

    con->fileResult = freopen_s(&con->output, "CONOUT$", "w", stdout);

    if (con->fileResult != 0)
    {
        (void) MessageBoxW(
            0, L"Opening StdOut Failed.", L"Blok", MB_OK | MB_ICONERROR);
    }
}

void BlokConsoleFree(DebugConsole *con)
{
    if (!con) { return; }

    if (con->fileResult == 0)
    {
        (void) fclose(stdout);
    }

    if (con->conResult != 0)
    {
        (void) FreeConsole();
    }
}