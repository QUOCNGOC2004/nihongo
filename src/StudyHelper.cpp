#include "StudyHelper.hpp"
#include "TimeUtils.hpp"
#include <algorithm>
#include <random>
#include <set>

// Xáo trộn mảng từ vựng
void StudyHelper::shuffleCards(std::vector<flashCard>& cards) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(cards.begin(), cards.end(), gen);
}

// Lấy bản sao đã xáo trộn
std::vector<flashCard> StudyHelper::getShuffledCards(const std::vector<flashCard>& cards) {
    std::vector<flashCard> shuffled = cards; // Tạo bản sao
    shuffleCards(shuffled);
    return shuffled;
}



// Lọc từ vựng theo ngày
std::vector<flashCard> StudyHelper::getCardsByDate(const std::vector<flashCard>& cards, const std::string& date) {
    std::vector<flashCard> filtered;
    
    for (const auto& card : cards) {
        std::string cardDate = TimeUtils::formatTimestampDate(card.getTimestamp());
        if (cardDate == date) {
            filtered.push_back(card);
        }
    }
    
    return filtered;
}

// Lọc theo ngày và xáo trộn
std::vector<flashCard> StudyHelper::getShuffledCardsByDate(const std::vector<flashCard>& cards, const std::string& date) {
    std::vector<flashCard> filtered = getCardsByDate(cards, date);
    shuffleCards(filtered);
    return filtered;
}

// Lấy danh sách các ngày duy nhất
std::vector<std::string> StudyHelper::getUniqueDates(const std::vector<flashCard>& cards) {
    std::set<std::string> dateSet;
    
    // Thu thập tất cả các ngày duy nhất
    for (const auto& card : cards) {
        std::string cardDate = TimeUtils::formatTimestampDate(card.getTimestamp());
        dateSet.insert(cardDate);
    }
    
    // Chuyển từ set sang vector và sắp xếp giảm dần (mới nhất trước)
    std::vector<std::string> dates(dateSet.begin(), dateSet.end());
    std::sort(dates.begin(), dates.end(), std::greater<std::string>());
    
    return dates;
}
