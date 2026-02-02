@echo off
echo ========================================
echo Building Nihongo App with CMake + G++
echo ========================================

REM Create build directory if it doesn't exist
if not exist "build" mkdir build

REM Navigate to build directory
cd build

REM Run CMake to generate build files
echo.
echo [1/3] Configuring with CMake...
cmake -G "MinGW Makefiles" ..

REM Build the project
echo.
echo [2/3] Building project...
cmake --build .

REM Check if build was successful
if %ERRORLEVEL% EQU 0 (
    echo.
    echo [3/3] Build successful!
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
