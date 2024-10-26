/**
 * \file drawing.c
 * \date 13-08-2024
 * \brief Implementation of the drawing module.
 *
 * This file contains the implementation for the drawing functions for the tools required
 * for drawing to the display.
 */

#include "drawing.h"
#include "../../core/log.h"
#include "theme.h"

static HBRUSH mBackgroundBrush = {0};
static HBRUSH mForegroundBrush = {0};
static HBRUSH mAccentBrush = {0};
static HPEN mForegroundPen = {0};

void BlokInitDrawingTools(void)
{
    mBackgroundBrush = CreateSolidBrush(BlokGetBackgroundColour());
    mForegroundBrush = CreateSolidBrush(BlokGetForegroundColour());
    mAccentBrush = CreateSolidBrush(BlokGetAccentColour());
    mForegroundPen = CreatePen(PS_SOLID, 2, BlokGetForegroundColour());

    BlokLog(BlokInformation,
            BlokCreateResult(BlokNone, L"Initialied GDI Drawing Tools."));
}

HBRUSH BlokGetBackgroundBrush(void)
{
    return mBackgroundBrush;
}

HBRUSH BlokGetForegroundBrush(void)
{
    return mForegroundBrush;
}

HBRUSH BlokGetAccentBrush(void)
{
    return mAccentBrush;
}

HPEN BlokGetForegroundPen(void)
{
    return mForegroundPen;
}

void BlokFreeDrawingTools(void)
{
    (void)DeleteObject(mBackgroundBrush);
    (void)DeleteObject(mForegroundBrush);
    (void)DeleteObject(mAccentBrush);
    (void)DeleteObject(mForegroundPen);

    BlokLog(BlokInformation,
            BlokCreateResult(BlokNone, L"Cleaned Up GDI Drawing Tools."));
}