/**
 * \file obstructables.c
 * \date 07-09-2024
 * \brief Function implementation for the obstructable objects.
 *
 * This file contains the function implementation for the obstructable objects.
 */

#include "obstructables.h"
#include "../../model/utility/vector.h"
#include "../graphics/drawing.h"
#include "../window.h"
#include "../components/panel.h"
#include "block.h"
#include <wingdi.h>

static BlokVector mObstructableSquares = {0};

void BlokInitObstructables(void)
{
    mObstructableSquares = BlokCreateVector(2);

    for (int index = 0; index < mObstructableSquares.max; index++)
    {
        BlokNode *nodePtr = BlokGetNodeAsPointer(&mObstructableSquares, index);

        if (!nodePtr)
        {
            continue;
        }

        nodePtr->indexed = 0;
        BlokCopyPosition(&(nodePtr->position), BlokCreatePosition(-1, -1));
    }

    BlokLog(BlokInformation, BlokCreateResult(BlokNone, L"Initialised Obstructables."));
}

void BlokRenderObstructables(HDC displayContext)
{
    BlokSize squareSize = BlokGetBlockSize();

    for (int index = 0; index < mObstructableSquares.max; index++)
    {
        BlokNode *nodePtr = BlokGetNodeAsPointer(&mObstructableSquares, index);

        if (!nodePtr)
        {
            continue;
        }

        if (nodePtr->position.x == -1 || nodePtr->position.y == -1 ||
            nodePtr->indexed == 0)
        {
            continue;
        }

        RECT nodeAsRect = {nodePtr->position.x, nodePtr->position.y,
                           nodePtr->position.x + squareSize.width,
                           nodePtr->position.y + squareSize.height};

        (void)FillRect(displayContext, &nodeAsRect, BlokGetForegroundBrush());
    }
}

void BlokAddObstrutable(const BlokPosition position)
{
    BlokNode node = {position, 1};
    BlokSize nodeSize = BlokGetBlockSize();
    RECT nodeAsRect = {
        position.x,
        position.y,
        position.x + nodeSize.width,
        position.y + nodeSize.height
    };

    (void)BlokPushNode(&mObstructableSquares, node);

    (void)InvalidateRect(BlokGetWindowHandle(), &nodeAsRect, TRUE);
    BlokInvalidateProgressBarArea();
}

void BlokClearObstrutables(void)
{
    (void)BlokClearVector(&mObstructableSquares);
}

int BlokGetObstrutableCount(void)
{
    return mObstructableSquares.size;
}

float BlokGetVectorMemoryPercentage(void)
{
    return ((mObstructableSquares.size * 1.0) / (mObstructableSquares.max * 1.0));
}

int BlokObstrutableExistsAtPosition(const int x, const int y)
{
    return BlokNodeExists(&mObstructableSquares, (BlokNode){{x, y}, 1});
}

BlokPosition BlokGetObstructableAtIndex(int index)
{
    BlokPosition result = {-1, -1};
    BlokNode *nodePtr = BlokGetNodeAsPointer(&mObstructableSquares, index);

    if (!nodePtr)
    {
        return result;
    }

    BlokCopyPosition(&result, nodePtr->position);
    return result;
}

void BlokFreeObstructables(void)
{
    BlokDestroyVector(&mObstructableSquares);
    BlokLog(BlokInformation,
            BlokCreateResult(BlokNone, L"Cleaned Up Obstructable Resources."));
}