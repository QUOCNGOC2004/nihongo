#pragma once
#include <vector>
#include <string>
#include "flashCard.hpp"

class StudyHelper {
public:
    // Xáo trộn mảng từ vựng (thay đổi trực tiếp mảng truyền vào)
    static void shuffleCards(std::vector<flashCard>& cards);
    
    // Lấy bản sao đã xáo trộn của toàn bộ từ vựng (không thay đổi mảng gốc)
    static std::vector<flashCard> getShuffledCards(const std::vector<flashCard>& cards);
    
    // Lọc từ vựng theo ngày (format: "YYYY-MM-DD")
    static std::vector<flashCard> getCardsByDate(const std::vector<flashCard>& cards, const std::string& date);
    
    // Lọc từ vựng theo ngày và xáo trộn
    static std::vector<flashCard> getShuffledCardsByDate(const std::vector<flashCard>& cards, const std::string& date);
    
private:
    // Hàm helper: Chuyển timestamp thành string ngày "YYYY-MM-DD"
    static std::string timestampToDateString(time_t timestamp);
};
