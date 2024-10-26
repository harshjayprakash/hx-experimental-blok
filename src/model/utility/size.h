/**
 * \file size.h
 * \date 13-08-2024
 * \brief Function definitions and structure for the size object.
 *
 * This file contains the structure to model size and the required function definitions.
 */

#ifndef BLOK_SIZE_H
#define BLOK_SIZE_H

/**
 * \brief Models the size.
 */
typedef struct __BlokSize
{
    int width;  ///< The Width of an Object.
    int height; ///< The Height of an Object.
} BlokSize;

/**
 * \brief Creates a new size object.
 *
 * \param width The represented width.
 * \param height The represented height.
 * \return A new stack allocated size object.
 */
BlokSize BlokCreateSize(const int width, const int height);

/**
 * \brief Creates a new size object from an existing size object.
 *
 * \param size The existing size object.
 * \return A new stack allocated size object.
 */
BlokSize BlokCreateSizeFromSelf(const BlokSize size);

/**
 * \brief Sets the size.
 *
 * \param size The size instance to be updated.
 * \param width The new width.
 * \param height The new height.
 */
void BlokSetSize(BlokSize *size, const int width, const int height);

/**
 * \brief Sets the width.
 *
 * \param size The size instance to be updated.
 * \param width The new width.
 */
void BlokSetWidth(BlokSize *size, const int width);

/**
 * \brief Sets the height.
 *
 * \param size The size instance to be updated.
 * \param height The new height.
 */
void BlokSetHeight(BlokSize *size, const int height);

/**
 * @brief Copy the size instance.
 *
 * @param dest The size to be copied to.
 * @param src The size to be copied from.
 */
void BlokCopySize(BlokSize *dest, const BlokSize src);

#endif