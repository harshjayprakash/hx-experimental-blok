#include "process.h"
#include "../../core/context.h"
#include <strsafe.h>
#include <Windowsx.h>

#define __BLOK_TOGGLE(v) \
    v = !v

void BlokProcessEventOnPaint(HWND window)
{
    // TODO: Function to be modularised. (?) Potential functions

    Viewport *viewport = BlokContextGetViewport();
    Graphics *graphics = BlokContextGetGraphics();
    State *state = BlokContextGetState();

    PAINTSTRUCT ps;
    HDC surface = BeginPaint(window, &ps);
    RECT rc = {0};
    RECT *area = &viewport->window.region;

    VectorII scaling = state->box.size;

    // ? 
    (void) GetClientRect(window, &rc);

    // ? Double Buffering
    HDC offScreen = CreateCompatibleDC(surface);
    HBITMAP offCanvas = CreateCompatibleBitmap(surface, rc.right, rc.bottom);
    (void) SelectObject(offScreen, offCanvas);
    
    HGDIOBJ oldFont = SelectObject(offScreen, viewport->font);

    // ? Paint Background.
    (void) FillRect(offScreen, &rc, graphics->tools.surfaceBrush);

    if (viewport->isGridVisible)
    {
        // ? Paint Grid.
        HGDIOBJ oldPen = SelectObject(offScreen, graphics->tools.onSurfaceVariantPen);
    
        for (int gIdx = 0; gIdx < viewport->window.region.right; gIdx += 15)
        {
            MoveToEx(offScreen, gIdx, 0, NULL);
            LineTo(offScreen, gIdx, viewport->window.region.bottom);
        }
    
        for (int gIdx = 0; gIdx < viewport->window.region.bottom; gIdx += 15)
        {
            MoveToEx(offScreen, 0, gIdx, NULL);
            LineTo(offScreen, viewport->window.region.right, gIdx);
        }
    
        (void) SelectObject(offScreen, oldPen);
    }


    // ? Paint Square.
    RECT sq = {
        state->box.position.x,
        state->box.position.y,
        state->box.position.x + state->box.size.x,
        state->box.position.y + state->box.size.y,
    };

    RECT isq = { 
        sq.left + 5, 
        sq.top + 5, 
        sq.right - 5, 
        sq.bottom - 5 
    };

    (void) FillRect(offScreen, &sq, graphics->tools.primaryBrush);
    (void) FillRect(offScreen, &isq, graphics->tools.surfaceBrush);

    // ? Paint Obstructives
    for (long long obsIdx = 0; obsIdx < state->obstructives.size; obsIdx++)
    {
        VectorII pos = state->obstructives.arr[obsIdx].data;
        RECT obrc = {pos.x, pos.y, pos.x + scaling.x, pos.y + scaling.y};
        (void) FillRect(offScreen, &obrc, graphics->tools.secondaryBrush);
    }

    if (viewport->isInterfaceVisible)
    {
        // ? Paint Panel
        BlokPanelUpdate(&viewport->panel, &rc);
        BlokCanvasUpdate(&viewport->canvas, &rc);
    
        (void) FillRect(offScreen, &viewport->panel.region, graphics->tools.surfaceVariantBrush);
    
        SetTextColor(offScreen, graphics->colours.onSurface);
        SetBkColor(offScreen, graphics->colours.surfaceVariant);

        // ? Draw Coordinates Text
        wchar_t text[60];
        StringCbPrintfW(text, 60*sizeof(wchar_t), L"(%d, %d)", sq.left, sq.top);
        RECT textC = {
            viewport->panel.region.left + 10,
            viewport->panel.region.top + 10,
            viewport->panel.region.left + 150,
            viewport->panel.region.top + 30
        };
        DrawTextW(offScreen, text, -1, &textC, DT_LEFT | DT_TOP);
        
        // ? Clear All Button
        HGDIOBJ _oldPen =  SelectObject(offScreen, graphics->tools.onSurfaceVariantPen);
        HGDIOBJ _oldBrush = SelectObject(offScreen, graphics->tools.surfaceVariantBrush);
        wchar_t clearAlltext[60];
        StringCbPrintfW(clearAlltext, 60*sizeof(wchar_t), L"%s", L"&Clear All");
        RECT clearAllC = {0};
        CopyRect(&clearAllC, &textC);
        clearAllC.left += 100;
        clearAllC.right += 30;
        (void) SetBkMode(offScreen, TRANSPARENT);

        if (viewport->x > clearAllC.left && viewport->x < clearAllC.right
            && viewport->y > clearAllC.top && viewport->y < clearAllC.bottom)
        {
            (void) SelectObject(offScreen, graphics->tools.surfaceBrush);
            (void) SelectObject(offScreen, graphics->tools.onSurfacePen);
            (void) SetBkColor(offScreen, graphics->colours.surface);
        }
        (void) Rectangle(offScreen, clearAllC.left, clearAllC.top, clearAllC.right, clearAllC.bottom);
        (void) DrawTextW(offScreen, clearAlltext, -1, &clearAllC, DT_CENTER | DT_VCENTER | DT_NOCLIP );

        SetTextColor(offScreen, graphics->colours.onSurface);
        SetBkColor(offScreen, graphics->colours.surfaceVariant);
        SelectObject(offScreen, graphics->tools.onSurfaceVariantPen);
        SelectObject(offScreen, graphics->tools.surfaceVariantBrush);
        // ? Generate Button
        wchar_t generateButtonText[60];
        StringCbPrintfW(generateButtonText, 60*sizeof(wchar_t), L"%s", L"&Generate");
        RECT generateButtonRc = {0};
        CopyRect(&generateButtonRc, &clearAllC);
        generateButtonRc.left += 180;
        generateButtonRc.right += 30;
        (void) SetBkMode(offScreen, TRANSPARENT);

        if (viewport->x > generateButtonRc.left && viewport->x < generateButtonRc.right
            && viewport->y > generateButtonRc.top && viewport->y < generateButtonRc.bottom)
        {
            (void) SelectObject(offScreen, graphics->tools.surfaceBrush);
            (void) SelectObject(offScreen, graphics->tools.onSurfacePen);
            (void) SetBkColor(offScreen, graphics->colours.surface);
        }
        (void) Rectangle(offScreen, generateButtonRc.left, generateButtonRc.top, generateButtonRc.right, generateButtonRc.bottom);
        (void) DrawTextW(offScreen, generateButtonText, -1, &generateButtonRc, DT_CENTER | DT_VCENTER | DT_NOCLIP );

        (void) SelectObject(offScreen, _oldPen);
        (void) SelectObject(offScreen, _oldBrush);


        // ? Reset Button

        // ? Lock Toggle

        // ? List Memory Bar
    }

    // ? Copy off screen buffer to surface.
    (void) BitBlt(surface, 0, 0, rc.right, rc.bottom, offScreen, 0, 0, SRCCOPY);

    (void) SelectObject(offScreen, oldFont);

    // ? Cleanup double buffering.
    (void) DeleteObject(offCanvas);
    (void) DeleteDC(offScreen);

    (void) EndPaint(window, &ps);
}

void BlokProcessEventOnKeyDown(HWND window, WPARAM infoWord)
{
    State *state = BlokContextGetState();
    Viewport *viewport = BlokContextGetViewport();
    Direction moveBoxOperation = 0;
    int changeGridVisibility = 0;
    int changeInterfaceVisibility = 0;

    switch (infoWord)
    {
    case 'W': 
        moveBoxOperation = BLOK_DIRECTION_NORTH; 
        break;
    
    case 'A':
        moveBoxOperation = BLOK_DIRECTION_WEST;
        break;
    
    case 'S':
        moveBoxOperation = BLOK_DIRECTION_SOUTH;
        break;
    
    case 'D':
        moveBoxOperation = BLOK_DIRECTION_EAST;
        break;

    case 'G':
        changeGridVisibility = 1;
        break;

    case 'I':
        changeInterfaceVisibility = 1;
        break;
    }

    if (moveBoxOperation)
    {
        BlokStateMoveBox(state, moveBoxOperation);
        RECT sq = {
            state->box.position.x - state->box.size.x,
            state->box.position.y - state->box.size.x,
            state->box.position.x + (state->box.size.x * 2),
            state->box.position.y + (state->box.size.y * 2),
        };
        InvalidateRect(window, &sq, FALSE);
        InvalidateRect(window, &viewport->panel.region, FALSE);
    }

    if (changeGridVisibility)
    {
        viewport->isGridVisible = !viewport->isGridVisible;
        InvalidateRect(window, &viewport->canvas.region, FALSE);
    }

    if (changeInterfaceVisibility)
    {
        viewport->isInterfaceVisible = !viewport->isInterfaceVisible;
        InvalidateRect(window, &viewport->panel.region, FALSE);
    }
}

void BlokProcessEventOnLeftMouseDown(HWND window, LPARAM dataLong)
{
    State *state = BlokContextGetState();
    
    VectorII span = state->box.size;

    VectorII mpos = {
        (GET_X_LPARAM(dataLong) / span.x) * span.x,
        (GET_Y_LPARAM(dataLong) / span.y) * span.y
    };

    Node node = {mpos};
    
    long long r = BlokDynListAdd(&state->obstructives, &node);
    (void) wprintf(L"pushed to list at idx %lld (%d, %d)\n",r, mpos.x, mpos.y);

    RECT refreshRegion = {
        mpos.x,
        mpos.y,
        mpos.x + span.x,
        mpos.y + span.y
    };

    (void) InvalidateRect(window, &refreshRegion, TRUE);
}

void BlokProcessEventOnResize(HWND window)
{
    Viewport *viewport = BlokContextGetViewport();

    (void) GetClientRect(window, &viewport->window.region);
}

void BlokProcessEventOnMouseHover(HWND window, LPARAM dataLong)
{
    Viewport *viewport = BlokContextGetViewport();

    viewport->window.mouse.X = GET_X_LPARAM(dataLong);
    viewport->window.mouse.Y = GET_Y_LPARAM(dataLong);

    InvalidateRect(window, NULL, FALSE);
}