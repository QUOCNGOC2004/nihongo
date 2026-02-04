#include "MenuHelper.hpp"
#include "StudyHelper.hpp"
#include <iostream>
#include <conio.h> // Để sử dụng _getch() trên Windows

#ifdef _WIN32
#include <windows.h>
#endif

// 1. Hiển thị toàn bộ danh sách từ vựng (không hiển thị time, không xáo trộn)
void MenuHelper::hienThiToanBoDanhSach(const std::vector<flashCard>& cards) {
    std::cout << "\n╔════════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║          DANH SÁCH TOÀN BỘ TỪ VỰNG                            ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
    
    if (cards.empty()) {
        std::cout << "❌ Không có từ vựng nào!" << std::endl;
        return;
    }
    
    std::cout << "\n";
    for (size_t i = 0; i < cards.size(); ++i) {
        std::cout << "[" << (i + 1) << "] ";
        std::cout << "Tiếng Việt: " << cards[i].getTiengViet();
        std::cout << " | Tiếng Nhật: " << cards[i].getTiengNhat();
        std::cout << " | Ghi chú: " << cards[i].getGhiChu() << std::endl;
    }
    std::cout << "\n📊 Tổng số: " << cards.size() << " từ vựng" << std::endl;
    
    std::cout << "\nẤn phím bất kỳ để quay lại menu...";
    _getch();
}

// 2. Ôn tiếng Nhật (hiển thị tiếng Việt, ấn w để xem tiếng Nhật)
void MenuHelper::onTiengNhat(std::vector<flashCard>& cards) {
    if (cards.empty()) {
        std::cout << "❌ Không có từ vựng nào để ôn!" << std::endl;
        std::cout << "Ấn phím bất kỳ để quay lại menu...";
        _getch();
        return;
    }
    
    // Xáo trộn danh sách
    std::vector<flashCard> shuffledCards = StudyHelper::getShuffledCards(cards);
    
    size_t currentIndex = 0;
    bool showAnswer = false; // false = hiển thị tiếng Việt, true = hiển thị tiếng Nhật
    
    while (true) {
        // Xóa màn hình
        system("cls");
        
        std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║                    ÔN TIẾNG NHẬT                               ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
        std::cout << "\n📍 Từ vựng: " << (currentIndex + 1) << "/" << shuffledCards.size() << std::endl;
        std::cout << "────────────────────────────────────────────────────────────────" << std::endl;
        
        if (!showAnswer) {
            // Hiển thị tiếng Việt
            std::cout << "\n🇻🇳 Tiếng Việt: " << shuffledCards[currentIndex].getTiengViet() << std::endl;
            std::cout << "\n🔒 Tiếng Nhật: [Ấn 'w' để hiển thị]" << std::endl;
            std::cout << "🔒 Ghi chú: [Ấn 'w' để hiển thị]" << std::endl;
        } else {
            // Hiển thị tiếng Việt + tiếng Nhật + ghi chú
            std::cout << "\n🇻🇳 Tiếng Việt: " << shuffledCards[currentIndex].getTiengViet() << std::endl;
            std::cout << "\n🇯🇵 Tiếng Nhật: " << shuffledCards[currentIndex].getTiengNhat() << std::endl;
            std::cout << "📝 Ghi chú: " << shuffledCards[currentIndex].getGhiChu() << std::endl;
        }
        
        std::cout << "\n────────────────────────────────────────────────────────────────" << std::endl;
        std::cout << "⌨️  Điều khiển:" << std::endl;
        std::cout << "   [W] - Hiển thị tiếng Nhật và ghi chú" << std::endl;
        std::cout << "   [S] - Ẩn tiếng Nhật và ghi chú" << std::endl;
        std::cout << "   [D] - Từ vựng tiếp theo" << std::endl;
        std::cout << "   [A] - Từ vựng trước đó" << std::endl;
        std::cout << "   [1] - Quay lại menu" << std::endl;
        
        // Đọc phím
        char key = _getch();
        
        if (key == 'w' || key == 'W') {
            showAnswer = true;
        } else if (key == 's' || key == 'S') {
            showAnswer = false;
        } else if (key == 'd' || key == 'D') {
            if (currentIndex < shuffledCards.size() - 1) {
                currentIndex++;
                showAnswer = false; // Reset về trạng thái ẩn khi chuyển từ
            }
        } else if (key == 'a' || key == 'A') {
            if (currentIndex > 0) {
                currentIndex--;
                showAnswer = false; // Reset về trạng thái ẩn khi chuyển từ
            }
        } else if (key == '1') {
            break; // Quay lại menu
        }
    }
}

// 3. Ôn tiếng Việt (hiển thị tiếng Nhật, ấn w để xem tiếng Việt)
void MenuHelper::onTiengViet(std::vector<flashCard>& cards) {
    if (cards.empty()) {
        std::cout << "❌ Không có từ vựng nào để ôn!" << std::endl;
        std::cout << "Ấn phím bất kỳ để quay lại menu...";
        _getch();
        return;
    }
    
    // Xáo trộn danh sách
    std::vector<flashCard> shuffledCards = StudyHelper::getShuffledCards(cards);
    
    size_t currentIndex = 0;
    bool showAnswer = false; // false = hiển thị tiếng Nhật, true = hiển thị tiếng Việt
    
    while (true) {
        // Xóa màn hình
        system("cls");
        
        std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║                    ÔN TIẾNG VIỆT                               ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
        std::cout << "\n📍 Từ vựng: " << (currentIndex + 1) << "/" << shuffledCards.size() << std::endl;
        std::cout << "────────────────────────────────────────────────────────────────" << std::endl;
        
        if (!showAnswer) {
            // Hiển thị tiếng Nhật
            std::cout << "\n🇯🇵 Tiếng Nhật: " << shuffledCards[currentIndex].getTiengNhat() << std::endl;
            std::cout << "\n🔒 Tiếng Việt: [Ấn 'w' để hiển thị]" << std::endl;
            std::cout << "🔒 Ghi chú: [Ấn 'w' để hiển thị]" << std::endl;
        } else {
            // Hiển thị tiếng Nhật + tiếng Việt + ghi chú
            std::cout << "\n🇯🇵 Tiếng Nhật: " << shuffledCards[currentIndex].getTiengNhat() << std::endl;
            std::cout << "\n🇻🇳 Tiếng Việt: " << shuffledCards[currentIndex].getTiengViet() << std::endl;
            std::cout << "📝 Ghi chú: " << shuffledCards[currentIndex].getGhiChu() << std::endl;
        }
        
        std::cout << "\n────────────────────────────────────────────────────────────────" << std::endl;
        std::cout << "⌨️  Điều khiển:" << std::endl;
        std::cout << "   [W] - Hiển thị tiếng Việt và ghi chú" << std::endl;
        std::cout << "   [S] - Ẩn tiếng Việt và ghi chú" << std::endl;
        std::cout << "   [D] - Từ vựng tiếp theo" << std::endl;
        std::cout << "   [A] - Từ vựng trước đó" << std::endl;
        std::cout << "   [1] - Quay lại menu" << std::endl;
        
        // Đọc phím
        char key = _getch();
        
        if (key == 'w' || key == 'W') {
            showAnswer = true;
        } else if (key == 's' || key == 'S') {
            showAnswer = false;
        } else if (key == 'd' || key == 'D') {
            if (currentIndex < shuffledCards.size() - 1) {
                currentIndex++;
                showAnswer = false; // Reset về trạng thái ẩn khi chuyển từ
            }
        } else if (key == 'a' || key == 'A') {
            if (currentIndex > 0) {
                currentIndex--;
                showAnswer = false; // Reset về trạng thái ẩn khi chuyển từ
            }
        } else if (key == '1') {
            break; // Quay lại menu
        }
    }
}

// 4. Thêm từ vựng mới vào file CSV
void MenuHelper::themTuVungMoi(CSVHandler& handler, std::vector<flashCard>& cards) {
    system("cls");
    std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                  THÊM TỪ VỰNG MỚI                              ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
    
    std::string tiengViet, tiengNhat, ghiChu;
    
    std::cout << "\n📝 Nhập tiếng Việt: ";
    std::getline(std::cin, tiengViet);
    
    std::cout << "📝 Nhập tiếng Nhật: ";
    std::getline(std::cin, tiengNhat);
    
    std::cout << "📝 Nhập ghi chú: ";
    std::getline(std::cin, ghiChu);
    
    // Tạo flashCard mới (timestamp sẽ tự động là thời gian hiện tại)
    flashCard cardMoi(tiengViet, tiengNhat, ghiChu);
    
    if (handler.themDuLieu(cardMoi)) {
        std::cout << "\n✅ Đã thêm từ vựng mới thành công!" << std::endl;
        // Cập nhật lại danh sách trong bộ nhớ
        cards = handler.docDuLieu();
    } else {
        std::cout << "\n❌ Lỗi khi thêm từ vựng!" << std::endl;
    }
    
    std::cout << "\nẤn phím bất kỳ để quay lại menu...";
    _getch();
}

// Hiển thị menu chính
void MenuHelper::hienThiMenu() {
    system("cls");
    std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║          CHƯƠNG TRÌNH HỌC TỪ VỰNG TIẾNG NHẬT                  ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
    std::cout << "\n📋 MENU CHÍNH:" << std::endl;
    std::cout << "────────────────────────────────────────────────────────────────" << std::endl;
    std::cout << "  1️⃣  Hiển thị toàn bộ danh sách từ vựng" << std::endl;
    std::cout << "  2️⃣  Ôn tiếng Nhật (Việt → Nhật)" << std::endl;
    std::cout << "  3️⃣  Ôn tiếng Việt (Nhật → Việt)" << std::endl;
    std::cout << "  4️⃣  Thêm từ vựng mới" << std::endl;
    std::cout << "  5️⃣  Thoát chương trình" << std::endl;
    std::cout << "────────────────────────────────────────────────────────────────" << std::endl;
    std::cout << "\n👉 Lựa chọn của bạn: ";
}

// Chạy menu chính
void MenuHelper::chayMenu(CSVHandler& handler, std::vector<flashCard>& cards) {
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif
    
    while (true) {
        hienThiMenu();
        
        std::string luaChon;
        std::getline(std::cin, luaChon);
        
        if (luaChon == "1") {
            hienThiToanBoDanhSach(cards);
        } else if (luaChon == "2") {
            onTiengNhat(cards);
        } else if (luaChon == "3") {
            onTiengViet(cards);
        } else if (luaChon == "4") {
            themTuVungMoi(handler, cards);
        } else if (luaChon == "5") {
            system("cls");
            std::cout << "\n╔════════════════════════════════════════════════════════════════╗" << std::endl;
            std::cout << "║              👋 TẠM BIỆT! CHÚC BẠN HỌC TỐT! 📚                 ║" << std::endl;
            std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
            break;
        } else {
            std::cout << "\n❌ Lựa chọn không hợp lệ! Vui lòng chọn từ 1-5." << std::endl;
            std::cout << "Ấn phím bất kỳ để thử lại...";
            _getch();
        }
    }
}
