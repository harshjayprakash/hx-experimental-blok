/**
 * \file button.h
 * \date 18-08-2024
 * \brief Structure of button control.
 *
 * This files contains a structure that represents a button.
 */

#ifndef BLOK_BUTTON_H
#define BLOK_BUTTON_H

#define STRICT 1
#include <Windows.h>
#include <stdlib.h>

/**
 * \brief Models a button.
 */
typedef struct __BlokButtonControl
{
    wchar_t text[60]; ///< Button text
    size_t max;       ///< Maximum text size
    COORD alignment;  ///< Text position
    RECT area;        ///< Control area
} BlokButtonControl;

#endif