/**
 * @file drawing.c
 * @date 2024-08-10
 * @brief
 */

#include "drawing.h"
#include "theme.h"
#include "../../core/log.h"
#include "../../core/result.h"

static HBRUSH mBackgroundBrush = { 0 };
static HBRUSH mForegroundBrush = { 0 };
static HBRUSH mAccentBrush = { 0 };
static HPEN mForegroundPen = { 0 };

void NeonInitDrawingTools(void)
{
    NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Initialising graphics tools."));
    mBackgroundBrush = CreateSolidBrush(NeonGetBackgroundColour());
    mForegroundBrush = CreateSolidBrush(NeonGetForegroundColour());
    mAccentBrush = CreateSolidBrush(NeonGetAccentColour());
    mForegroundPen = CreatePen(PS_SOLID, 1, NeonGetForegroundColour());
}

HBRUSH NeonGetBackgroundBrush(void)
{
    return mBackgroundBrush;
}

HBRUSH NeonGetForegroundBrush(void)
{
    return mForegroundBrush;
}

HBRUSH NeonGetAccentBrush(void)
{
    return mAccentBrush;
}

HPEN NeonGetForegroundPen(void)
{
    return mForegroundPen;
}

void NeonFreeDrawingTools(void)
{
    NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Cleaning up graphics tools."));
    (void) DeleteObject(mBackgroundBrush);
    (void) DeleteObject(mForegroundBrush);
    (void) DeleteObject(mAccentBrush);
    (void) DeleteObject(mForegroundPen);
}