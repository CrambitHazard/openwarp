#include <windows.h>
#include <iostream>
#include <memory>
#include "core/OpenWarpApp.h"

using namespace OpenWarp;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Initialize COM for Windows
    HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    if (FAILED(hr)) {
        MessageBoxW(nullptr, L"Failed to initialize COM", L"OpenWarp Error", MB_OK | MB_ICONERROR);
        return -1;
    }

    try {
        // Create and initialize the OpenWarp application
        auto app = std::make_unique<OpenWarpApp>();
        
        if (!app->Initialize()) {
            MessageBoxW(nullptr, L"Failed to initialize OpenWarp", L"OpenWarp Error", MB_OK | MB_ICONERROR);
            CoUninitialize();
            return -1;
        }

        // Run the application
        int result = app->Run();
        
        // Cleanup
        app->Shutdown();
        
        CoUninitialize();
        return result;
    }
    catch (const std::exception& e) {
        std::wstring errorMsg = L"Unhandled exception: ";
        errorMsg += std::wstring(e.what(), e.what() + strlen(e.what()));
        MessageBoxW(nullptr, errorMsg.c_str(), L"OpenWarp Error", MB_OK | MB_ICONERROR);
        CoUninitialize();
        return -1;
    }
    catch (...) {
        MessageBoxW(nullptr, L"Unknown error occurred", L"OpenWarp Error", MB_OK | MB_ICONERROR);
        CoUninitialize();
        return -1;
    }
}

// Console entry point for debugging
int main(int argc, char* argv[]) {
    return WinMain(GetModuleHandle(nullptr), nullptr, nullptr, SW_SHOW);
}
