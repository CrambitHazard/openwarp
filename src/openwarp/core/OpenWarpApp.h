#pragma once

#include <windows.h>
#include <string>
#include <memory>

namespace OpenWarp {

    enum class TerminalMode {
        Shell,      // Traditional terminal mode
        Agent,      // AI-powered command execution
        Plan        // Step-by-step plan execution
    };

    class OpenWarpApp {
    public:
        OpenWarpApp();
        ~OpenWarpApp();

        // Application lifecycle
        bool Initialize();
        int Run();
        void Shutdown();

        // Mode management
        void SwitchMode(TerminalMode mode);
        TerminalMode GetCurrentMode() const;

        // Settings
        bool LoadSettings();
        bool SaveSettings();

        // AI integration
        bool IsAIAvailable() const;
        void SetAIModel(const std::wstring& modelName);

    private:
        // Private implementation
        class Impl;
        std::unique_ptr<Impl> pImpl;

        // Internal methods
        bool InitializeTerminal();
        bool InitializeAI();
        bool InitializeUI();
    };

} // namespace OpenWarp
