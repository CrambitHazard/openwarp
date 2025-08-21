#pragma once

#include <windows.h>
#include <string>
#include <functional>
#include <memory>

namespace OpenWarp {

    enum class UIMode {
        Shell,
        Agent,
        Plan
    };

    struct ModeSwitcherConfig {
        bool showModeIndicator;
        bool enableKeyboardShortcuts;
        std::wstring shellModeText;
        std::wstring agentModeText;
        std::wstring planModeText;
        UINT shellModeShortcut;
        UINT agentModeShortcut;
        UINT planModeShortcut;
    };

    class ModeSwitcher {
    public:
        ModeSwitcher();
        ~ModeSwitcher();

        // Initialization
        bool Initialize(HWND parentWindow, const ModeSwitcherConfig& config);
        void Shutdown();

        // Mode management
        void SetCurrentMode(UIMode mode);
        UIMode GetCurrentMode() const;
        void SwitchToNextMode();
        void SwitchToPreviousMode();

        // UI updates
        void UpdateDisplay();
        void ShowModeIndicator(bool show);
        void SetModeText(UIMode mode, const std::wstring& text);

        // Event handling
        void OnKeyDown(WPARAM keyCode, LPARAM flags);
        void OnMouseClick(int x, int y);
        void OnPaint(HDC hdc);

        // Callbacks
        void SetModeChangeCallback(std::function<void(UIMode)> callback);
        void SetModeIndicatorCallback(std::function<void(const std::wstring&)> callback);

        // Configuration
        void SetConfig(const ModeSwitcherConfig& config);
        ModeSwitcherConfig GetConfig() const;

    private:
        // Private implementation
        class Impl;
        std::unique_ptr<Impl> pImpl;

        // Internal methods
        void DrawModeIndicator(HDC hdc);
        void HandleKeyboardShortcut(WPARAM keyCode);
        std::wstring GetModeDisplayText(UIMode mode) const;
        void NotifyModeChange(UIMode newMode);
    };

} // namespace OpenWarp
