#include "greeting.hpp"
#include <iostream>

void Greeting::welcome() {
    std::cout << "🎌 ようこそ！(Youkoso! - Welcome!)\n";
    std::cout << "This file was automatically detected by CMake!\n";
    std::cout << "No need to edit CMakeLists.txt! 🎉\n\n";
}

void Greeting::goodbye() {
    std::cout << "\n👋 またね！(Mata ne! - See you!)\n";
}
