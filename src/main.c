#include "core/module.h"
#include "core/context.h"
#include <Windows.h>

int WINAPI wWinMain(
    HINSTANCE hInstance, 
    HINSTANCE hPrevInstance, 
    LPWSTR lpCmdLine, 
    int nShowCmd)
{
    Context *context = BlokContextGet();
    BlokContextInit(context, hInstance, lpCmdLine, nShowCmd);
    BlokContextRun(context);
    BlokContextTerminate(context);

    return 0;
}