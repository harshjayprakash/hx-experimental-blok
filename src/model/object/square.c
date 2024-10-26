/**
 * \file square.c
 * \date 13-08-2024
 * \brief Implementation of square functions.
 *
 * This file contans the implementation of the functions of the square module to create a
 * new square and copy squares.
 */

#include "square.h"
#include "../../core/log.h"

BlokSquare BlokCreateSquare(const BlokPosition position, const BlokSize size)
{
    return (BlokSquare){BlokCreatePositionFromSelf(position),
                        BlokCreateSizeFromSelf(size)};
}

void BlokCopySquare(BlokSquare *dest, const BlokSquare src)
{
    if (!dest)
    {
        BlokLog(
            BlokWarning,
            BlokCreateResult(BlokNullPtr, L"Copying Square Failed: Null Pointer Error."));
        return;
    }

    BlokCopySize(&(dest->size), src.size);
    BlokCopyPosition(&(dest->position), src.position);
}