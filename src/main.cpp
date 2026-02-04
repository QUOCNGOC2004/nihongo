#include <iostream>
#include "flashCard.hpp"
#include "CSVHandler.hpp"
#include "MenuHelper.hpp"
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif

    CSVHandler handler("../tuvung/flashcards.csv");
    
    // Đọc dữ liệu từ file
    std::cout << "📖 Đang đọc dữ liệu từ file CSV..." << std::endl;
    std::vector<flashCard> danhSachGoc = handler.docDuLieu();
    
    if (danhSachGoc.empty()) {
        std::cout << "⚠️  Cảnh báo: Không có dữ liệu từ vựng!" << std::endl;
    } else {
        std::cout << "✅ Đã tải " << danhSachGoc.size() << " từ vựng!" << std::endl;
    }
    
    // Chạy menu chính
    MenuHelper::chayMenu(handler, danhSachGoc);

    return 0;
}