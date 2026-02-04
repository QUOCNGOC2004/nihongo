#include "TimeUtils.hpp"
#include <iomanip>
#include <sstream>

// Chuyển timestamp thành string với format đầy đủ "YYYY-MM-DD HH:MM:SS"
std::string TimeUtils::formatTimestampFull(time_t timestamp) {
    struct tm* timeinfo = localtime(&timestamp);
    std::ostringstream oss;
    oss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

// Chuyển timestamp thành string chỉ có ngày "YYYY-MM-DD"
std::string TimeUtils::formatTimestampDate(time_t timestamp) {
    struct tm* timeinfo = localtime(&timestamp);
    std::ostringstream oss;
    oss << std::put_time(timeinfo, "%Y-%m-%d");
    return oss.str();
}

// Chuyển string thành timestamp (format: "YYYY-MM-DD HH:MM:SS")
time_t TimeUtils::parseTimestamp(const std::string& str) {
    if (str.empty()) return time(nullptr);
    
    struct tm tm = {};
    std::istringstream ss(str);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    
    if (ss.fail()) {
        return time(nullptr); // Nếu parse thất bại, trả về thời gian hiện tại
    }
    
    return mktime(&tm);
}
