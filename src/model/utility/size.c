/**
 * \file size.c
 * \date 13-08-2024
 * \brief Implementation of functions for size object.
 *
 * This file contains the implementation of functions required for the size object. This
 * includes creating a new instance and setting sizes.
 */

#include "size.h"
#include "../../core/log.h"

BlokSize BlokCreateSize(const int width, const int height)
{
    return (BlokSize){width, height};
}

BlokSize BlokCreateSizeFromSelf(const BlokSize size)
{
    return BlokCreateSize(size.width, size.height);
}

void BlokSetSize(BlokSize *size, const int width, const int height)
{
    if (!size)
    {
        BlokLog(
            BlokWarning,
            BlokCreateResult(BlokNullPtr, L"Size Update Failed: Null Pointer Error."));
        return;
    }

    BlokSetWidth(size, width);
    BlokSetHeight(size, height);
}

void BlokSetWidth(BlokSize *size, const int width)
{
    if (!size)
    {
        BlokLog(
            BlokWarning,
            BlokCreateResult(BlokNullPtr, L"Width Updated Failed: Null Pointer Error."));
        return;
    }

    size->width = width;
}

void BlokSetHeight(BlokSize *size, const int height)
{
    if (!size)
    {
        BlokLog(
            BlokWarning,
            BlokCreateResult(BlokNullPtr, L"Height Updated Failed: Null Pointer Error."));
        return;
    }

    size->height = height;
}

void BlokCopySize(BlokSize *dest, const BlokSize src)
{
    if (!dest)
    {
        BlokLog(BlokWarning,
                BlokCreateResult(BlokNullPtr, L"Size Copy Failed: Null Pointer Error."));
        return;
    }

    BlokSetSize(dest, src.width, src.height);
}