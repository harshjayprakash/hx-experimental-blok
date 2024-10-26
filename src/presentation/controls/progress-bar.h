/**
 * \file progress-bar.h
 * \date 18-08-2024
 * \brief Structure to represent a progress bar.
 *
 * This file contains the structure for representing information required for a progress
 * bar.
 */

#ifndef BLOK_PROGRESS_BAR_H
#define BLOK_PROGRESS_BAR_H

#define STRICT 1
#include <Windows.h>
#include <stdlib.h>

/**
 * \brief Represents a progress bar.
 */
typedef struct __BlokProgressBarControl
{
    wchar_t text[60];   ///< Text alongside bar
    size_t maxTextSize; ///< Maximum text size
    COORD textPosition; ///< Text position
    RECT barOutline;    ///< Bar container area
    RECT bar;           ///< Bar area
    RECT area;          ///< Control area
    int barMin;         ///< Minimum bar point
    int barMax;         ///< Maximum bar point
    int barSpan;        ///< Bar span length
} BlokProgressBarControl;

#endif