@echo off
echo ========================================
echo Quick Rebuild (for code changes only)
echo ========================================

REM Check if build directory exists
if not exist "build" (
    echo Build directory not found!
    echo Please run build.bat first to configure the project.
    pause
    exit /b 1
)

REM Navigate to build directory and rebuild
cd build

echo.
echo Rebuilding project...
cmake --build .

REM Check if build was successful
if %ERRORLEVEL% EQU 0 (
    echo.
    echo Build successful!
    echo ========================================
    echo.
    echo Running the application...
    echo ========================================
    echo.
    nihongo_app.exe
) else (
    echo.
    echo Build failed! Please check the errors above.
)

cd ..
pause
