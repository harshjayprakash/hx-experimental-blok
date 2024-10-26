/**
 * \file block.c
 * \date 07-09-2024
 * \brief Function implementation for the block object.
 *
 * This file contains the implementaion for the block object.
 */

#include "block.h"
#include "../../core/args.h"
#include "../../core/log.h"
#include "../../core/result.h"
#include "../../model/object/square.h"
#include "../graphics/drawing.h"
#include "obstructables.h"

static BlokSquare mMovableSquare = {0};
static BlokSquare mProjectedSquare = {0};
static BlokSize mMovableSquareBoundary = {0};
static RECT mMovableSquareAsRect = {0};
static RECT mMovableSquareInnerAsRect = {0};

void BlokInitBlockObject(void)
{
    mMovableSquare =
        BlokCreateSquare(BlokCreatePosition(0, 0),
                         BlokCreateSize(BlokGetBlockScale(), BlokGetBlockScale()));

    mMovableSquareAsRect =
        (RECT){mMovableSquare.position.x, mMovableSquare.position.y,
               (mMovableSquare.position.x + mMovableSquare.size.width),
               (mMovableSquare.position.y + mMovableSquare.size.height)};

    mMovableSquareInnerAsRect =
        (RECT){mMovableSquare.position.x + 5, mMovableSquare.position.y + 5,
               (mMovableSquare.position.x + (mMovableSquare.size.width - 5)),
               (mMovableSquare.position.y + (mMovableSquare.size.height - 5))};

    BlokLog(BlokInformation,
            BlokCreateResult(BlokNone, L"Initialised Movable Block Object."));
}

void BlokRenderBlock(HDC displayContext)
{
    (void)FillRect(displayContext, &mMovableSquareAsRect, BlokGetAccentBrush());
    (void)FillRect(displayContext, &mMovableSquareInnerAsRect, BlokGetBackgroundBrush());
}

static int __BlokCanMoveBlock()
{
    int insideBoundary = (mProjectedSquare.position.x >= 0 &&
                          mProjectedSquare.position.x < mMovableSquareBoundary.width &&
                          mProjectedSquare.position.y >= 0 &&
                          mProjectedSquare.position.y < mMovableSquareBoundary.height);

    int hitWall = 0;

    for (int index = 0; index < BlokGetObstrutableCount(); index++)
    {
        BlokPosition pos = BlokGetObstructableAtIndex(index);

        if (pos.x == mProjectedSquare.position.x && pos.y == mProjectedSquare.position.y)
        {
            hitWall = 1;
        }
    }

    return (insideBoundary == 1 && hitWall == 0);
}

void BlokMoveBlock(BlokDirection direction)
{
    BlokCopySquare(&mProjectedSquare, mMovableSquare);

    switch (direction)
    {
    case BlokNorth:
        BlokSetYPosition(&(mProjectedSquare.position),
                         mProjectedSquare.position.y - mProjectedSquare.size.height);
        break;
    case BlokEast:
        BlokSetXPosition(&(mProjectedSquare.position),
                         mProjectedSquare.position.x + mProjectedSquare.size.width);
        break;
    case BlokSouth:
        BlokSetYPosition(&(mProjectedSquare.position),
                         mProjectedSquare.position.y + mProjectedSquare.size.height);
        break;
    case BlokWest:
        BlokSetXPosition(&(mProjectedSquare.position),
                         mProjectedSquare.position.x - mProjectedSquare.size.width);
        break;
    }

    if (__BlokCanMoveBlock())
    {
        BlokCopySquare(&mMovableSquare, mProjectedSquare);
    }

    mMovableSquareAsRect =
        (RECT){mMovableSquare.position.x, mMovableSquare.position.y,
               (mMovableSquare.position.x + mMovableSquare.size.width),
               (mMovableSquare.position.y + mMovableSquare.size.height)};

    mMovableSquareInnerAsRect =
        (RECT){mMovableSquare.position.x + 5, mMovableSquare.position.y + 5,
               (mMovableSquare.position.x + (mMovableSquare.size.width - 5)),
               (mMovableSquare.position.y + (mMovableSquare.size.height - 5))};
}

void BlokSetBlockBoundary(const BlokSize size)
{
    BlokCopySize(&mMovableSquareBoundary, size);
}

BlokPosition BlokGetBlockPosition(void)
{
    return mMovableSquare.position;
}

BlokSize BlokGetBlockSize(void)
{
    return mMovableSquare.size;
}

RECT BlokGetBlockAsRect(void)
{
    return mMovableSquareAsRect;
}

void BlokFreeBlockObject(void)
{
    BlokLog(BlokInformation,
            BlokCreateResult(BlokNone, L"Cleaned Up Movable Block Object."));
}