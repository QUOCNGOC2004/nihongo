#include "MenuHelper.hpp"
#include "StudyHelper.hpp"
#include <iostream>
#include <conio.h> // Để sử dụng _getch() trên Windows
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

// 1. Hiển thị toàn bộ danh sách từ vựng (không hiển thị time, không xáo trộn)
void MenuHelper::hienThiToanBoDanhSach(const std::vector<flashCard> &cards)
{
    std::cout << "\n╔════════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║          DANH SÁCH TOÀN BỘ TỪ VỰNG                             ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;

    if (cards.empty())
    {
        std::cout << "❌ Không có từ vựng nào!" << std::endl;
        return;
    }

    std::cout << "\n";
    for (size_t i = 0; i < cards.size(); ++i)
    {
        std::cout << "[" << (i + 1) << "] ";
        std::cout << " " << cards[i].getTiengViet();
        std::cout << " | " << cards[i].getTiengNhat();
        if (!cards[i].getGhiChu().empty())
        {
            std::cout << " | Ghi chú: " << cards[i].getGhiChu() << std::endl;
        }
        else
        {
            std::cout << std::endl;
        }
    }
    std::cout << "\n📊 Tổng số: " << cards.size() << " từ vựng" << std::endl;

    std::cout << "\nẤn phím bất kỳ để quay lại menu...";
    _getch();
}

// 2. Ôn tiếng Nhật (hiển thị tiếng Việt, ấn w để xem tiếng Nhật)
void MenuHelper::onTiengNhat(std::vector<flashCard> &cards)
{
    if (cards.empty())
    {
        std::cout << "❌ Không có từ vựng nào để ôn!" << std::endl;
        std::cout << "Ấn phím bất kỳ để quay lại menu...";
        _getch();
        return;
    }

    // Xáo trộn danh sách
    std::vector<flashCard> shuffledCards = StudyHelper::getShuffledCards(cards);

    size_t currentIndex = 0;
    bool showAnswer = false; // false = hiển thị tiếng Việt, true = hiển thị tiếng Nhật

    while (true)
    {
        // Xóa màn hình
        system("cls");

        std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║                    ÔN TIẾNG NHẬT                               ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
        std::cout << "\n📍 Từ vựng: " << (currentIndex + 1) << "/" << shuffledCards.size() << std::endl;
        std::cout << "────────────────────────────────────────────────────────────────" << std::endl;

        if (!showAnswer)
        {
            // Hiển thị tiếng Việt
            std::cout << "\n 🙂 Tiếng Việt: " << shuffledCards[currentIndex].getTiengViet() << std::endl;
        }
        else
        {
            // Hiển thị tiếng Việt + tiếng Nhật + ghi chú
            std::cout << "\n 🙂 Tiếng Việt: " << shuffledCards[currentIndex].getTiengViet() << std::endl;
            std::cout << "\n 🤔 Tiếng Nhật: " << shuffledCards[currentIndex].getTiengNhat() << std::endl;
            if (!shuffledCards[currentIndex].getGhiChu().empty())
            {
                std::cout << "\n 📝 Ghi chú: " << shuffledCards[currentIndex].getGhiChu() << std::endl;
            }
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

        if (key == 'w' || key == 'W')
        {
            showAnswer = true;
        }
        else if (key == 's' || key == 'S')
        {
            showAnswer = false;
        }
        else if (key == 'd' || key == 'D')
        {
            if (currentIndex < shuffledCards.size() - 1)
            {
                currentIndex++;
                showAnswer = false; // Reset về trạng thái ẩn khi chuyển từ
            }
        }
        else if (key == 'a' || key == 'A')
        {
            if (currentIndex > 0)
            {
                currentIndex--;
                showAnswer = false; // Reset về trạng thái ẩn khi chuyển từ
            }
        }
        else if (key == '1')
        {
            break; // Quay lại menu
        }
    }
}

// 3. Ôn tiếng Việt (hiển thị tiếng Nhật, ấn w để xem tiếng Việt)
void MenuHelper::onTiengViet(std::vector<flashCard> &cards)
{
    if (cards.empty())
    {
        std::cout << "❌ Không có từ vựng nào để ôn!" << std::endl;
        std::cout << "Ấn phím bất kỳ để quay lại menu...";
        _getch();
        return;
    }

    // Xáo trộn danh sách
    std::vector<flashCard> shuffledCards = StudyHelper::getShuffledCards(cards);

    size_t currentIndex = 0;
    bool showAnswer = false; // false = hiển thị tiếng Nhật, true = hiển thị tiếng Việt

    while (true)
    {
        // Xóa màn hình
        system("cls");

        std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║                    ÔN TIẾNG VIỆT                               ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
        std::cout << "\n📍 Từ vựng: " << (currentIndex + 1) << "/" << shuffledCards.size() << std::endl;
        std::cout << "────────────────────────────────────────────────────────────────" << std::endl;

        if (!showAnswer)
        {
            // Hiển thị tiếng Nhật
            std::cout << "\n  🤔 Tiếng Nhật: " << shuffledCards[currentIndex].getTiengNhat() << std::endl;
        }
        else
        {
            // Hiển thị tiếng Nhật + tiếng Việt + ghi chú
            std::cout << "\n 🤔 Tiếng Nhật: " << shuffledCards[currentIndex].getTiengNhat() << std::endl;
            std::cout << "\n 🙂 Tiếng Việt: " << shuffledCards[currentIndex].getTiengViet() << std::endl;
            if (!shuffledCards[currentIndex].getGhiChu().empty())
            {
                std::cout << "\n 📝 Ghi chú: " << shuffledCards[currentIndex].getGhiChu() << std::endl;
            }
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

        if (key == 'w' || key == 'W')
        {
            showAnswer = true;
        }
        else if (key == 's' || key == 'S')
        {
            showAnswer = false;
        }
        else if (key == 'd' || key == 'D')
        {
            if (currentIndex < shuffledCards.size() - 1)
            {
                currentIndex++;
                showAnswer = false; // Reset về trạng thái ẩn khi chuyển từ
            }
        }
        else if (key == 'a' || key == 'A')
        {
            if (currentIndex > 0)
            {
                currentIndex--;
                showAnswer = false; // Reset về trạng thái ẩn khi chuyển từ
            }
        }
        else if (key == '1')
        {
            break; // Quay lại menu
        }
    }
}

// 4. Thêm từ vựng mới vào file CSV
void MenuHelper::themTuVungMoi(CSVHandler &handler, std::vector<flashCard> &cards)
{
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

    if (handler.themDuLieu(cardMoi))
    {
        std::cout << "\n✅ Đã thêm từ vựng mới thành công!" << std::endl;
        // Cập nhật lại danh sách trong bộ nhớ
        cards = handler.docDuLieu();
    }
    else
    {
        std::cout << "\n❌ Lỗi khi thêm từ vựng!" << std::endl;
    }

    std::cout << "\nẤn phím bất kỳ để quay lại menu...";
    _getch();
}

// 5. Hiển thị menu lọc theo ngày và xử lý lựa chọn
void MenuHelper::hienThiMenuTheoNgay(CSVHandler& handler, std::vector<flashCard>& cards) {
    if (cards.empty()) {
        system("cls");
        std::cout << "❌ Không có từ vựng nào!" << std::endl;
        std::cout << "Ấn phím bất kỳ để quay lại menu...";
        _getch();
        return;
    }
    
    // Lấy danh sách các ngày duy nhất
    std::vector<std::string> dates = StudyHelper::getUniqueDates(cards);
    
    if (dates.empty()) {
        system("cls");
        std::cout << "❌ Không tìm thấy ngày nào!" << std::endl;
        std::cout << "Ấn phím bất kỳ để quay lại menu...";
        _getch();
        return;
    }
    
    while (true) {
        system("cls");
        std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║              LỌC TỪ VỰNG THEO NGÀY                             ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
        std::cout << "\n📅 Chọn ngày để xem từ vựng:" << std::endl;
        std::cout << "────────────────────────────────────────────────────────────────" << std::endl;
        
        // Hiển thị danh sách các ngày với số lượng từ vựng
        for (size_t i = 0; i < dates.size(); ++i) {
            std::vector<flashCard> cardsOnDate = StudyHelper::getCardsByDate(cards, dates[i]);
            std::cout << (i + 1) << ". " << dates[i] << " (" << cardsOnDate.size() << " từ vựng)" << std::endl;
        }
        
        std::cout << "0. Quay lại menu chính" << std::endl;
        std::cout << "────────────────────────────────────────────────────────────────" << std::endl;
        std::cout << "\n👉 Lựa chọn của bạn: ";
        
        std::string luaChon;
        std::getline(std::cin, luaChon);
        
        if (luaChon == "0") {
            break; // Quay lại menu chính
        }
        
        // Kiểm tra lựa chọn hợp lệ
        try {
            int choice = std::stoi(luaChon);
            if (choice >= 1 && choice <= static_cast<int>(dates.size())) {
                std::string selectedDate = dates[choice - 1];
                chayMenuTheoNgay(selectedDate, cards);
            } else {
                std::cout << "\n❌ Lựa chọn không hợp lệ!" << std::endl;
                std::cout << "Ấn phím Enter để thử lại...";
                _getch();
            }
        } catch (...) {
            std::cout << "\n❌ Vui lòng nhập số!" << std::endl;
            std::cout << "Ấn phím Enter để thử lại...";
            _getch();
        }
    }
}

// Chạy menu phụ cho từ vựng đã lọc theo ngày
void MenuHelper::chayMenuTheoNgay(const std::string& date, const std::vector<flashCard>& cards) {
    // Lọc từ vựng theo ngày đã chọn
    std::vector<flashCard> filteredCards = StudyHelper::getCardsByDate(cards, date);
    
    if (filteredCards.empty()) {
        system("cls");
        std::cout << "❌ Không có từ vựng nào trong ngày " << date << "!" << std::endl;
        std::cout << "Ấn phím bất kỳ để quay lại...";
        _getch();
        return;
    }
    
    while (true) {
        system("cls");
        std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║          TỪ VỰNG NGÀY: " << date << "                      ║" << std::endl;
        std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
        std::cout << "\n📋 MENU:" << std::endl;
        std::cout << "────────────────────────────────────────────────────────────────" << std::endl;
        std::cout << "1. Hiển thị toàn bộ từ vựng (" << filteredCards.size() << " từ)" << std::endl;
        std::cout << "2. Ôn tiếng Nhật (Việt → Nhật)" << std::endl;
        std::cout << "3. Ôn tiếng Việt (Nhật → Việt)" << std::endl;
        std::cout << "4. Quay lại" << std::endl;
        std::cout << "────────────────────────────────────────────────────────────────" << std::endl;
        std::cout << "\n👉 Lựa chọn của bạn: ";
        
        std::string luaChon;
        std::getline(std::cin, luaChon);
        
        if (luaChon == "1") {
            hienThiToanBoDanhSach(filteredCards);
        } else if (luaChon == "2") {
            onTiengNhat(filteredCards);
        } else if (luaChon == "3") {
            onTiengViet(filteredCards);
        } else if (luaChon == "4") {
            break; // Quay lại menu chọn ngày
        } else {
            std::cout << "\n❌ Lựa chọn không hợp lệ! Vui lòng chọn từ 1-4." << std::endl;
            std::cout << "Ấn phím Enter để thử lại...";
            _getch();
        }
    }
}

// Hiển thị menu chính
void MenuHelper::hienThiMenu()
{
    system("cls");
    std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║          CHƯƠNG TRÌNH HỌC TỪ VỰNG TIẾNG NHẬT                   ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
    std::cout << "\n📋 MENU CHÍNH:" << std::endl;
    std::cout << "────────────────────────────────────────────────────────────────" << std::endl;
    std::cout << "1. Hiển thị toàn bộ danh sách từ vựng" << std::endl;
    std::cout << "2. Ôn tiếng Nhật (Việt → Nhật)" << std::endl;
    std::cout << "3. Ôn tiếng Việt (Nhật → Việt)" << std::endl;
    std::cout << "4. Thêm từ vựng mới" << std::endl;
    std::cout << "5. Lọc từ vựng theo ngày" << std::endl;
    std::cout << "6. Thoát chương trình" << std::endl;
    std::cout << "────────────────────────────────────────────────────────────────" << std::endl;
    std::cout << "\n👉 Lựa chọn của bạn: ";
}

// Chạy menu chính
void MenuHelper::chayMenu(CSVHandler &handler, std::vector<flashCard> &cards)
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

    while (true)
    {
        hienThiMenu();

        std::string luaChon;
        std::getline(std::cin, luaChon);

        if (luaChon == "1")
        {
            hienThiToanBoDanhSach(cards);
        }
        else if (luaChon == "2")
        {
            onTiengNhat(cards);
        }
        else if (luaChon == "3")
        {
            onTiengViet(cards);
        }
        else if (luaChon == "4")
        {
            themTuVungMoi(handler, cards);
        }
        else if (luaChon == "5")
        {
            hienThiMenuTheoNgay(handler, cards);
        }
        else if (luaChon == "6")
        {
            system("cls");
            std::cout << "\n╔════════════════════════════════════════════════════════════════╗" << std::endl;
            std::cout << "║              👋 TẠM BIỆT! CHÚC BẠN HỌC TỐT! 📚                 ║" << std::endl;
            std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
            break;
        }
        else
        {
            std::cout << "\n❌ Lựa chọn không hợp lệ! Vui lòng chọn từ 1-6." << std::endl;
            std::cout << "Ấn phím Enter để thử lại...";
            _getch();
        }
    }
}
