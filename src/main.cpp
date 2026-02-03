#include <iostream>
#include "flashCard.hpp"
#include "CSVHandler.hpp"
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif


int main() {
    
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif
    CSVHandler handler("./data/flashcards.csv");
    std::cout << "Đang đọc dữ liệu từ file CSV..." << std::endl;
    std::vector<flashCard> danhSachHienTai = handler.docDuLieu();

    // In ra kiểm tra
    std::cout << "Tìm thấy " << danhSachHienTai.size() << " từ vựng trong file." << std::endl;
    for(const auto& card : danhSachHienTai) {
        card.hienThi(); 
    }

    std::string nhapTiep;
    
    do {
        std::cout << "Nhaps tiep (y/n): ";
        std::getline(std::cin, nhapTiep);

        if (nhapTiep == "y") {
            std::cout << "Nhap tieng viet: ";
            std::string tiengViet;
            std::getline(std::cin, tiengViet);
            std::cout << "Nhap tieng nhat: ";
            std::string tiengNhat;
            std::getline(std::cin, tiengNhat);
            std::cout << "Nhap ghi chu: ";
            std::string ghiChu;
            std::getline(std::cin, ghiChu);
            flashCard card(tiengViet, tiengNhat, ghiChu);
            handler.themDuLieu(card);
        }
    } while (nhapTiep != "n");





    return 0;
}