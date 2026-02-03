#include <iostream>
#include "flashCard.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif

    std::cout << "Testing FlashCard Class (Optimized)..." << std::endl;

    flashCard card("Xin chào", "こんにちは", "Greeting");

    std::cout << "Initial state:" << std::endl;
    card.hienThi();
    std::cout << "-----------------" << std::endl;

    card.setTiengViet("Tạm biệt");
    card.setTiengNhat("さようなら");
    card.setGhiChu("  Farewell");

    std::cout << "After individual setters:" << std::endl;

    std::cout << "Tiếng Việt: " << card.getTiengViet() << std::endl;
    std::cout << "Tiếng Nhật: " << card.getTiengNhat() << std::endl;
    std::cout << "Ghi Chú: " << card.getGhiChu() << std::endl;
    std::cout << "-----------------" << std::endl;

    card.setAll("Cảm ơn", "ありがとう", "Thank you");
    std::cout << "After setAll:" << std::endl;
    std::cout << card.getAll() << std::endl;

    return 0;
}