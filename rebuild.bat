@echo off
:: Chuyen sang bang ma UTF-8 de hien thi tieng Viet co dau
chcp 65001 > nul

echo ========================================
echo Tái biên dịch nhanh (Chỉ cập nhật thay đổi code)
echo ========================================

REM Kiểm tra xem thư mục build có tồn tại không
if not exist "build" (
    echo Không tìm thấy thư mục build!
    echo Vui lòng chạy file build.bat trước để cấu hình dự án.
    pause
    exit /b 1
)

REM Di chuyển vào thư mục build và tiến hành biên dịch lại
cd build

echo.
echo Đang tái biên dịch dự án...
cmake --build .

REM Kiểm tra kết quả biên dịch
if %ERRORLEVEL% EQU 0 (
    echo.
    echo Biên dịch thành công!
    echo ========================================
    echo.
    echo Đang khởi chạy ứng dụng...
    echo ========================================
    echo.
    nihongo_app.exe
) else (
    echo.
    echo Biên dịch thất bại! Vui lòng kiểm tra các lỗi ở trên.
)

cd ..
pause