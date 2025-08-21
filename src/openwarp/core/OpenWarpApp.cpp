#include "OpenWarpApp.h"
#include <iostream>

namespace OpenWarp {

    class OpenWarpApp::Impl {
    public:
        TerminalMode currentMode = TerminalMode::Shell;
        bool isInitialized = false;
        bool aiAvailable = false;
        std::wstring currentAIModel = L"deepseek/deepseek-r1-0528:free";
    };

    OpenWarpApp::OpenWarpApp() : pImpl(std::make_unique<Impl>()) {
    }

    OpenWarpApp::~OpenWarpApp() = default;

    bool OpenWarpApp::Initialize() {
        if (pImpl->isInitialized) {
            return true;
        }

        // Initialize terminal
        if (!InitializeTerminal()) {
            return false;
        }

        // Initialize AI
        if (!InitializeAI()) {
            // AI initialization failure is not critical
            pImpl->aiAvailable = false;
        } else {
            pImpl->aiAvailable = true;
        }

        // Initialize UI
        if (!InitializeUI()) {
            return false;
        }

        pImpl->isInitialized = true;
        return true;
    }

    int OpenWarpApp::Run() {
        if (!pImpl->isInitialized) {
            return -1;
        }

        // For now, just show a message that OpenWarp is running
        MessageBoxW(nullptr, L"OpenWarp is running!\n\nThis is a placeholder implementation.\n\nFeatures coming soon:\n- Agent Mode\n- Plan Mode\n- OpenRouter Integration", 
                   L"OpenWarp", MB_OK | MB_ICONINFORMATION);
        
        return 0;
    }

    void OpenWarpApp::Shutdown() {
        if (pImpl->isInitialized) {
            pImpl->isInitialized = false;
        }
    }

    void OpenWarpApp::SwitchMode(TerminalMode mode) {
        pImpl->currentMode = mode;
    }

    TerminalMode OpenWarpApp::GetCurrentMode() const {
        return pImpl->currentMode;
    }

    bool OpenWarpApp::LoadSettings() {
        // TODO: Implement settings loading
        return true;
    }

    bool OpenWarpApp::SaveSettings() {
        // TODO: Implement settings saving
        return true;
    }

    bool OpenWarpApp::IsAIAvailable() const {
        return pImpl->aiAvailable;
    }

    void OpenWarpApp::SetAIModel(const std::wstring& modelName) {
        pImpl->currentAIModel = modelName;
    }

    bool OpenWarpApp::InitializeTerminal() {
        // TODO: Initialize Microsoft Terminal integration
        return true;
    }

    bool OpenWarpApp::InitializeAI() {
        // TODO: Initialize OpenRouter client
        return false; // Not implemented yet
    }

    bool OpenWarpApp::InitializeUI() {
        // TODO: Initialize UI components
        return true;
    }

} // namespace OpenWarp
