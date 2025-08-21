#include "ModeSwitcher.h"
#include <iostream>

namespace OpenWarp {

    class ModeSwitcher::Impl {
    public:
        HWND parentWindow = nullptr;
        UIMode currentMode = UIMode::Shell;
        ModeSwitcherConfig config;
        std::function<void(UIMode)> modeChangeCallback;
        std::function<void(const std::wstring&)> modeIndicatorCallback;
        bool isInitialized = false;
    };

    ModeSwitcher::ModeSwitcher() : pImpl(std::make_unique<Impl>()) {
        // Set default configuration
        pImpl->config.showModeIndicator = true;
        pImpl->config.enableKeyboardShortcuts = true;
        pImpl->config.shellModeText = L"Shell";
        pImpl->config.agentModeText = L"Agent";
        pImpl->config.planModeText = L"Plan";
        pImpl->config.shellModeShortcut = VK_F1;
        pImpl->config.agentModeShortcut = VK_F2;
        pImpl->config.planModeShortcut = VK_F3;
    }

    ModeSwitcher::~ModeSwitcher() = default;

    bool ModeSwitcher::Initialize(HWND parentWindow, const ModeSwitcherConfig& config) {
        if (pImpl->isInitialized) {
            return true;
        }

        pImpl->parentWindow = parentWindow;
        pImpl->config = config;
        pImpl->isInitialized = true;

        return true;
    }

    void ModeSwitcher::Shutdown() {
        if (pImpl->isInitialized) {
            pImpl->isInitialized = false;
            pImpl->parentWindow = nullptr;
        }
    }

    void ModeSwitcher::SetCurrentMode(UIMode mode) {
        if (pImpl->currentMode != mode) {
            pImpl->currentMode = mode;
            NotifyModeChange(mode);
            UpdateDisplay();
        }
    }

    UIMode ModeSwitcher::GetCurrentMode() const {
        return pImpl->currentMode;
    }

    void ModeSwitcher::SwitchToNextMode() {
        UIMode nextMode;
        switch (pImpl->currentMode) {
            case UIMode::Shell:
                nextMode = UIMode::Agent;
                break;
            case UIMode::Agent:
                nextMode = UIMode::Plan;
                break;
            case UIMode::Plan:
                nextMode = UIMode::Shell;
                break;
            default:
                nextMode = UIMode::Shell;
                break;
        }
        SetCurrentMode(nextMode);
    }

    void ModeSwitcher::SwitchToPreviousMode() {
        UIMode prevMode;
        switch (pImpl->currentMode) {
            case UIMode::Shell:
                prevMode = UIMode::Plan;
                break;
            case UIMode::Agent:
                prevMode = UIMode::Shell;
                break;
            case UIMode::Plan:
                prevMode = UIMode::Agent;
                break;
            default:
                prevMode = UIMode::Shell;
                break;
        }
        SetCurrentMode(prevMode);
    }

    void ModeSwitcher::UpdateDisplay() {
        if (pImpl->config.showModeIndicator && pImpl->modeIndicatorCallback) {
            std::wstring modeText = GetModeDisplayText(pImpl->currentMode);
            pImpl->modeIndicatorCallback(modeText);
        }
    }

    void ModeSwitcher::ShowModeIndicator(bool show) {
        pImpl->config.showModeIndicator = show;
        if (show) {
            UpdateDisplay();
        }
    }

    void ModeSwitcher::SetModeText(UIMode mode, const std::wstring& text) {
        switch (mode) {
            case UIMode::Shell:
                pImpl->config.shellModeText = text;
                break;
            case UIMode::Agent:
                pImpl->config.agentModeText = text;
                break;
            case UIMode::Plan:
                pImpl->config.planModeText = text;
                break;
        }
    }

    void ModeSwitcher::OnKeyDown(WPARAM keyCode, LPARAM flags) {
        if (!pImpl->config.enableKeyboardShortcuts) {
            return;
        }

        HandleKeyboardShortcut(keyCode);
    }

    void ModeSwitcher::OnMouseClick(int x, int y) {
        // TODO: Implement mouse click handling for mode switching
    }

    void ModeSwitcher::OnPaint(HDC hdc) {
        if (pImpl->config.showModeIndicator) {
            DrawModeIndicator(hdc);
        }
    }

    void ModeSwitcher::SetModeChangeCallback(std::function<void(UIMode)> callback) {
        pImpl->modeChangeCallback = callback;
    }

    void ModeSwitcher::SetModeIndicatorCallback(std::function<void(const std::wstring&)> callback) {
        pImpl->modeIndicatorCallback = callback;
    }

    void ModeSwitcher::SetConfig(const ModeSwitcherConfig& config) {
        pImpl->config = config;
    }

    ModeSwitcherConfig ModeSwitcher::GetConfig() const {
        return pImpl->config;
    }

    void ModeSwitcher::DrawModeIndicator(HDC hdc) {
        // TODO: Implement mode indicator drawing
    }

    void ModeSwitcher::HandleKeyboardShortcut(WPARAM keyCode) {
        if (keyCode == pImpl->config.shellModeShortcut) {
            SetCurrentMode(UIMode::Shell);
        } else if (keyCode == pImpl->config.agentModeShortcut) {
            SetCurrentMode(UIMode::Agent);
        } else if (keyCode == pImpl->config.planModeShortcut) {
            SetCurrentMode(UIMode::Plan);
        }
    }

    std::wstring ModeSwitcher::GetModeDisplayText(UIMode mode) const {
        switch (mode) {
            case UIMode::Shell:
                return pImpl->config.shellModeText;
            case UIMode::Agent:
                return pImpl->config.agentModeText;
            case UIMode::Plan:
                return pImpl->config.planModeText;
            default:
                return L"Unknown";
        }
    }

    void ModeSwitcher::NotifyModeChange(UIMode newMode) {
        if (pImpl->modeChangeCallback) {
            pImpl->modeChangeCallback(newMode);
        }
    }

} // namespace OpenWarp
