#include "process.h"
#include "../../core/context.h"

void BlokProcessEventOnCreate()
{

}

void BlokProcessEventOnDestroy()
{

}

void BlokProcessEventOnPaint(HWND window)
{
    // TODO: Function to be modularised. (?) Potential functions

    PAINTSTRUCT ps;
    HDC surface = BeginPaint(window, &ps);
    RECT rc = {0};

    Viewport *viewport = BlokContextGetViewport();
    Graphics *graphics = BlokContextGetGraphics();
    State *state = BlokContextGetState();

    // ? 
    (void) GetClientRect(window, &rc);

    // ? Double Buffering
    HDC offScreen = CreateCompatibleDC(surface);
    HBITMAP offCanvas = CreateCompatibleBitmap(surface, rc.right, rc.bottom);
    (void) SelectObject(offScreen, offCanvas);

    HFONT font = CreateFontW(
        18, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, OUT_OUTLINE_PRECIS, 
        DEFAULT_CHARSET, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, 
        L"Segoe UI");
    
    HGDIOBJ oldFont = SelectObject(offScreen, font);

    // ? Paint Background.
    (void) FillRect(offScreen, &rc, graphics->tools.backgroundBrush);

    // ? Paint Square.
    RECT sq = {
        state->box.position.x,
        state->box.position.y,
        state->box.position.x + state->box.size.x,
        state->box.position.y + state->box.size.y,
    };

    (void) FillRect(offScreen, &sq, graphics->tools.accentBrush);

    // ? Paint Panel
    BlokPanelUpdate(&viewport->panel, &rc);
    BlokCanvasUpdate(&viewport->canvas, &rc);

    (void) FillRect(offScreen, &viewport->panel.region, graphics->tools.foregroundBrush);

    // ? Copy off screen buffer to surface.
    (void) BitBlt(surface, 0, 0, rc.right, rc.bottom, offScreen, 0, 0, SRCCOPY);

    (void) SelectObject(offScreen, oldFont);

    // ? Cleanup double buffering.
    (void) DeleteObject(offCanvas);
    (void) DeleteDC(offScreen);

    (void) DeleteObject(font);

    (void) EndPaint(window, &ps);
}

void BlokProcessEventOnKeyDown(HWND window, WPARAM infoWord)
{
    State *state = BlokContextGetState();
    Direction moveBoxOperation = 0;

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
        InvalidateRect(window, &sq, TRUE);
    }
}

void BlokProcessEventOnLeftMouseDown()
{

}

void BlokProcessEventOnResize()
{
}