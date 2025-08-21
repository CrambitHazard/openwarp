#pragma once

#include <windows.h>
#include <string>
#include <vector>
#include <memory>
#include <functional>

namespace OpenWarp {

    struct AIModel {
        std::wstring id;
        std::wstring name;
        std::wstring provider;
        bool isFree;
        double costPerInput;
        double costPerOutput;
    };

    struct AIRequest {
        std::wstring prompt;
        std::wstring modelId;
        double temperature;
        int maxTokens;
        std::vector<std::wstring> stopSequences;
    };

    struct AIResponse {
        std::wstring content;
        std::wstring modelId;
        int tokensUsed;
        double cost;
        bool success;
        std::wstring errorMessage;
    };

    class OpenRouterClient {
    public:
        OpenRouterClient();
        ~OpenRouterClient();

        // API key management
        bool SetAPIKey(const std::wstring& apiKey);
        bool IsAPIKeyValid() const;
        std::wstring GetAPIKey() const;

        // Model management
        std::vector<AIModel> GetAvailableModels();
        AIModel GetDefaultModel() const;
        bool SetDefaultModel(const std::wstring& modelId);

        // API calls
        AIResponse SendRequest(const AIRequest& request);
        AIResponse SendRequestAsync(const AIRequest& request, 
                                  std::function<void(const AIResponse&)> callback);

        // Command generation
        std::wstring GenerateCommand(const std::wstring& naturalLanguage);
        std::vector<std::wstring> GeneratePlan(const std::wstring& task);

        // Error handling
        std::wstring GetLastError() const;
        void ClearLastError();

    private:
        // Private implementation
        class Impl;
        std::unique_ptr<Impl> pImpl;

        // Internal methods
        bool InitializeHTTPClient();
        std::wstring BuildRequestURL() const;
        std::wstring SerializeRequest(const AIRequest& request) const;
        AIResponse ParseResponse(const std::wstring& response) const;
        bool ValidateResponse(const std::wstring& response) const;
    };

} // namespace OpenWarp
