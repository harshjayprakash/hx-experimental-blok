/**
 * \file canvas.h
 * \date 18-08-2024
 * \brief Function definitions for the canvas component.
 *
 * This file contains the function definitions for the canvas component's initialisation,
 * rendering and releasing resources.
 */

#ifndef BLOK_CANVAS_H
#define BLOK_CANVAS_H

#define STRICT 1
#include <Windows.h>

/**
 * \brief Initialises the canvas component.
 */
void BlokInitCanvasComponent(void);

/**
 * \brief Renders the canvas components.
 *
 * \param displayContext The display context handle.
 */
void BlokRenderCanvasComponent(HDC displayContext);

/**
 * \brief Returns if the canvas has been locked.
 *
 * \return If the canvas has been locked.
 */
int BlokIsCanvasLocked(void);

/**
 * \brief Toggles the lock for the canvas component.
 */
void BlokToggleCanvasLock(void);

/**
 * \brief Frees the canvas component.
 */
void BlokFreeCanvasComponent(void);

#endif