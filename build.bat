@echo off
:: Chuyen sang bang ma UTF-8 de hien thi tieng Viet co dau
chcp 65001 > nul


echo ========================================
echo はじめます
echo ========================================

REM Tao thu muc build neu chua ton tai
if not exist "build" mkdir build

REM Di chuyen vao thu muc build
cd build

REM Chay CMake de tao cac file build
echo.
echo [1/3] Đang cấu hình với CMake
cmake -G "MinGW Makefiles" ..

REM Bien dich du an
echo.
echo [2/3] Đang biên dịch dự án...
cmake --build .

REM Kiem tra xem build co thanh cong hay khong
if %ERRORLEVEL% EQU 0 (
    echo.
    echo [3/3] Biên dịch thành công!
    echo ========================================
    echo.
    echo Đang khởi chạy ứng dụng...
    echo ========================================
    echo.
    nihongo_app.exe
) else (
    echo.
    echo Biên dịch thất bại! Vui lòng kiểm tra các lỗi phía trên.
)

cd ..
pause