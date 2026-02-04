#include <iostream>
#include "flashCard.hpp"
#include "CSVHandler.hpp"
#include "StudyHelper.hpp"
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

void inDanhSach(const std::vector<flashCard>& cards, const std::string& tieuDe) {
    std::cout << "\n========================================" << std::endl;
    std::cout << tieuDe << std::endl;
    std::cout << "========================================" << std::endl;
    if (cards.empty()) {
        std::cout << "Không có từ vựng nào!" << std::endl;
    } else {
        for (size_t i = 0; i < cards.size(); ++i) {
            std::cout << "[" << (i + 1) << "] ";
            cards[i].hienThi();
        }
        std::cout << "Tổng số: " << cards.size() << " từ vựng" << std::endl;
    }
}

int main() {
    
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif

    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║   CHƯƠNG TRÌNH HỌC TỪ VỰNG TIẾNG NHẬT   ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;

    CSVHandler handler("../tuvung/flashcards.csv");
    
    // Đọc dữ liệu từ file
    std::cout << "\n📖 Đang đọc dữ liệu từ file CSV..." << std::endl;
    std::vector<flashCard> danhSachGoc = handler.docDuLieu();

    // Test 1: Hiển thị danh sách gốc
    inDanhSach(danhSachGoc, "📚 DANH SÁCH TỪ VỰNG GỐC (Theo thứ tự trong file)");

    // Test 2: Xáo trộn toàn bộ từ vựng
    std::vector<flashCard> danhSachXaoTron = StudyHelper::getShuffledCards(danhSachGoc);
    inDanhSach(danhSachXaoTron, "🎲 DANH SÁCH TỪ VỰNG SAU KHI XÁO TRỘN (Random)");

    // Test 3: Lọc từ vựng theo ngày 2026-02-01
    std::cout << "\n🔍 Test lọc từ vựng theo ngày..." << std::endl;
    std::vector<flashCard> ngay1 = StudyHelper::getCardsByDate(danhSachGoc, "2026-02-01");
    inDanhSach(ngay1, "📅 TỪ VỰNG NGÀY 2026-02-01");

    // Test 4: Lọc từ vựng theo ngày 2026-02-02
    std::vector<flashCard> ngay2 = StudyHelper::getCardsByDate(danhSachGoc, "2026-02-02");
    inDanhSach(ngay2, "📅 TỪ VỰNG NGÀY 2026-02-02");

    // Test 5: Lọc từ vựng theo ngày 2026-02-03
    std::vector<flashCard> ngay3 = StudyHelper::getCardsByDate(danhSachGoc, "2026-02-03");
    inDanhSach(ngay3, "📅 TỪ VỰNG NGÀY 2026-02-03");

    // Test 6: Lọc từ vựng theo ngày 2026-02-04 và xáo trộn
    std::vector<flashCard> ngay4XaoTron = StudyHelper::getShuffledCardsByDate(danhSachGoc, "2026-02-04");
    inDanhSach(ngay4XaoTron, "🎲📅 TỪ VỰNG NGÀY 2026-02-04 (Đã xáo trộn)");

    // Test 7: Thử lọc ngày không có dữ liệu
    std::vector<flashCard> ngayKhongCo = StudyHelper::getCardsByDate(danhSachGoc, "2026-01-15");
    inDanhSach(ngayKhongCo, "📅 TỪ VỰNG NGÀY 2026-01-15 (Ngày không có dữ liệu)");

    // Menu tương tác
    std::cout << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║          MENU TƯƠNG TÁC                ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;

    while (true) {
        std::cout << "\n📋 Chọn chức năng:" << std::endl;
        std::cout << "1. Xem toàn bộ từ vựng (random)" << std::endl;
        std::cout << "2. Ôn từ vựng theo ngày cụ thể" << std::endl;
        std::cout << "3. Thêm từ vựng mới" << std::endl;
        std::cout << "4. Thoát" << std::endl;
        std::cout << "Lựa chọn của bạn: ";

        std::string luaChon;
        std::getline(std::cin, luaChon);

        if (luaChon == "1") {
            // Xáo trộn và hiển thị
            std::vector<flashCard> shuffled = StudyHelper::getShuffledCards(danhSachGoc);
            inDanhSach(shuffled, "🎲 HỌC TỪ VỰNG RANDOM");
        } 
        else if (luaChon == "2") {
            // Lọc theo ngày
            std::cout << "Nhập ngày cần ôn (YYYY-MM-DD): ";
            std::string ngay;
            std::getline(std::cin, ngay);
            
            std::vector<flashCard> cardsByDate = StudyHelper::getShuffledCardsByDate(danhSachGoc, ngay);
            inDanhSach(cardsByDate, "📅 ÔN TẬP TỪ VỰNG NGÀY " + ngay);
        }
        else if (luaChon == "3") {
            // Thêm từ vựng mới
            std::cout << "Nhập tiếng việt: ";
            std::string tiengViet;
            std::getline(std::cin, tiengViet);
            
            std::cout << "Nhập tiếng nhật: ";
            std::string tiengNhat;
            std::getline(std::cin, tiengNhat);
            
            std::cout << "Nhập ghi chú: ";
            std::string ghiChu;
            std::getline(std::cin, ghiChu);
            
            flashCard cardMoi(tiengViet, tiengNhat, ghiChu);
            if (handler.themDuLieu(cardMoi)) {
                std::cout << "✅ Đã thêm từ vựng mới!" << std::endl;
                // Cập nhật lại danh sách gốc
                danhSachGoc = handler.docDuLieu();
            }
        }
        else if (luaChon == "4") {
            std::cout << "\n👋 Tạm biệt! Chúc bạn học tốt!" << std::endl;
            break;
        }
        else {
            std::cout << "❌ Lựa chọn không hợp lệ!" << std::endl;
        }
    }

    return 0;
}