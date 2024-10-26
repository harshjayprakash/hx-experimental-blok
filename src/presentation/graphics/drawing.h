/**
 * \file drawing.h
 * \date 13-08-2024
 * \brief Function definitions for the drawing module.
 *
 * This file contains the function definitions for getting the tools for painting to the
 * display.
 */

#ifndef BLOK_DRAWING_H
#define BLOK_DRAWING_H

#define STRICT 1
#include <Windows.h>

/**
 * \brief Initialises the drawing tools.
 *
 * \warning The tools must be freed using the `BlokFreeDrawingTools` function.
 */
void BlokInitDrawingTools(void);

/**
 * \brief Gets the background coloured solid brush.
 *
 * \return The background coloured solid brush handle.
 */
HBRUSH BlokGetBackgroundBrush(void);

/**
 * \brief Gets the foreground coloured solid brush.
 *
 * \return The foreground coloured solid brush handle.
 */
HBRUSH BlokGetForegroundBrush(void);

/**
 * \brief Gets the foreground coloured solid brush.
 *
 * \return The foreground coloured solid brush handle.
 */
HBRUSH BlokGetAccentBrush(void);

/**
 * \brief Gets the foreground coloured pen.
 *
 * \return The foreground coloured pen handle.
 */
HPEN BlokGetForegroundPen(void);

/**
 * \brief Cleans up resources used by the drawing tools.
 *
 * \warning The tools must be freed using this function.
 */
void BlokFreeDrawingTools(void);

#endif