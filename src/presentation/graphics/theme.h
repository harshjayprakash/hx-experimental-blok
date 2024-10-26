/**
 * \file theme.h
 * \date 13-08-2024
 * \brief Function definitions and enumeration for theming.
 *
 * This file contains an enumeration to denote the current theme and function defintions
 * to set and get the colours within the theme.
 */

#ifndef BLOK_THEME_H
#define BLOK_THEME_H

#define STRICT 1
#include <Windows.h>

#include "../../core/result.h"

/**
 * \brief The chosen theme.
 */
typedef enum __BlokTheme
{
    BlokUnsetTheme = 0x000001, ///< Unset Theme
    BlokLightTheme = 0x000002, ///< Light Mode
    BlokDarkTheme = 0x000003,  ///< Dark Mode
    BlokCustomTheme = 0x000004 ///< Custom Theme
} BlokTheme;

/**
 * \brief Update the colours based on the chosen theme.
 *
 * \warning This function must be called to initialise the colours.
 */
void BlokUpdateColours(void);

/**
 * \brief Set the theme.
 *
 * \param theme The theme.
 */
void BlokSetTheme(const BlokTheme theme);

/**
 * \brief Gets the background colour.
 *
 * \return The background colour.
 */
unsigned long BlokGetBackgroundColour(void);

/**
 * \brief Gets the foreground colour.
 *
 * \return The foreground colour.
 */
unsigned long BlokGetForegroundColour(void);

/**
 * \brief Gets the accent colour.
 *
 * \return The accent colour.
 */
unsigned long BlokGetAccentColour(void);

#endif