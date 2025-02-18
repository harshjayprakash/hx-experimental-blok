#include "process.h"
#include "../../core/context.h"
#include "../../service/convert.h"
#include <strsafe.h>
#include <Windowsx.h>

void BlokProcessEventOnPaint(HWND window)
{
    /// Contextual Information.
    Graphics *graphics = BlokContextGetGraphics();
    Viewport *viewport = BlokContextGetViewport();
    State *state = BlokContextGetState();
    VectorII scaling = state->box.size;

    /// Prepare Painting, Create Buffer to Draw to.
    PAINTSTRUCT paintstruct;
    HDC surface = BeginPaint(window, &paintstruct);
    HDC offSurface = CreateCompatibleDC(surface);
    HBITMAP offSurfaceBitmap = CreateCompatibleBitmap(
        surface, viewport->region.right, viewport->region.bottom);
    (void) SelectObject(offSurface, offSurfaceBitmap);

    /// Set Tools, Save Defaults.
    HFONT oldFont = (HFONT) SelectObject(offSurface, viewport->font);
    HBRUSH oldBrush = (HBRUSH) SelectObject(offSurface, graphics->tools.backgroundBrush);
    HPEN oldPen = (HPEN) SelectObject(offSurface, graphics->tools.onSurfacePen);
    INT oldBkMode = SetBkMode(offSurface, TRANSPARENT);
    COLORREF oldBkColour = SetBkColor(offSurface, graphics->colours.surface);
    COLORREF oldTextColour = SetTextColor(offSurface, graphics->colours.onSurface);

    /// Paint Background.
    (void) FillRect(offSurface, &viewport->region, graphics->tools.surfaceBrush);

    /// Paint Grid If Visible.
    if (viewport->isGridVisible)
    {
        (void) SelectObject(offSurface, graphics->tools.onSurfaceVariantPen);

        for (long xAxisIdx = 0; 
            xAxisIdx < viewport->canvas.region.right; 
            xAxisIdx += scaling.x)
        {
            (void) MoveToEx(offSurface, xAxisIdx, 0, NULL);
            (void) LineTo(offSurface, xAxisIdx, viewport->canvas.region.bottom);
        }

        for (long yAxisIdx = 0; 
            yAxisIdx < viewport->canvas.region.bottom; 
            yAxisIdx += scaling.y)
        {
            (void) MoveToEx(offSurface, 0, yAxisIdx, NULL);
            (void) LineTo(offSurface, viewport->canvas.region.right, yAxisIdx);
        }
    }

    /// Paint Box.
    RECT box = BlokConvertVectorRect(state->box.position, state->box.size);
    INT innerBoxSF = 3;
    RECT innerBox = {
        box.left + (scaling.x / innerBoxSF),
        box.top + (scaling.y / innerBoxSF),
        box.right - (scaling.x / innerBoxSF),
        box.bottom - (scaling.y / innerBoxSF)
    };
    (void) FillRect(offSurface, &box, graphics->tools.primaryBrush);
    (void) FillRect(offSurface, &innerBox, graphics->tools.surfaceBrush);

    /// Paint Obstructives.
    for (long obstructIdx = 0; obstructIdx < state->obstructives.size; obstructIdx++)
    {
        RECT obstructiveRc = BlokConvertVectorRect(
            state->obstructives.arr[obstructIdx].data, scaling);
        (void) FillRect(offSurface, &obstructiveRc, graphics->tools.secondaryBrush);
    }

    /// Paint Interface.
    if (viewport->isInterfaceVisible)
    {
        /// Paint Panel Area.
        (void) FillRect(
            offSurface, &viewport->panel.region, graphics->tools.surfaceVariantBrush);
        
        /// Draw Coordinates Text.
        (void) DrawTextW(
            offSurface, viewport->coordinatesText.data, -1, 
            &viewport->coordinatesText.region, 
            DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_TOP);

        /// Draw Clear All Button.
        (void) Rectangle(
            offSurface, viewport->clearAllButton.region.left, 
            viewport->clearAllButton.region.top, viewport->clearAllButton.region.right, 
            viewport->clearAllButton.region.bottom);
        (void) DrawTextW(
            offSurface, viewport->clearAllButton.text, -1, 
            &viewport->clearAllButton.region, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);

        /// Draw Generate Button.
        (void) Rectangle(
            offSurface, viewport->generateButton.region.left, 
            viewport->generateButton.region.top, viewport->generateButton.region.right, 
            viewport->generateButton.region.bottom);
        (void) DrawTextW(
            offSurface, viewport->generateButton.text, -1, 
            &viewport->generateButton.region, 
            DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
        
    }

    /// Copy DC.
    (void) BitBlt(
        surface, 0, 0, viewport->region.right, viewport->region.bottom, 
        offSurface, 0, 0, SRCCOPY);
    
    /// Reset To Defaults.
    (void) SetTextColor(offSurface, oldTextColour);
    (void) SetBkColor(offSurface, oldBkColour);
    (void) SetBkMode(offSurface, oldBkMode);
    (void) SelectObject(offSurface, oldPen);
    (void) SelectObject(offSurface, oldBrush);
    (void) SelectObject(offSurface, oldFont);
    (void) DeleteObject(offSurfaceBitmap);
    (void) DeleteDC(offSurface);
    (void) EndPaint(window, &paintstruct);
}

void BlokProcessEventOnKeyDown(HWND window, WPARAM infoWord)
{
    State *state = BlokContextGetState();
    Viewport *viewport = BlokContextGetViewport();
    Direction moveBoxOperation = 0;
    int changeGridVisibility = 0;
    int changeInterfaceVisibility = 0;
    int generateObstructive = 0;
    int changeTheme = 0;

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
    
    case 'O':
        generateObstructive = 1;
        break;

    case 'I':
        changeInterfaceVisibility = 1;
        break;
    
    case 'T':
        changeTheme = 1;
        break;
    }

    if (moveBoxOperation)
    {
        BlokStateMoveBox(state, moveBoxOperation);
        StringCbPrintfW(
            viewport->coordinatesText.data, 60,
            L"(%d, %d)", state->box.position.x, state->box.position.y);
        
        RECT boxUpdateRegion = {
            state->box.position.x - state->box.size.x,
            state->box.position.y - state->box.size.x,
            state->box.position.x + (state->box.size.x * 2),
            state->box.position.y + (state->box.size.y * 2),
        };
        InvalidateRect(window, &boxUpdateRegion, FALSE);
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

    if (generateObstructive)
    {
        VectorII scale = state->box.size;

        VectorII obstruct = {
            ((rand() % viewport->canvas.size.cx) / scale.x) * scale.x,
            ((rand() % viewport->canvas.size.cy) / scale.y) * scale.y
        };

        Node node = {obstruct};
        BlokDynListAdd(&state->obstructives, &node);

        RECT updateRegion = BlokConvertVectorRect(obstruct, state->box.size);
        InvalidateRect(window, &updateRegion, FALSE);
    }

    if (changeTheme)
    {
        Graphics *graphics = BlokContextGetGraphics();
        int currentTheme = graphics->theme;
        BlokGraphicsFree(graphics);
        BlokGraphicsInit(
            graphics, 
            (currentTheme == 1 || currentTheme == 0) 
            ? BLOK_THEME_LIGHT : BLOK_THEME_DARK
        );
        InvalidateRect(window, NULL, FALSE);
    }
}

void BlokProcessEventOnLeftMouseDown(HWND window, LPARAM dataLong)
{
    State *state = BlokContextGetState();
    Viewport *viewport = BlokContextGetViewport();
    
    VectorII span = state->box.size;

    VectorII mpos = {
        (GET_X_LPARAM(dataLong) / span.x) * span.x,
        (GET_Y_LPARAM(dataLong) / span.y) * span.y
    };

    if (mpos.x > viewport->panel.region.left && mpos.x < viewport->region.right 
        && mpos.y > viewport->panel.region.top && mpos.y < viewport->region.bottom)
    {
        return;
    }

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

    (void) GetClientRect(window, &viewport->region);
    BlokPanelUpdate(&viewport->panel, &viewport->region);
    BlokCanvasUpdate(&viewport->canvas, &viewport->region);
    BlokTextUpdate(
        &viewport->coordinatesText, 
        &((POINT){viewport->panel.region.left+10, viewport->panel.region.top+10}));
    BlokButtonUpdate(
        &viewport->clearAllButton, 
        &((POINT){
            viewport->coordinatesText.region.right+10, 
            viewport->coordinatesText.region.top}
        ));
    BlokButtonUpdate(
        &viewport->generateButton, 
        &((POINT){
            viewport->clearAllButton.region.right+10, 
            viewport->clearAllButton.region.top}
        ));
}

void BlokProcessEventOnMouseHover(HWND window, LPARAM dataLong)
{
    Viewport *viewport = BlokContextGetViewport();

    viewport->mousePos.X = GET_X_LPARAM(dataLong);
    viewport->mousePos.Y = GET_Y_LPARAM(dataLong);

    InvalidateRect(window, NULL, FALSE);
}