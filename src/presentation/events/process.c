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

    Graphics *graphics = BlokContextGetGraphics();
    State *state = BlokContextGetState();

    // ? 
    (void) GetClientRect(window, &rc);

    // ? Double Buffering
    HDC offScreen = CreateCompatibleDC(surface);
    HBITMAP offCanvas = CreateCompatibleBitmap(surface, rc.right, rc.bottom);
    (void) SelectObject(offScreen, offCanvas);

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

    // ? Copy off screen buffer to surface.
    (void) BitBlt(surface, 0, 0, rc.right, rc.bottom, offScreen, 0, 0, SRCCOPY);

    // ? Cleanup double buffering.
    (void) DeleteObject(offCanvas);
    (void) DeleteDC(offScreen);

    (void) EndPaint(window, &ps);
}

void BlokProcessEventOnKeyDown()
{

}

void BlokProcessEventOnLeftMouseDown()
{

}

void BlokProcessEventOnResize()
{
}