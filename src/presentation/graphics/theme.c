/**
 * \file theme.c
 * \date 13-08-2024
 * \brief Implementation of the functions related to theme managing.
 *
 * This file contains implementation of functions required for theming.
 */

#include "theme.h"

static BlokTheme mTheme = BlokUnsetTheme;

static unsigned long mBlackColour = RGB(0, 0, 0);
static unsigned long mWhiteColour = RGB(255, 255, 255);
static unsigned long mBlueColour = RGB(0, 0, 255);
static unsigned long mAquaColour = RGB(0, 255, 255);

static unsigned long mBackgroundColour = 0UL;
static unsigned long mForegroundColour = 0UL;
static unsigned long mAccentColour = 0UL;

void BlokUpdateColours(void)
{
    switch (mTheme)
    {
    case BlokLightTheme:
        mBackgroundColour = mWhiteColour;
        mForegroundColour = mBlackColour;
        mAccentColour = mBlueColour;
        return;
    case BlokUnsetTheme:
    case BlokDarkTheme:
    default:
        mBackgroundColour = mBlackColour;
        mForegroundColour = mWhiteColour;
        mAccentColour = mAquaColour;
        return;
    }
}

void BlokSetTheme(const BlokTheme theme)
{
    mTheme = theme;
}

unsigned long BlokGetBackgroundColour(void)
{
    return mBackgroundColour;
}

unsigned long BlokGetForegroundColour(void)
{
    return mForegroundColour;
}

unsigned long BlokGetAccentColour(void)
{
    return mAccentColour;
}
