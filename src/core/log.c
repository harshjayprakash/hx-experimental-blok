/**
 * \file log.c
 * \date 13-08-2024
 * \brief Implementation of log functions.
 *
 * This file contains the implementation of the functions contianed in log.h.
 */

#include "log.h"
#include <stdio.h>
#include <time.h>

static BlokLogTechnique mLogTechnique = BlokConsole;
static FILE *logFile = NULL;
static time_t mTime;
static struct tm mTm;

void BlokInitLogger(const BlokLogTechnique technique)
{
    mLogTechnique = technique;

    if (mLogTechnique == BlokFile)
    {
        logFile = fopen("log.txt", "w");
    }
}

void BlokLog(const BlokLogLevel level, const BlokResult information)
{
    wchar_t *levelsAsString[] = {
        L"Unknown",
        L"Information",
        L"Warning",
        L"Error",
    };

    int levelAsIndex = (int)level;

    mTime = time(NULL);
    mTm = *localtime(&mTime);

    if (mLogTechnique == BlokFile)
    {
        if (!logFile)
        {
            return;
        }

        (void)fwprintf(logFile, L"Blok | %d/%d/%d %d:%d:%d | %ls | %ls\n",
                       mTm.tm_year + 1900, mTm.tm_mon, mTm.tm_mday, mTm.tm_hour,
                       mTm.tm_min, mTm.tm_sec, levelsAsString[levelAsIndex],
                       information.message);

        return;
    }

    (void)fwprintf(stderr, L"Blok | %d/%d/%d %d:%d:%d | %ls | %ls\n", mTm.tm_year + 1900,
                   mTm.tm_mon, mTm.tm_mday, mTm.tm_hour, mTm.tm_min, mTm.tm_sec,
                   levelsAsString[levelAsIndex], information.message);
}

BlokResult BlokLogAndReturn(const BlokLogLevel level, const BlokResult information)
{
    BlokLog(level, information);
    return information;
}

void BlokFreeLogger(void)
{
    if (logFile)
    {
        fclose(logFile);
    }
}