#pragma once

#include <windows.h>
#include <string>
#include <vector>
#include <memory>

namespace OpenWarp {

    struct AISettings {
        std::wstring apiKey;
        std::wstring defaultModel;
        double temperature;
        int maxTokens;
        bool enableAutoComplete;
        bool enableCommandValidation;
    };

    struct UISettings {
        bool showModeIndicator;
        bool enableKeyboardShortcuts;
        std::wstring theme;
        int fontSize;
        bool enableAnimations;
        std::wstring language;
    };

    struct TerminalSettings {
        std::wstring defaultShell;
        std::wstring workingDirectory;
        bool enableHistory;
        int historySize;
        bool enableAutoSave;
    };

    struct OpenWarpSettings {
        AISettings ai;
        UISettings ui;
        TerminalSettings terminal;
        std::wstring version;
        std::wstring lastUpdateCheck;
    };

    class SettingsManager {
    public:
        SettingsManager();
        ~SettingsManager();

        // Initialization
        bool Initialize();
        void Shutdown();

        // Settings management
        bool LoadSettings();
        bool SaveSettings();
        bool ResetToDefaults();

        // AI Settings
        bool SetAPIKey(const std::wstring& apiKey);
        std::wstring GetAPIKey() const;
        bool IsAPIKeyValid() const;
        bool SetDefaultModel(const std::wstring& modelId);
        std::wstring GetDefaultModel() const;
        void SetAITemperature(double temperature);
        double GetAITemperature() const;
        void SetMaxTokens(int maxTokens);
        int GetMaxTokens() const;

        // UI Settings
        void SetShowModeIndicator(bool show);
        bool GetShowModeIndicator() const;
        void SetEnableKeyboardShortcuts(bool enable);
        bool GetEnableKeyboardShortcuts() const;
        void SetTheme(const std::wstring& theme);
        std::wstring GetTheme() const;
        void SetFontSize(int size);
        int GetFontSize() const;

        // Terminal Settings
        void SetDefaultShell(const std::wstring& shell);
        std::wstring GetDefaultShell() const;
        void SetWorkingDirectory(const std::wstring& directory);
        std::wstring GetWorkingDirectory() const;
        void SetEnableHistory(bool enable);
        bool GetEnableHistory() const;
        void SetHistorySize(int size);
        int GetHistorySize() const;

        // Security
        bool EncryptAPIKey(const std::wstring& apiKey);
        std::wstring DecryptAPIKey() const;
        bool StoreAPIKeySecurely(const std::wstring& apiKey);
        std::wstring RetrieveAPIKeySecurely() const;

        // Validation
        bool ValidateSettings() const;
        std::vector<std::wstring> GetValidationErrors() const;

        // Access to all settings
        OpenWarpSettings GetAllSettings() const;
        void SetAllSettings(const OpenWarpSettings& settings);

    private:
        // Private implementation
        class Impl;
        std::unique_ptr<Impl> pImpl;

        // Internal methods
        bool LoadSettingsFromFile();
        bool SaveSettingsToFile();
        bool LoadSettingsFromRegistry();
        bool SaveSettingsToRegistry();
        std::wstring GetSettingsFilePath() const;
        std::wstring GetRegistryKeyPath() const;
        bool ValidateAPIKey(const std::wstring& apiKey) const;
        bool ValidateModelId(const std::wstring& modelId) const;
    };

} // namespace OpenWarp
