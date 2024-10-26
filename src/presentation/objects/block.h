/**
 * \file block.h
 * \date 07-09-2024
 * \brief Function definitions for the block object.
 *
 * This file contains the definitions for the block object including: initialising,
 * rendering, releasing resources, getting the block, moving the block or setting
 * boundaries.
 */

#ifndef BLOK_BLOCK_H
#define BLOK_BLOCK_H

#define STRICT 1
#include <Windows.h>

#include "../../model/object/square.h"
#include "../../model/utility/direction.h"

/**
 * \brief Initialises the block object.
 */
void BlokInitBlockObject(void);

/**
 * \brief Renders the block object.
 *
 * \param displayContext The display context handle.
 */
void BlokRenderBlock(HDC displayContext);

/**
 * \brief Moves the block in the specified direction.
 *
 * \param direction The direction to be moved.
 */
void BlokMoveBlock(BlokDirection direction);

/**
 * \brief Sets the boundary the block must stay in.
 *
 * \param size The size of the boundary.
 */
void BlokSetBlockBoundary(const BlokSize size);

/**
 * \brief Gets the position of the block.
 * 
 * \return Stack allocated position of the block.
 */
BlokPosition BlokGetBlockPosition(void);

/**
 * \brief Gets the size of the block.
 * 
 * \return Stack allocated size of the block.
 */
BlokSize BlokGetBlockSize(void);

/**
 * \brief Gets the block as a winapi rectangle.
 *
 * \return The block as the rect type.
 */
RECT BlokGetBlockAsRect(void);

/**
 * \brief Cleans up the resources used by the block object.
 */
void BlokFreeBlockObject(void);

#endif