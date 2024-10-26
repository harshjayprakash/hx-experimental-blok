/**
 * \file position.c
 * \date 13-08-2024
 * \brief Implementation of position function definitions.
 *
 * This file contains the implementation of the function definitions provided in the
 * position header file.
 */

#include "position.h"
#include "../../core/log.h"
#include "../../core/result.h"

BlokPosition BlokCreatePosition(const int x, const int y)
{
    return (BlokPosition){x, y};
}

BlokPosition BlokCreatePositionFromSelf(const BlokPosition position)
{
    return BlokCreatePosition(position.x, position.y);
}

void BlokSetPosition(BlokPosition *position, const int x, const int y)
{
    if (!position)
    {
        BlokLog(BlokWarning,
                BlokCreateResult(BlokNullPtr,
                                 L"Update Position Failed: Null Pointer Error."));
        return;
    }

    BlokSetXPosition(position, x);
    BlokSetYPosition(position, y);
}

void BlokSetXPosition(BlokPosition *position, const int x)
{
    if (!position)
    {
        BlokLog(BlokWarning,
                BlokCreateResult(BlokNullPtr,
                                 L"X Position Update Failed: Null Pointer Error."));
        return;
    }

    position->x = x;
}

void BlokSetYPosition(BlokPosition *position, const int y)
{
    if (!position)
    {
        BlokLog(BlokWarning,
                BlokCreateResult(BlokNullPtr,
                                 L"Y Position Update Failed: Null Pointer Error."));
        return;
    }

    position->y = y;
}

void BlokCopyPosition(BlokPosition *dest, const BlokPosition src)
{
    if (!dest)
    {
        BlokLog(
            BlokWarning,
            BlokCreateResult(BlokNullPtr, L"Position Copy Failed: Null Pointer Error."));
        return;
    }

    BlokSetPosition(dest, src.x, src.y);
}