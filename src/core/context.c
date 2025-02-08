#include "context.h"

void BlokContextInit(
    Context *context, HINSTANCE instanceHandle, LPCWSTR commandLine, DWORD showFlag)
{
    if (!context) { return; }
    if (!instanceHandle) { return; }

    context->instanceHandle = instanceHandle;
    context->commandLine = commandLine;
    context->showFlag = showFlag;
}

void BlokContextRun(Context *context)
{
    if (!context) { return; }

    (void) MessageBoxW(0, L"Test", L"Test", MB_OK);
}

void BlokContextTerminate(Context *context)
{
    if (!context) { return; }
}