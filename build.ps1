# simple windows build script that i wrote in like 2 minutes
# definitely could be improved but it works good enough

$errorOccurred = $false

if (Test-Path "build") {
    Write-Host "Would you like to remove the existing build directory? (y/n)"
    $choice = (Read-Host).Trim().ToLower()
    if ($choice -eq "y") {
        Remove-Item -Recurse -Force "build"
    } elseif ($choice -eq "n") {
        Write-Host "Exiting..."
        exit
    }
}

New-Item -ItemType Directory -Path "build" -ErrorAction SilentlyContinue | Out-Null

Push-Location "build"

try {
    $env:PATH = "C:\Qt\Tools\mingw1310_64\bin;C:\Qt\Tools\CMake_64\bin;C:\Qt\Tools\Ninja;$env:PATH"

    cmake -G "MinGW Makefiles" ..

    mingw32-make
} catch {
    Write-Host -ForegroundColor Red "An unexpected error occurred during the build process: $_"
    $errorOccurred = $true
}
finally {
    Pop-Location
    if ($errorOccurred) {
        exit 1
    } else {
        exit 0
    }
}
