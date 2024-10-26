/**
 * \file toggle-button.h
 * \date 18-08-2024
 * \brief Structure for a toggle button.
 *
 * This file contains a structure for representing a toggle button.
 */

#ifndef BLOK_TOGGLE_BUTTON_H
#define BLOK_TOGGLE_BUTTON_H

#define STRICT 1
#include <Windows.h>
#include <stdlib.h>

/**
 * \brief Representing a toggle button.
 */
typedef struct __BlokToggleButtonControl
{
    wchar_t text[60];   ///< Text alongside
    size_t max;         ///< Maximum text size
    COORD textPosition; ///< Text position
    RECT wholeArea;     ///< Control area
    RECT buttonArea;    ///< Button area
    RECT selectedArea;  ///< Selected visual button area
    int selected;       ///< Toggle enabled
} BlokToggleButtonControl;

#endif