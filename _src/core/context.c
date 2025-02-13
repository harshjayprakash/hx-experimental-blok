#include "context.h"

void BlokContextInit(
    Context *context, HINSTANCE instanceHandle, LPCWSTR commandLine, DWORD showFlag)
{
    if (!context) { return; }
    if (!instanceHandle) { return; }

    context->instanceHandle = instanceHandle;
    context->commandLine = commandLine;
    context->showFlag = showFlag;

    BlokRendererInit(&context->renderer, 0);
    BlokWindowInit(&context->window, context->instanceHandle);
}

void BlokContextRun(Context *context)
{
    if (!context) { return; }

    BlokWindowShow(&context->window, context->showFlag);
}

void BlokContextTerminate(Context *context)
{
    if (!context) { return; }

    BlokWindowFree(&context->window, context->instanceHandle);
    BlokRendererFree(&context->renderer);
}