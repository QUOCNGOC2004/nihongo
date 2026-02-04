#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include "flashCard.hpp"

class CSVHandler {
private:
    std::string filePath;
    
    // Hàm hỗ trợ: Xử lý escape dấu phẩy và dấu ngoặc kép trong CSV
    std::string escapeCSV(const std::string& data) const;
    
    // Hàm hỗ trợ: Giải mã dữ liệu CSV (xử lý dấu ngoặc kép)
    std::string unescapeCSV(const std::string& data) const;

public:
    // Constructor: Nhận đường dẫn file CSV
    CSVHandler(const std::string& path);
    
    // Lưu danh sách flashCard vào file (GHI ĐÈ toàn bộ file)
    bool luuDuLieu(const std::vector<flashCard>& cards);
    
    // Thêm flashCard mới vào cuối file (KHÔNG làm mất dữ liệu cũ)
    bool themDuLieu(const flashCard& card);
    
    // Thêm nhiều flashCard vào cuối file
    bool themNhieuDuLieu(const std::vector<flashCard>& cards);
    
    // Mở và Đọc tất cả dữ liệu từ file CSV
    std::vector<flashCard> docDuLieu();
    
    // Kiểm tra file có tồn tại không
    bool kiemTraFile() const;
    
    // Tạo file CSV mới với header
    bool taoFileMoi();
};
