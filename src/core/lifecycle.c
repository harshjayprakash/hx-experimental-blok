#include "lifecycle.h"
#include "config/args.h"

void BlokInit(Context *context, HINSTANCE instance, LPWSTR commandLine, DWORD showFlag)
{
    if (!context) { return; }

    context->instance = instance;
    context->commandLine = commandLine;
    context->showFlag = showFlag;

    ArgsInfo argsResult;
    BlokArgsProcess(context->commandLine, &argsResult);

    BlokStateInit(&context->state);
    BlokGraphicsInit(&context->graphics, argsResult.theme);
    BlokViewportInit(&context->viewport, context->instance);
}

void BlokRun(Context *context)
{
    if (!context) { return; }

    BlokViewportShow(&context->viewport, context->showFlag);
}

void BlokFree(Context *context)
{
    if (!context) { return; }

    BlokViewportFree(&context->viewport, context->instance);
    BlokGraphicsFree(&context->graphics);
    BlokStateFree(&context->state);
}