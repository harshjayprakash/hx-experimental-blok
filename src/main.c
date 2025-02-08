#include <Windows.h>

int WINAPI wWinMain(
    HINSTANCE hInstance, 
    HINSTANCE hPrevInstance, 
    LPWSTR lpCmdLine, 
    int nShowCmd)
{
    (void) MessageBoxW(0, L"Hello, world!", L"Test", MB_OK | MB_ICONINFORMATION);

    return 0;
}