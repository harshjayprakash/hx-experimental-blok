/**
 * \file program.c
 * \date 13-08-2024
 * \brief Implementation of the program module.
 *
 * This file contains the function implementation of the program "singleton", storing
 * global values.
 */

#include "program.h"
#include "../presentation/graphics/drawing.h"

#include "../presentation/window.h"
#include "log.h"
#include "result.h"

static HINSTANCE mInstanceHandle = {0};
static int mShowflag = 0;
static int mInitialised = 0;

BlokResult BlokInit(HINSTANCE instanceHandle, int showFlags)
{
    if (mInitialised)
    {
        return BlokLogAndReturn(
            BlokWarning, BlokCreateResult(BlokCannotReInit,
                                          L"Cannot Re-Initialise Program: Skipping."));
    }

    mInstanceHandle = instanceHandle;
    mShowflag = showFlags;
    mInitialised = 1;

    return BlokCreateResult(BlokSuccess, L"Program Initialised.");
}

int BlokIsInit(void)
{
    return mInitialised;
}

BlokResult BlokStart(void)
{
    BlokInitDrawingTools();
    (void)BlokInitWindow();
    (void)BlokFreeWindow();
    BlokFreeDrawingTools();
    return BlokLogAndReturn(
        BlokInformation,
        BlokCreateResult(BlokSuccess, L"Quit Message Recieved: Closing."));
}

HINSTANCE BlokGetHandle(void)
{
    return mInstanceHandle;
}

int BlokGetShowFlag(void)
{
    return mShowflag;
}

BlokResult BlokFree(void)
{
    return BlokLogAndReturn(
        BlokInformation, BlokCreateResult(BlokSuccess, L"Cleaned Up Program Resources."));
}