/**
 * \file position.h
 * \date 13-08-2024
 * \brief Function definitions and structure for the position.
 *
 * This file contains the structure to model position and function definitions to create
 * and set positions.
 */

#ifndef BLOK_POSITION_H
#define BLOK_POSITION_H

/**
 * \brief Models the position of an object.
 */
typedef struct __BlokPosition
{
    int x; ///< The X Position
    int y; ///< The Y Position
} BlokPosition;

/**
 * \brief Creates a new position object.
 *
 * \param x The x position
 * \param y The y position
 * \return A new stack allocated position object.
 */
BlokPosition BlokCreatePosition(const int x, const int y);

/**
 * \brief Creates a new position object from an existing position object.
 *
 * \param position The existing position object.
 * \return A new stack allocated position object.
 */
BlokPosition BlokCreatePositionFromSelf(const BlokPosition position);

/**
 * \brief Sets the position.
 *
 * \param position The position instance to be updated.
 * \param x The new x position.
 * \param y The new y position.
 */
void BlokSetPosition(BlokPosition *position, const int x, const int y);

/**
 * \brief Sets the x position.
 *
 * \param position The position instance to be updated.
 * \param x The new x position.
 */
void BlokSetXPosition(BlokPosition *position, const int x);

/**
 * \brief Sets the y position.
 *
 * \param position The position instance to be updated.
 * \param y The new y position.
 */
void BlokSetYPosition(BlokPosition *position, const int y);

/**
 * @brief Copies the positon object.
 *
 * @param dest The instance to be copied to.
 * @param src The instance to be copied from.
 */
void BlokCopyPosition(BlokPosition *dest, const BlokPosition src);

#endif