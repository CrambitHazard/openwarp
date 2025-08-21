# OpenWarp 🚀

A free, AI-powered terminal application that helps software engineers automate command-line tasks by providing intelligent agent and plan modes, built on Microsoft Terminal's robust foundation.

## 🌟 Features

### 🤖 AI-Powered Modes
- **Agent Mode**: Natural language command execution with AI understanding
- **Plan Mode**: Step-by-step task planning with user editing capabilities
- **Shell Mode**: Traditional terminal experience with full Microsoft Terminal compatibility

### 🔧 Key Capabilities
- **OpenRouter Integration**: Flexible AI model selection with DeepSeek RI 0528:free as default
- **Secure API Management**: Safe storage and management of OpenRouter API keys
- **Multi-Model Support**: Switch between different AI models for different use cases
- **Seamless Mode Switching**: Easy toggle between shell, agent, and plan modes
- **Command History**: Persistent history across all modes with AI context
- **Error Recovery**: Intelligent error handling and suggestion generation

### 🎯 Target Users
- **Software Engineers**: Who want terminal automation but can't afford premium solutions
- **DevOps Engineers**: Who need efficient command-line workflows with AI assistance
- **Open Source Contributors**: Who prefer free, community-driven tools

## 🚀 Getting Started

### Prerequisites
- Windows 10/11 (build >= 10.0.19041.0)
- Visual Studio 2022 with C++ workloads
- PowerShell 7 or later
- Developer Mode enabled
- Windows 11 SDK (10.0.22621.0 or later)

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/openwarp.git
   cd openwarp
   ```

2. Open the solution in Visual Studio 2022:
   ```bash
   start OpenWarp.sln
   ```

3. Build the project:
   ```bash
   msbuild OpenWarp.sln /p:Configuration=Release /p:Platform=x64
   ```

4. Run OpenWarp:
   ```bash
   .\x64\Release\OpenWarp.exe
   ```

### Configuration
1. Open OpenWarp
2. Go to Settings (Ctrl+,)
3. Navigate to AI Settings
4. Add your OpenRouter API key
5. Select your preferred AI model (DeepSeek RI 0528:free is default)

## 🎮 Usage

### Shell Mode
Traditional terminal experience - use it like any other terminal application.

### Agent Mode
Switch to Agent Mode and type natural language commands:
```
"Show me all running processes"
"Create a backup of my project folder"
"Install the latest version of Node.js"
```

### Plan Mode
Create and execute step-by-step plans:
```
"Set up a new React project with TypeScript"
```
The AI will create a plan like:
1. Create project directory
2. Initialize npm project
3. Install React and TypeScript dependencies
4. Set up basic project structure
5. Create initial components

You can edit the plan before execution.

## 🛠️ Development

### Project Structure
```
openwarp/
├── src/                    # Source code
│   ├── TerminalApp/       # Main application
│   ├── TerminalCore/      # Core terminal functionality
│   ├── TerminalSettings/  # Settings UI
│   └── AI/               # AI integration layer
├── tools/                # Build tools and scripts
├── doc/                  # Documentation
└── .agent-os/           # Agent OS configuration
```

### Building from Source
```bash
# Import build module
Import-Module .\tools\OpenWarp.psm1

# Set development environment
Set-MsBuildDevEnvironment

# Build the project
Invoke-OpenWarpBuild
```

### Contributing
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 🔒 Security

- API keys are stored securely using Windows Credential Manager
- All sensitive data is encrypted using Windows DPAPI
- No data is sent to external services except OpenRouter API calls
- User commands and AI responses are not logged or stored

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **Microsoft Terminal Team**: For the excellent foundation
- **OpenRouter**: For providing flexible AI model access
- **DeepSeek**: For the free AI model that makes this project possible
- **Open Source Community**: For inspiration and support

## 📞 Support

- **Issues**: [GitHub Issues](https://github.com/your-username/openwarp/issues)
- **Discussions**: [GitHub Discussions](https://github.com/your-username/openwarp/discussions)
- **Documentation**: [Wiki](https://github.com/your-username/openwarp/wiki)

## 🗺️ Roadmap

See our [detailed roadmap](.agent-os/product/roadmap.md) for upcoming features and development phases.

---

**Made with ❤️ for the open source community**
