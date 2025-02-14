#include "lifecycle.h"
#include "../config/args.h"

void BlokInit(Context *context, HINSTANCE instance, LPWSTR commandLine, DWORD showFlag)
{
    if (!context) { return; }

    context->instance = instance;
    context->commandLine = commandLine;
    context->showFlag = showFlag;

    ArgsInfo argsResult;
    BlokArgsProcess(context->commandLine, &argsResult);
}

void BlokRun(Context *context)
{
    if (!context) { return; }
}

void BlokFree(Context *context)
{
    if (!context) { return; }
}