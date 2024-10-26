/**
 * \file window.c
 * \date 13-08-2024
 * \brief Function implementation for the Window.
 *
 * This file contains the implementation for the graphical window.
 */

#define STRICT 1
#include "window.h"
#include "../core/log.h"
#include "../core/program.h"
#include "../core/result.h"
#include "components/canvas.h"
#include "components/panel.h"
#include "events/handler.h"
#include "graphics/drawing.h"
#include "graphics/theme.h"
#include "objects/block.h"

#include <Windows.h>
#include <wchar.h>
#include <wingdi.h>

static HWND mWindow = {0};
static MSG mMessage = {0};
static WNDCLASSEXW mClass = {0};
static wchar_t mName[] = L"__BlokWindowClass";
static wchar_t mCaption[] = L"Blok H2 '24";
static RECT mWindowArea = {0};
static int mWindowHeight = 0;
static int mWindowWidth = 0;
static int mRunning = 0;

static long long __BlokProcedure(HWND windowHandle, UINT message, WPARAM wordParam,
                                 LPARAM longParam)
{
    PAINTSTRUCT paint;
    HDC displayContext;

    switch (message)
    {
    case WM_CREATE:
        (void)GetClientRect(windowHandle, &mWindowArea);
        return 0;
    case WM_DESTROY:
        mRunning = 0;
        PostQuitMessage(0);
        return 0;
    case WM_PAINT: {
        displayContext = BeginPaint(mWindow, &paint);
        HDC bufferedContext = CreateCompatibleDC(displayContext);
        HBITMAP bitmapMemory =
            CreateCompatibleBitmap(displayContext, mWindowWidth, mWindowHeight);
        (void)SelectObject(bufferedContext, bitmapMemory);
        (void)FillRect(bufferedContext, &mWindowArea, BlokGetBackgroundBrush());
        BlokHandleWindowPaintEvent(bufferedContext);
        (void)BitBlt(displayContext, 0, 0, mWindowWidth, mWindowHeight, bufferedContext,
                     0, 0, SRCCOPY);
        (void)DeleteObject(bitmapMemory);
        (void)DeleteObject(bufferedContext);
        (void)EndPaint(windowHandle, &paint);
        return 0;
    }
    case WM_SIZE:
        (void)GetClientRect(windowHandle, &mWindowArea);
        mWindowWidth = mWindowArea.right;
        mWindowHeight = mWindowArea.bottom;
        BlokSetBlockBoundary(BlokCreateSize(mWindowWidth, mWindowHeight));
        BlokUpdatePanelSize();
        return 0;
    case WM_LBUTTONDOWN:
        BlokHandleWindowLeftMouseDown(longParam);
        return 0;
    case WM_KEYDOWN:
        BlokHandleWindowKeyDownEvent(wordParam);
        return 0;
    default:
        return DefWindowProcW(windowHandle, message, wordParam, longParam);
    }
}

static int __BlokMessageLoop(void)
{
    while (GetMessageW(&mMessage, NULL, 0, 0))
    {
        (void)TranslateMessage(&mMessage);
        (void)DispatchMessageW(&mMessage);
    }

    return (int)mMessage.wParam;
}

static BlokResult __BlokCreateWindow(void)
{
    mWindow = CreateWindowExW(WS_EX_OVERLAPPEDWINDOW, mName, mCaption,
                              WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
                              NULL, NULL, BlokGetHandle(), NULL);

    if (!mWindow)
    {
        return BlokLogAndReturn(BlokError,
                                BlokCreateResult(BlokFail, L"Window Creation Failed."));
    }

    return BlokLogAndReturn(BlokInformation,
                            BlokCreateResult(BlokSuccess, L"Created Window."));
}

static BlokResult __BlokRegisterWindow(void)
{
    mClass.cbSize = sizeof(WNDCLASSEXW);
    mClass.style = CS_HREDRAW | CS_VREDRAW;
    mClass.lpfnWndProc = __BlokProcedure;
    mClass.cbClsExtra = 0;
    mClass.cbWndExtra = 0;
    mClass.hInstance = BlokGetHandle();
    mClass.hCursor = LoadCursorW(NULL, IDC_ARROW);
    mClass.hIcon = LoadIconW(BlokGetHandle(), IDI_APPLICATION);
    mClass.hIconSm = LoadIconW(BlokGetHandle(), IDI_APPLICATION);
    mClass.hbrBackground = CreateSolidBrush(BlokGetBackgroundColour());
    mClass.lpszMenuName = NULL;
    mClass.lpszClassName = mName;

    int success = RegisterClassExW(&mClass);

    if (!success)
    {
        return BlokLogAndReturn(BlokError,
                                BlokCreateResult(BlokFail, L"Failed to Register Class."));
    }

    return BlokLogAndReturn(BlokInformation,
                            BlokCreateResult(BlokSuccess, L"Registered Window."));
}

BlokResult BlokInitWindow(void)
{
    BlokResult registerResult = __BlokRegisterWindow();
    if (registerResult.code == BlokFail)
    {
        (void)BlokFreeWindow();
        return BlokLogAndReturn(
            BlokError, BlokCreateResult(BlokFail, L"Window Initialisation Failed."));
    }

    BlokResult createResult = __BlokCreateWindow();
    if (createResult.code == BlokFail)
    {
        (void)BlokFreeWindow();
        return BlokLogAndReturn(
            BlokError, BlokCreateResult(BlokFail, L"Window Initialisation Failed."));
    }

    mRunning = 1;

    BlokInitPanelComponent();
    BlokInitCanvasComponent();

    (void)ShowWindow(mWindow, BlokGetShowFlag());
    (void)UpdateWindow(mWindow);
    (void)__BlokMessageLoop();

    return BlokCreateResult(BlokSuccess, L"Window Initialised.");
}

RECT BlokGetWindowArea(void)
{
    return mWindowArea;
}

HWND BlokGetWindowHandle(void)
{
    return mWindow;
}

BlokResult BlokFreeWindow(void)
{
    BlokFreePanelComponent();
    BlokFreeCanvasComponent();

    (void)UnregisterClassW(mName, BlokGetHandle());

    if (mClass.hIcon)
    {
        (void)DestroyIcon(mClass.hIcon);
    }

    if (mClass.hIconSm)
    {
        (void)DestroyIcon(mClass.hIconSm);
    }

    if (mClass.hCursor)
    {
        (void)DestroyCursor(mClass.hCursor);
    }

    if (mClass.hbrBackground)
    {
        (void)DeleteObject(mClass.hbrBackground);
    }

    if (mWindow)
    {
        (void)DestroyWindow(mWindow);
    }

    return BlokLogAndReturn(
        BlokInformation, BlokCreateResult(BlokSuccess, L"Cleaned Up Window Resources."));
}