# OpenWarp Build Script
# This script builds the OpenWarp project using MSBuild

param(
    [string]$Configuration = "Debug",
    [string]$Platform = "x64",
    [switch]$Clean,
    [switch]$Help
)

if ($Help) {
    Write-Host "OpenWarp Build Script"
    Write-Host "Usage: .\build.ps1 [-Configuration Debug|Release] [-Platform x64|x86] [-Clean] [-Help]"
    Write-Host ""
    Write-Host "Parameters:"
    Write-Host "  -Configuration: Build configuration (Debug or Release, default: Debug)"
    Write-Host "  -Platform: Target platform (x64 or x86, default: x64)"
    Write-Host "  -Clean: Clean build before building"
    Write-Host "  -Help: Show this help message"
    exit 0
}

# Validate parameters
if ($Configuration -notin @("Debug", "Release")) {
    Write-Error "Invalid configuration: $Configuration. Use Debug or Release."
    exit 1
}

if ($Platform -notin @("x64", "x86")) {
    Write-Error "Invalid platform: $Platform. Use x64 or x86."
    exit 1
}

Write-Host "Building OpenWarp..." -ForegroundColor Green
Write-Host "Configuration: $Configuration" -ForegroundColor Yellow
Write-Host "Platform: $Platform" -ForegroundColor Yellow
Write-Host ""

# Set platform for MSBuild
$MSBuildPlatform = if ($Platform -eq "x86") { "Win32" } else { $Platform }

# Find MSBuild
$MSBuildPath = $null
$VSInstallPath = $null

# Try to find Visual Studio 2022
$VS2022Path = "${env:ProgramFiles}\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\MSBuild.exe"
if (Test-Path $VS2022Path) {
    $MSBuildPath = $VS2022Path
    $VSInstallPath = "${env:ProgramFiles}\Microsoft Visual Studio\2022\Community"
} else {
    $VS2022Path = "${env:ProgramFiles}\Microsoft Visual Studio\2022\Professional\MSBuild\Current\Bin\MSBuild.exe"
    if (Test-Path $VS2022Path) {
        $MSBuildPath = $VS2022Path
        $VSInstallPath = "${env:ProgramFiles}\Microsoft Visual Studio\2022\Professional"
    } else {
        $VS2022Path = "${env:ProgramFiles}\Microsoft Visual Studio\2022\Enterprise\MSBuild\Current\Bin\MSBuild.exe"
        if (Test-Path $VS2022Path) {
            $MSBuildPath = $VS2022Path
            $VSInstallPath = "${env:ProgramFiles}\Microsoft Visual Studio\2022\Enterprise"
        }
    }
}

if (-not $MSBuildPath) {
    Write-Error "MSBuild not found. Please install Visual Studio 2022 with C++ workloads."
    exit 1
}

Write-Host "Using MSBuild: $MSBuildPath" -ForegroundColor Cyan

# Set up environment
if ($VSInstallPath) {
    $VCVarsPath = "$VSInstallPath\VC\Auxiliary\Build\vcvars64.bat"
    if (Test-Path $VCVarsPath) {
        Write-Host "Setting up Visual Studio environment..." -ForegroundColor Cyan
        & cmd /c "`"$VCVarsPath`" && set" | ForEach-Object {
            if ($_ -match "=") {
                $name, $value = $_.split("=", 2)
                Set-Item -Path "env:$name" -Value $value
            }
        }
    }
}

# Clean if requested
if ($Clean) {
    Write-Host "Cleaning build..." -ForegroundColor Yellow
    & $MSBuildPath "OpenWarp.sln" /t:Clean /p:Configuration=$Configuration /p:Platform=$MSBuildPlatform /verbosity:minimal
    if ($LASTEXITCODE -ne 0) {
        Write-Warning "Clean failed, but continuing with build..."
    }
}

# Build the solution
Write-Host "Building solution..." -ForegroundColor Yellow
& $MSBuildPath "OpenWarp.sln" /p:Configuration=$Configuration /p:Platform=$MSBuildPlatform /verbosity:minimal

if ($LASTEXITCODE -eq 0) {
    Write-Host "Build completed successfully!" -ForegroundColor Green
    
    # Show output location
    $OutputPath = "src\openwarp\$Platform\$Configuration\OpenWarp.exe"
    if (Test-Path $OutputPath) {
        Write-Host "Output: $OutputPath" -ForegroundColor Cyan
        Write-Host "You can run OpenWarp with: .\$OutputPath" -ForegroundColor Cyan
    }
} else {
    Write-Error "Build failed with exit code: $LASTEXITCODE"
    exit $LASTEXITCODE
}
