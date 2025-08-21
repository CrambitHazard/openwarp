#include "SettingsManager.h"
#include <iostream>

namespace OpenWarp {

    class SettingsManager::Impl {
    public:
        OpenWarpSettings settings;
        bool isInitialized = false;
        std::vector<std::wstring> validationErrors;
    };

    SettingsManager::SettingsManager() : pImpl(std::make_unique<Impl>()) {
        // Set default settings
        pImpl->settings.version = L"1.0.0";
        pImpl->settings.ai.defaultModel = L"deepseek/deepseek-r1-0528:free";
        pImpl->settings.ai.temperature = 0.7;
        pImpl->settings.ai.maxTokens = 2048;
        pImpl->settings.ai.enableAutoComplete = true;
        pImpl->settings.ai.enableCommandValidation = true;
        
        pImpl->settings.ui.showModeIndicator = true;
        pImpl->settings.ui.enableKeyboardShortcuts = true;
        pImpl->settings.ui.theme = L"default";
        pImpl->settings.ui.fontSize = 12;
        pImpl->settings.ui.enableAnimations = true;
        pImpl->settings.ui.language = L"en-US";
        
        pImpl->settings.terminal.defaultShell = L"powershell.exe";
        pImpl->settings.terminal.workingDirectory = L"";
        pImpl->settings.terminal.enableHistory = true;
        pImpl->settings.terminal.historySize = 1000;
        pImpl->settings.terminal.enableAutoSave = true;
    }

    SettingsManager::~SettingsManager() = default;

    bool SettingsManager::Initialize() {
        if (pImpl->isInitialized) {
            return true;
        }

        if (!LoadSettings()) {
            // If loading fails, use defaults
            ResetToDefaults();
        }

        pImpl->isInitialized = true;
        return true;
    }

    void SettingsManager::Shutdown() {
        if (pImpl->isInitialized) {
            SaveSettings();
            pImpl->isInitialized = false;
        }
    }

    bool SettingsManager::LoadSettings() {
        // TODO: Implement settings loading from file/registry
        return false; // Not implemented yet
    }

    bool SettingsManager::SaveSettings() {
        // TODO: Implement settings saving to file/registry
        return true; // Placeholder
    }

    bool SettingsManager::ResetToDefaults() {
        // Reset to constructor defaults
        pImpl->settings.ai.apiKey.clear();
        pImpl->settings.ai.defaultModel = L"deepseek/deepseek-r1-0528:free";
        pImpl->settings.ai.temperature = 0.7;
        pImpl->settings.ai.maxTokens = 2048;
        pImpl->settings.ai.enableAutoComplete = true;
        pImpl->settings.ai.enableCommandValidation = true;
        
        pImpl->settings.ui.showModeIndicator = true;
        pImpl->settings.ui.enableKeyboardShortcuts = true;
        pImpl->settings.ui.theme = L"default";
        pImpl->settings.ui.fontSize = 12;
        pImpl->settings.ui.enableAnimations = true;
        pImpl->settings.ui.language = L"en-US";
        
        pImpl->settings.terminal.defaultShell = L"powershell.exe";
        pImpl->settings.terminal.workingDirectory = L"";
        pImpl->settings.terminal.enableHistory = true;
        pImpl->settings.terminal.historySize = 1000;
        pImpl->settings.terminal.enableAutoSave = true;
        
        return true;
    }

    bool SettingsManager::SetAPIKey(const std::wstring& apiKey) {
        if (ValidateAPIKey(apiKey)) {
            pImpl->settings.ai.apiKey = apiKey;
            return true;
        }
        return false;
    }

    std::wstring SettingsManager::GetAPIKey() const {
        return pImpl->settings.ai.apiKey;
    }

    bool SettingsManager::IsAPIKeyValid() const {
        return ValidateAPIKey(pImpl->settings.ai.apiKey);
    }

    bool SettingsManager::SetDefaultModel(const std::wstring& modelId) {
        if (ValidateModelId(modelId)) {
            pImpl->settings.ai.defaultModel = modelId;
            return true;
        }
        return false;
    }

    std::wstring SettingsManager::GetDefaultModel() const {
        return pImpl->settings.ai.defaultModel;
    }

    void SettingsManager::SetAITemperature(double temperature) {
        pImpl->settings.ai.temperature = temperature;
    }

    double SettingsManager::GetAITemperature() const {
        return pImpl->settings.ai.temperature;
    }

    void SettingsManager::SetMaxTokens(int maxTokens) {
        pImpl->settings.ai.maxTokens = maxTokens;
    }

    int SettingsManager::GetMaxTokens() const {
        return pImpl->settings.ai.maxTokens;
    }

    void SettingsManager::SetShowModeIndicator(bool show) {
        pImpl->settings.ui.showModeIndicator = show;
    }

    bool SettingsManager::GetShowModeIndicator() const {
        return pImpl->settings.ui.showModeIndicator;
    }

    void SettingsManager::SetEnableKeyboardShortcuts(bool enable) {
        pImpl->settings.ui.enableKeyboardShortcuts = enable;
    }

    bool SettingsManager::GetEnableKeyboardShortcuts() const {
        return pImpl->settings.ui.enableKeyboardShortcuts;
    }

    void SettingsManager::SetTheme(const std::wstring& theme) {
        pImpl->settings.ui.theme = theme;
    }

    std::wstring SettingsManager::GetTheme() const {
        return pImpl->settings.ui.theme;
    }

    void SettingsManager::SetFontSize(int size) {
        pImpl->settings.ui.fontSize = size;
    }

    int SettingsManager::GetFontSize() const {
        return pImpl->settings.ui.fontSize;
    }

    void SettingsManager::SetDefaultShell(const std::wstring& shell) {
        pImpl->settings.terminal.defaultShell = shell;
    }

    std::wstring SettingsManager::GetDefaultShell() const {
        return pImpl->settings.terminal.defaultShell;
    }

    void SettingsManager::SetWorkingDirectory(const std::wstring& directory) {
        pImpl->settings.terminal.workingDirectory = directory;
    }

    std::wstring SettingsManager::GetWorkingDirectory() const {
        return pImpl->settings.terminal.workingDirectory;
    }

    void SettingsManager::SetEnableHistory(bool enable) {
        pImpl->settings.terminal.enableHistory = enable;
    }

    bool SettingsManager::GetEnableHistory() const {
        return pImpl->settings.terminal.enableHistory;
    }

    void SettingsManager::SetHistorySize(int size) {
        pImpl->settings.terminal.historySize = size;
    }

    int SettingsManager::GetHistorySize() const {
        return pImpl->settings.terminal.historySize;
    }

    bool SettingsManager::EncryptAPIKey(const std::wstring& apiKey) {
        // TODO: Implement API key encryption using Windows DPAPI
        return false;
    }

    std::wstring SettingsManager::DecryptAPIKey() const {
        // TODO: Implement API key decryption using Windows DPAPI
        return L"";
    }

    bool SettingsManager::StoreAPIKeySecurely(const std::wstring& apiKey) {
        // TODO: Implement secure API key storage using Windows Credential Manager
        return false;
    }

    std::wstring SettingsManager::RetrieveAPIKeySecurely() const {
        // TODO: Implement secure API key retrieval using Windows Credential Manager
        return L"";
    }

    bool SettingsManager::ValidateSettings() const {
        pImpl->validationErrors.clear();
        
        if (!ValidateAPIKey(pImpl->settings.ai.apiKey)) {
            pImpl->validationErrors.push_back(L"Invalid API key");
        }
        
        if (!ValidateModelId(pImpl->settings.ai.defaultModel)) {
            pImpl->validationErrors.push_back(L"Invalid model ID");
        }
        
        return pImpl->validationErrors.empty();
    }

    std::vector<std::wstring> SettingsManager::GetValidationErrors() const {
        return pImpl->validationErrors;
    }

    OpenWarpSettings SettingsManager::GetAllSettings() const {
        return pImpl->settings;
    }

    void SettingsManager::SetAllSettings(const OpenWarpSettings& settings) {
        pImpl->settings = settings;
    }

    bool SettingsManager::LoadSettingsFromFile() {
        // TODO: Implement file-based settings loading
        return false;
    }

    bool SettingsManager::SaveSettingsToFile() {
        // TODO: Implement file-based settings saving
        return false;
    }

    bool SettingsManager::LoadSettingsFromRegistry() {
        // TODO: Implement registry-based settings loading
        return false;
    }

    bool SettingsManager::SaveSettingsToRegistry() {
        // TODO: Implement registry-based settings saving
        return false;
    }

    std::wstring SettingsManager::GetSettingsFilePath() const {
        // TODO: Return proper settings file path
        return L"";
    }

    std::wstring SettingsManager::GetRegistryKeyPath() const {
        return L"SOFTWARE\\OpenWarp";
    }

    bool SettingsManager::ValidateAPIKey(const std::wstring& apiKey) const {
        // TODO: Implement proper API key validation
        return !apiKey.empty() && apiKey.length() > 10;
    }

    bool SettingsManager::ValidateModelId(const std::wstring& modelId) const {
        // TODO: Implement proper model ID validation
        return !modelId.empty() && modelId.find(L"/") != std::wstring::npos;
    }

} // namespace OpenWarp
