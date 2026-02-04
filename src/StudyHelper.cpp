#include "StudyHelper.hpp"
#include "TimeUtils.hpp"
#include <algorithm>
#include <random>

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
