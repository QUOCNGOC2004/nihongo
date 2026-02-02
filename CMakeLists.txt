# Yêu cầu phiên bản CMake tối thiểu
cmake_minimum_required(VERSION 3.10)

# Tên dự án và phiên bản
project(NihongoApp VERSION 1.0)

# Thiết lập tiêu chuẩn C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Tự động tìm tất cả các tệp .cpp trong thư mục src/
file(GLOB SOURCES "src/*.cpp")

# Tạo tệp thực thi từ tất cả các nguồn đã tìm thấy
add_executable(nihongo_app ${SOURCES})

# Cấu hình thư mục chứa các tệp header (.h)
target_include_directories(nihongo_app PRIVATE include)

# Cấu hình cho Windows: Luôn hiển thị cửa sổ console
if(WIN32)
    set_target_properties(nihongo_app PROPERTIES
        WIN32_EXECUTABLE FALSE
    )
endif()