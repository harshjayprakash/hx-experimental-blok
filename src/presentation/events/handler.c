/**
 * \file handler.c
 * \date 07-09-2024
 * \brief Implementation of the window handle events.
 *
 * This file contains the implementation of handling window events.
 */

#define STRICT 1
#include "handler.h"
#include "../../core/log.h"
#include "../components/canvas.h"
#include "../components/panel.h"
#include "../objects/block.h"
#include "../objects/obstructables.h"
#include "../window.h"
#include <Windows.h>
#include <time.h>

void BlokHandleWindowPaintEvent(HDC displayContext)
{
    BlokRenderCanvasComponent(displayContext);
    BlokRenderPanelComponent(displayContext);
}

void BlokHandleWindowKeyDownEvent(WPARAM wordParam)
{
    BlokDirection direction;

    switch ((int)wordParam)
    {
    case VK_UP:
        BlokLog(BlokInformation,
                BlokCreateResult(BlokNone, L"Up Arrow Key Event Detected."));
        direction = BlokNorth;
        break;
    case VK_RIGHT:
        BlokLog(BlokInformation,
                BlokCreateResult(BlokNone, L"Right Arrow Key Event Detected."));
        direction = BlokEast;
        break;
    case VK_DOWN:
        BlokLog(BlokInformation,
                BlokCreateResult(BlokNone, L"Down Arrow Key Event Detected."));
        direction = BlokSouth;
        break;
    case VK_LEFT:
        BlokLog(BlokInformation,
                BlokCreateResult(BlokNone, L"Left Arrow Key Event Detected"));
        direction = BlokWest;
        break;
    default:
        return;
    }

    BlokMoveBlock(direction);
    BlokUpdateCoordinatesText();

    BlokSize sqSize = BlokGetBlockSize();

    RECT updateRegion = BlokGetBlockAsRect();
    updateRegion.top -= sqSize.height;
    updateRegion.left -= sqSize.width;
    updateRegion.right += sqSize.height;
    updateRegion.bottom += sqSize.width;

    (void)InvalidateRect(BlokGetWindowHandle(), &updateRegion, FALSE);
    BlokInvalidateCoordinateTextArea();
}

void BlokHandleWindowLeftMouseDown(LPARAM longParam)
{
    int positionX = (LOWORD(longParam));
    int positionY = (HIWORD(longParam));

    if (BlokIsInPanelArea(positionX, positionY))
    {
        if (BlokIsInClearButtonArea(positionX, positionY))
        {
            BlokLog(BlokInformation,
                    BlokCreateResult(BlokNone, L"Clearing All Obstructables."));
            BlokClearObstrutables();
            BlokUpdateVectorMemoryBar();
            (void)InvalidateRect(BlokGetWindowHandle(), NULL, FALSE);
            return;
        }

        if (BlokIsInLockToggleArea(positionX, positionY))
        {
            BlokLog(BlokInformation, BlokCreateResult(BlokNone, L"Toggling Lock Mode."));
            BlokHandleLockToggleButtonClick();
            BlokInvalidateLockedToggleArea();
            return;
        }

        if (BlokIsInGenerateButtonArea(positionX, positionY))
        {
            BlokLog(BlokInformation,
                    BlokCreateResult(BlokNone, L"Generating Random Obstructables."));
            RECT windowArea = BlokGetWindowArea();

            BlokSize squareSize = BlokGetBlockSize();

            int generateCount = (windowArea.bottom * windowArea.right) / 2000;

            for (int index = 0; index < generateCount; index++)
            {
                int newX = ((rand() % windowArea.right) / squareSize.width) *
                           squareSize.width;
                int newY = ((rand() % windowArea.bottom) / squareSize.height) *
                           squareSize.height;

                if (BlokObstrutableExistsAtPosition(newX, newY))
                {
                    continue;
                }

                BlokAddObstrutable(BlokCreatePosition(newX, newY));
                BlokUpdateVectorMemoryBar();
            }
        }

        return;
    }

    if (BlokIsCanvasLocked())
    {
        return;
    }

    BlokSize squareSize = BlokGetBlockSize();

    int MultiX = (positionX / squareSize.width) * squareSize.width;
    int MultiY = (positionY / squareSize.height) * squareSize.height;

    wchar_t logMessage[60];

    (void)swprintf(logMessage, 60, L"Click At (%d, %d)", MultiX, MultiY);
    BlokLog(BlokInformation, BlokCreateResult(BlokNone, logMessage));

    if (BlokObstrutableExistsAtPosition(MultiX, MultiY))
    {
        BlokLog(BlokInformation,
                BlokCreateResult(BlokNone,
                                 L"Existing Obstructable At Given Position: Skipping."));
        return;
    }

    BlokAddObstrutable(BlokCreatePosition(MultiX, MultiY));
    BlokUpdateVectorMemoryBar();
}