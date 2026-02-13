#pragma once
#include <vector>
#include <string>
#include "flashCard.hpp"
#include "CSVHandler.hpp"

class MenuHelper {
public:
    // 1. Hiển thị toàn bộ danh sách từ vựng (không hiển thị time, không xáo trộn)
    static void hienThiToanBoDanhSach(const std::vector<flashCard>& cards);
    
    // 2. Ôn tiếng Nhật (hiển thị tiếng Việt, ấn w để xem tiếng Nhật)
    static void onTiengNhat(std::vector<flashCard>& cards);
    
    // 3. Ôn tiếng Việt (hiển thị tiếng Nhật, ấn w để xem tiếng Việt)
    static void onTiengViet(std::vector<flashCard>& cards);
    
    // 4. Thêm từ vựng mới vào file CSV
    static void themTuVungMoi(CSVHandler& handler, std::vector<flashCard>& cards);
    
    // 5. Hiển thị menu lọc theo ngày và xử lý lựa chọn
    static void hienThiMenuTheoNgay(CSVHandler& handler, std::vector<flashCard>& cards);
    
    // Chạy menu phụ cho từ vựng đã lọc theo ngày
    static void chayMenuTheoNgay(const std::string& date, const std::vector<flashCard>& cards);
    
    // Hiển thị menu chính
    static void hienThiMenu();
    
    // Chạy menu chính
    static void chayMenu(CSVHandler& handler, std::vector<flashCard>& cards);
};
