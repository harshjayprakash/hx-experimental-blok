/**
 * \file text.h
 * \date 18-08-2024
 * \brief Structure for the text.
 *
 * This file contains a structure for information required for rendering text.
 */

#ifndef BLOK_TEXT_H
#define BLOK_TEXT_H

#define STRICT 1
#include <Windows.h>
#include <stdlib.h>

/**
 * \brief Represents a text control.
 */
typedef struct __BlokTextControl
{
    wchar_t text[60]; ///< Text
    size_t max;       ///< Maximum text size
    COORD position;   ///< Text position
    RECT area;        ///< Control area
} BlokTextControl;

#endif