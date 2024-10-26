/**
 * \file obstructables.h
 * \date 13-08-2024
 * \brief Function definitions for obstructable objects.
 *
 * This file contains the function definitions for initialising, rendering and freeing
 * resources in relation to the obstructables. This include any interaction with the
 * obstructables.
 */

#ifndef BLOK_WALLS_H
#define BLOK_WALLS_H

#define STRICT 1
#include "../../model/utility/position.h"
#include <Windows.h>

/**
 * \brief Initialises the obstructables.
 *
 * \warning The `BlokFreeObstructables` function must be called during resource clean up.
 */
void BlokInitObstructables(void);

/**
 * \brief Renders the obstructables.
 *
 * \param displayContext The display context handle.
 */
void BlokRenderObstructables(HDC displayContext);

/**
 * \brief Add an obstructable.
 *
 * \param position The position of the obstructable.
 */
void BlokAddObstrutable(const BlokPosition position);

/**
 * \brief Calculates the percentage of vector memory used.
 *
 * \return The percentage of vector memory used.
 */
float BlokGetVectorMemoryPercentage(void);

/**
 * \brief Gets the number of obstructables created.
 *
 * \return The number of obstructables.
 */
int BlokGetObstrutableCount(void);

/**
 * \brief Clears all obstructables.
 */
void BlokClearObstrutables(void);

/**
 * \brief Checks if a obstructable exists at a position.
 *
 * \param x The x position to be checked.
 * \param y The y position to be checked.
 * \return If obstructable exists.
 *
 * \retval 0: No.
 * \retval 1: Exists.
 */
int BlokObstrutableExistsAtPosition(const int x, const int y);

/**
 * \brief Gets an obstructable at specific index.
 *
 * \param index The index to get the obstructable.
 * \return The position of the obstructable.
 *
 * \retval (-1, -1): Error or No Obstructable Exists at Index.
 * \retval (X, Y) Actual coordinate more than -1: Obstructable position.
 */
BlokPosition BlokGetObstructableAtIndex(int index);

/**
 * \brief Frees memory used by the obstructables.
 *
 * \warning This function must be used in the clean up process.
 */
void BlokFreeObstructables(void);

#endif