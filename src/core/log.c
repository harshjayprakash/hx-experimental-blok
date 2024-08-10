/**
 * @file log.c
 * @date 2024-08-09
 * @brief
 */

#include "log.h"
#include <stdio.h>

static NeonLogTechnique mLogTechnique = NeonConsole;
static FILE *logFile = NULL;

void NeonInitLogger(const NeonLogTechnique technique)
{
    mLogTechnique = technique;

    if (mLogTechnique == NeonFile)
    {
        logFile = fopen("log.txt", "w");
    }
}

void NeonLog(const NeonLogLevel level, const NeonResult information)
{
    wchar_t *levelsAsString[] = {
        L"Unknown",
        L"Information", 
        L"Warning", 
        L"Error",
    };

    int levelAsIndex = (int) level;

    if (mLogTechnique == NeonFile)
    {
        if (!logFile) { return; }

        (void) fwprintf(
            logFile, L"Project Neon | %ls | %ls\n", 
            levelsAsString[levelAsIndex], information.message 
        );
        
        return;
    }

    (void) fwprintf(
        stdout, L"Project Neon | %ls | %ls\n", 
        levelsAsString[levelAsIndex], information.message 
    );
}

NeonResult NeonLogAndReturn(const NeonLogLevel level, const NeonResult information)
{
    NeonLog(level, information);
    return information;
}

void NeonFreeLogger(void)
{

}