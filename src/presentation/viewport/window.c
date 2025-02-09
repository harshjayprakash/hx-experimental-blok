#include "window.h"

static LRESULT CALLBACK BlokWindowProcedure(
    HWND windowHandle, UINT messageId, WPARAM infoWord, LPARAM infoLong)
{
    switch (messageId)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return TRUE;
    default:
        return DefWindowProcW(windowHandle, messageId, infoWord, infoLong);
    }
}

void BlokWindowInit(Window *window, HINSTANCE instanceHandle)
{
    if (!window) { return; }
    if (!instanceHandle) { return; }

    window->klassName = L"BlokViewport";
    window->caption = L"Blok 25H2.1";

    window->klass.cbSize = sizeof(WNDCLASSEXW);
    window->klass.style = CS_HREDRAW | CS_VREDRAW;
    window->klass.lpfnWndProc = BlokWindowProcedure;
    window->klass.cbClsExtra = 0;
    window->klass.cbWndExtra = 0;
    window->klass.hInstance = instanceHandle;
    window->klass.hIcon = LoadIconW(instanceHandle, IDI_APPLICATION);
    window->klass.hCursor = LoadCursor(NULL, IDC_ARROW);
    window->klass.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
    window->klass.lpszMenuName = NULL;
    window->klass.lpszClassName = window->klassName;
    window->klass.hIconSm = LoadIconW(instanceHandle, IDI_APPLICATION);

    window->klassAtomRef = RegisterClassExW(&window->klass);

    if (window->klassAtomRef == 0)
    {
        (void) MessageBoxW(
            NULL, L"Window Class Registration Failed.", L"Blok", MB_OK | MB_ICONERROR);
        BlokWindowFree(window, instanceHandle);
        return;
    }

    window->handle = CreateWindowExW(
        0L, window->klassName, window->caption, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 
        CW_USEDEFAULT, 800, 600, NULL, NULL, instanceHandle, NULL);
    
    if (!window->handle)
    {
        (void) MessageBoxW(
            NULL, L"Window Creation Failed.", L"Blok", MB_OK | MB_ICONERROR);
        BlokWindowFree(window, instanceHandle);
        return;
    }
}

void BlokWindowShow(Window *window, DWORD showFlag)
{
    if (!window) { return; }
    if (!window->handle) { return; }

    (void) ShowWindow(window->handle, showFlag);

    MSG message = {0};

    for (;;)
    {
        if (PeekMessageW(&message, NULL, 0, 0, PM_REMOVE) > 0) 
        {
            (void) TranslateMessage(&message);
            (void) DispatchMessageW(&message);

            if (message.message == WM_QUIT) { break; }
        }

        (void) UpdateWindow(window->handle);

        Sleep(1);
    }
}

void BlokWindowFree(Window *window, HINSTANCE instanceHandle)
{
    if (!window) { return; }
    if (!instanceHandle) { return; }

    if (window->handle != NULL) 
    { 
        (void) DestroyWindow(window->handle);
    }

    if (window->klass.hIcon != NULL) 
    { 
        (void) DestroyIcon(window->klass.hIcon);
    }

    if (window->klass.hIconSm != NULL) 
    { 
        (void) DestroyIcon(window->klass.hIconSm);
    }

    if (window->klass.hCursor != NULL) 
    { 
        (void) DestroyCursor(window->klass.hCursor);
    }

    if (window->klass.hbrBackground != NULL) 
    { 
        (void) DeleteObject(window->klass.hbrBackground);
    }

    if (window->klassAtomRef != 0) 
    { 
        (void) UnregisterClassW(window->klassName, instanceHandle);
    }
}