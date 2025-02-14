#include "args.h"

void BlokArgsProcess(LPWSTR commandLine, ArgsInfo *result)
{
    if (!commandLine) { return; }
    if (!result) { return; }

    result->theme = 2;

    int argc = 0;
    LPWSTR *args = CommandLineToArgvW(commandLine, &argc);

    if (!args) { return; }

    for (int argIdx = 0; argIdx < argc; ++argIdx)
    {
        if (_wcsnicmp(args[argIdx], L"--dark-theme", 13*sizeof(unsigned short)) == 0)
        {
            result->theme = 1;
        }
        if (_wcsnicmp(args[argIdx], L"--light-theme", 14*sizeof(unsigned short)) == 0)
        {
            result->theme = 2;
        }
    }

    (void) LocalFree(args);
}