#include "OpenRouterClient.h"
#include <iostream>

namespace OpenWarp {

    class OpenRouterClient::Impl {
    public:
        std::wstring apiKey;
        std::wstring defaultModel = L"deepseek/deepseek-r1-0528:free";
        std::wstring lastError;
        bool isInitialized = false;
    };

    OpenRouterClient::OpenRouterClient() : pImpl(std::make_unique<Impl>()) {
    }

    OpenRouterClient::~OpenRouterClient() = default;

    bool OpenRouterClient::SetAPIKey(const std::wstring& apiKey) {
        pImpl->apiKey = apiKey;
        return !apiKey.empty();
    }

    bool OpenRouterClient::IsAPIKeyValid() const {
        return !pImpl->apiKey.empty();
    }

    std::wstring OpenRouterClient::GetAPIKey() const {
        return pImpl->apiKey;
    }

    std::vector<AIModel> OpenRouterClient::GetAvailableModels() {
        // TODO: Implement API call to get available models
        std::vector<AIModel> models;
        
        // Add default model
        AIModel defaultModel;
        defaultModel.id = L"deepseek/deepseek-r1-0528:free";
        defaultModel.name = L"DeepSeek RI 0528 (Free)";
        defaultModel.provider = L"DeepSeek";
        defaultModel.isFree = true;
        defaultModel.costPerInput = 0.0;
        defaultModel.costPerOutput = 0.0;
        models.push_back(defaultModel);
        
        return models;
    }

    AIModel OpenRouterClient::GetDefaultModel() const {
        AIModel model;
        model.id = pImpl->defaultModel;
        model.name = L"DeepSeek RI 0528 (Free)";
        model.provider = L"DeepSeek";
        model.isFree = true;
        model.costPerInput = 0.0;
        model.costPerOutput = 0.0;
        return model;
    }

    bool OpenRouterClient::SetDefaultModel(const std::wstring& modelId) {
        pImpl->defaultModel = modelId;
        return true;
    }

    AIResponse OpenRouterClient::SendRequest(const AIRequest& request) {
        // TODO: Implement actual API call
        AIResponse response;
        response.success = false;
        response.errorMessage = L"OpenRouter API not implemented yet";
        return response;
    }

    AIResponse OpenRouterClient::SendRequestAsync(const AIRequest& request, 
                                                 std::function<void(const AIResponse&)> callback) {
        // TODO: Implement async API call
        AIResponse response;
        response.success = false;
        response.errorMessage = L"Async OpenRouter API not implemented yet";
        
        if (callback) {
            callback(response);
        }
        
        return response;
    }

    std::wstring OpenRouterClient::GenerateCommand(const std::wstring& naturalLanguage) {
        // TODO: Implement command generation
        return L"# Command generation not implemented yet\n# Input: " + naturalLanguage;
    }

    std::vector<std::wstring> OpenRouterClient::GeneratePlan(const std::wstring& task) {
        // TODO: Implement plan generation
        std::vector<std::wstring> plan;
        plan.push_back(L"# Plan generation not implemented yet");
        plan.push_back(L"# Task: " + task);
        return plan;
    }

    std::wstring OpenRouterClient::GetLastError() const {
        return pImpl->lastError;
    }

    void OpenRouterClient::ClearLastError() {
        pImpl->lastError.clear();
    }

    bool OpenRouterClient::InitializeHTTPClient() {
        // TODO: Initialize HTTP client
        return false;
    }

    std::wstring OpenRouterClient::BuildRequestURL() const {
        return L"https://openrouter.ai/api/v1/chat/completions";
    }

    std::wstring OpenRouterClient::SerializeRequest(const AIRequest& request) const {
        // TODO: Implement JSON serialization
        return L"{}";
    }

    AIResponse OpenRouterClient::ParseResponse(const std::wstring& response) const {
        // TODO: Implement JSON parsing
        AIResponse result;
        result.success = false;
        result.errorMessage = L"Response parsing not implemented";
        return result;
    }

    bool OpenRouterClient::ValidateResponse(const std::wstring& response) const {
        // TODO: Implement response validation
        return false;
    }

} // namespace OpenWarp
