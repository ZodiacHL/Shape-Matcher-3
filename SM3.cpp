#include <iostream>
#include <windows.h>

// Function to handle window messages
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int main() {
    // Register the window class
    const wchar_t CLASS_NAME[] = L"SampleWindowClass";  // Wide string

    WNDCLASSW wc = {};  // Use WNDCLASSW for Unicode
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.style = CS_HREDRAW | CS_VREDRAW;

    if (!RegisterClassW(&wc)) {
        std::cerr << "Failed to register window class!\n";
        return 1;
    }

    // Create the window
    HWND hwnd = CreateWindowExW(
        0,                              // Optional window styles
        CLASS_NAME,                     // Window class (wide string)
        L"Learn to Program Windows",    // Window title (wide string)
        WS_OVERLAPPEDWINDOW,            // Window style
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, // Size and position
        nullptr,                        // Parent window
        nullptr,                        // Menu
        GetModuleHandle(nullptr),       // Instance handle
        nullptr                         // Additional application data
    );

    if (!hwnd) {
        std::cerr << "Failed to create window!\n";
        return 1;
    }

    ShowWindow(hwnd, SW_SHOWDEFAULT);
    UpdateWindow(hwnd);

    // Message loop
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}