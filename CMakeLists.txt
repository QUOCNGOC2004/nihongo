cmake_minimum_required(VERSION 3.10)

# Project name
project(NihongoApp VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Automatically find all .cpp files in src/ directory
file(GLOB SOURCES "src/*.cpp")

# Add executable with all found sources
add_executable(nihongo_app ${SOURCES})

# Include directories
target_include_directories(nihongo_app PRIVATE include)

# For Windows: Open console window
if(WIN32)
    set_target_properties(nihongo_app PROPERTIES
        WIN32_EXECUTABLE FALSE
    )
endif()
