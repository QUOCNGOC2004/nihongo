#include "CSVHandler.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

// Constructor
CSVHandler::CSVHandler(const std::string& path) : filePath(path) {}

// Hàm escape: Xử lý dấu phẩy và dấu ngoặc kép trong dữ liệu
std::string CSVHandler::escapeCSV(const std::string& data) const {
    // Nếu có dấu phẩy hoặc dấu ngoặc kép, bọc chuỗi bằng dấu ngoặc kép
    if (data.find(',') != std::string::npos || data.find('"') != std::string::npos) {
        std::string escaped = "\"";
        for (char c : data) {
            if (c == '"') {
                escaped += "\"\""; // Escape dấu ngoặc kép bằng cách nhân đôi
            } else {
                escaped += c;
            }
        }
        escaped += "\"";
        return escaped;
    }
    return data;
}

// Hàm unescape: Giải mã dữ liệu CSV
std::string CSVHandler::unescapeCSV(const std::string& data) const {
    if (data.empty()) return data;
    
    std::string result = data;
    
    // Nếu bắt đầu và kết thúc bằng dấu ngoặc kép, bỏ chúng đi
    if (result.front() == '"' && result.back() == '"') {
        result = result.substr(1, result.length() - 2);
        
        // Thay thế "" thành "
        size_t pos = 0;
        while ((pos = result.find("\"\"", pos)) != std::string::npos) {
            result.replace(pos, 2, "\"");
            pos += 1;
        }
    }
    
    return result;
}

// Chuyển timestamp thành string
std::string CSVHandler::formatTimestamp(time_t t) const {
    struct tm* timeinfo = localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

// Chuyển string thành timestamp
time_t CSVHandler::parseTimestamp(const std::string& str) const {
    if (str.empty()) return time(nullptr);
    
    struct tm tm = {};
    std::istringstream ss(str);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    
    if (ss.fail()) {
        return time(nullptr); // Nếu parse thất bại, trả về thời gian hiện tại
    }
    
    return mktime(&tm);
}

// Lưu toàn bộ dữ liệu vào file (GHI ĐÈ)
bool CSVHandler::luuDuLieu(const std::vector<flashCard>& cards) {
    std::ofstream file(filePath);
    
    if (!file.is_open()) {
        std::cerr << "Loi: Khong the mo file de ghi!" << std::endl;
        return false;
    }
    
    // Ghi header
    file << "Tieng Viet,Tieng Nhat,Ghi Chu,Time" << std::endl;
    
    // Ghi từng flashCard
    for (const auto& card : cards) {
        file << escapeCSV(card.getTiengViet()) << ","
             << escapeCSV(card.getTiengNhat()) << ","
             << escapeCSV(card.getGhiChu()) << ","
             << formatTimestamp(card.getTimestamp()) << std::endl;
    }
    
    file.close();
    std::cout << "Da luu " << cards.size() << " flashcard vao file!" << std::endl;
    return true;
}

// Thêm 1 flashCard vào cuối file (KHÔNG mất dữ liệu cũ)
bool CSVHandler::themDuLieu(const flashCard& card) {
    // Kiểm tra xem file có tồn tại không
    bool fileExists = kiemTraFile();
    
    // Mở file ở chế độ append (ios::app)
    std::ofstream file(filePath, std::ios::app);
    
    if (!file.is_open()) {
        std::cerr << "Loi: Khong the mo file de them du lieu!" << std::endl;
        return false;
    }
    
    // Nếu file mới tạo, thêm header
    if (!fileExists) {
        file << "Tieng Viet,Tieng Nhat,Ghi Chu,Time" << std::endl;
    }
    
    // Thêm dữ liệu mới
    file << escapeCSV(card.getTiengViet()) << ","
         << escapeCSV(card.getTiengNhat()) << ","
         << escapeCSV(card.getGhiChu()) << ","
         << formatTimestamp(card.getTimestamp()) << std::endl;
    
    file.close();
    std::cout << "Da them 1 flashcard vao file!" << std::endl;
    return true;
}

// Thêm nhiều flashCard vào cuối file
bool CSVHandler::themNhieuDuLieu(const std::vector<flashCard>& cards) {
    bool fileExists = kiemTraFile();
    
    std::ofstream file(filePath, std::ios::app);
    
    if (!file.is_open()) {
        std::cerr << "Loi: Khong the mo file de them du lieu!" << std::endl;
        return false;
    }
    
    // Nếu file mới tạo, thêm header
    if (!fileExists) {
        file << "Tieng Viet,Tieng Nhat,Ghi Chu,Time" << std::endl;
    }
    
    // Thêm từng flashCard
    for (const auto& card : cards) {
        file << escapeCSV(card.getTiengViet()) << ","
             << escapeCSV(card.getTiengNhat()) << ","
             << escapeCSV(card.getGhiChu()) << ","
             << formatTimestamp(card.getTimestamp()) << std::endl;
    }
    
    file.close();
    std::cout << "Da them " << cards.size() << " flashcard vao file!" << std::endl;
    return true;
}

// Đọc tất cả dữ liệu từ file CSV
std::vector<flashCard> CSVHandler::docDuLieu() {
    std::vector<flashCard> cards;
    std::ifstream file(filePath);
    
    if (!file.is_open()) {
        std::cerr << "Lỗi: Chưa tạo file hoặc không thể mở file để đọc" << std::endl;
        return cards;
    }
    
    std::string line;
    bool isFirstLine = true;
    
    while (std::getline(file, line)) {
        // Bỏ qua dòng header
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }
        
        // Bỏ qua dòng trống
        if (line.empty()) continue;
        
        std::vector<std::string> fields;
        std::string field;
        bool inQuotes = false;
        
        // Parse CSV với xử lý dấu ngoặc kép
        for (size_t i = 0; i < line.length(); ++i) {
            char c = line[i];
            
            if (c == '"') {
                // Kiểm tra xem có phải là dấu ngoặc kép escape không
                if (inQuotes && i + 1 < line.length() && line[i + 1] == '"') {
                    field += '"';
                    ++i; // Skip dấu ngoặc kép thứ 2
                } else {
                    inQuotes = !inQuotes;
                    field += c;
                }
            } else if (c == ',' && !inQuotes) {
                // Kết thúc field
                fields.push_back(unescapeCSV(field));
                field.clear();
            } else {
                field += c;
            }
        }
        
        // Thêm field cuối cùng
        fields.push_back(unescapeCSV(field));
        
        // Tạo flashCard với timestamp
        if (fields.size() >= 4) {
            // File mới có cột Time
            time_t timestamp = parseTimestamp(fields[3]);
            cards.emplace_back(fields[0], fields[1], fields[2], timestamp);
        } else if (fields.size() == 3) {
            // File cũ không có cột Time, sử dụng thời gian hiện tại
            cards.emplace_back(fields[0], fields[1], fields[2]);
        } else if (fields.size() == 2) {
            // Nếu thiếu cột Ghi Chú, thêm chuỗi rỗng
            cards.emplace_back(fields[0], fields[1], "");
        }
    }
    
    file.close();
    std::cout << "Da doc " << cards.size() << " flashcard tu file!" << std::endl;
    return cards;
}

// Kiểm tra file có tồn tại không
bool CSVHandler::kiemTraFile() const {
    std::ifstream file(filePath);
    return file.good();
}

// Tạo file CSV mới với header
bool CSVHandler::taoFileMoi() {
    std::ofstream file(filePath);
    
    if (!file.is_open()) {
        std::cerr << "Loi: Khong the tao file moi!" << std::endl;
        return false;
    }
    
    // Ghi header
    file << "Tieng Viet,Tieng Nhat,Ghi Chu,Time" << std::endl;
    file.close();
    
    std::cout << "Da tao file CSV moi: " << filePath << std::endl;
    return true;
}
