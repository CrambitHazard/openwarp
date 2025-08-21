# Technical Stack

## Application Framework
- **Framework:** Microsoft Terminal (C++/C#)
- **Version:** Latest stable release from Microsoft Terminal repository
- **Architecture:** Windows Terminal with custom AI integration layer

## Core Technologies
- **Language:** C++ (92.4%), C# (4.0%), C (1.8%)
- **Build System:** Visual Studio 2022 with MSBuild
- **Package Management:** NuGet, vcpkg

## AI Integration
- **AI Provider:** OpenRouter API
- **Default Model:** DeepSeek RI 0528:free
- **Model Selection:** User-configurable through settings
- **API Management:** Secure key storage and management

## User Interface
- **UI Framework:** Windows Terminal UI (DirectWrite-based)
- **Theming:** Microsoft Terminal theme system
- **Icons:** Windows Terminal icon library
- **Fonts:** Cascadia Code (default), user-configurable

## Development Tools
- **IDE:** Visual Studio 2022
- **Version Control:** Git
- **Code Repository:** GitHub (fork of Microsoft Terminal)
- **CI/CD:** GitHub Actions

## Platform Support
- **Primary:** Windows 10/11
- **Secondary:** Windows Server
- **Future:** macOS, Linux (via cross-platform compilation)

## Dependencies
- **Windows SDK:** 10.0.22621.0 or later
- **PowerShell:** 7.0 or later
- **Developer Mode:** Enabled for local installation
- **Visual Studio Workloads:** Desktop Development with C++, Universal Windows Platform Development

## Security
- **API Key Storage:** Windows Credential Manager
- **Encryption:** Windows DPAPI for sensitive data
- **Authentication:** OpenRouter API key validation

## Deployment
- **Distribution:** Microsoft Store, GitHub Releases
- **Installation:** MSIX package, portable executable
- **Updates:** Microsoft Store updates, GitHub releases

## Testing
- **Unit Testing:** Microsoft Test Framework
- **Integration Testing:** Custom test suite
- **UI Testing:** Windows Terminal test framework

## Documentation
- **API Documentation:** Microsoft Terminal docs + OpenWarp extensions
- **User Guide:** In-app help, GitHub Wiki
- **Developer Guide:** Contributing guidelines, architecture docs
