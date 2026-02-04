#pragma once
#include <string>
#include <ctime>

// Utility class cho các hàm xử lý timestamp
class TimeUtils {
public:
    // Chuyển timestamp thành string với format đầy đủ "YYYY-MM-DD HH:MM:SS"
    static std::string formatTimestampFull(time_t timestamp);
    
    // Chuyển timestamp thành string chỉ có ngày "YYYY-MM-DD"
    static std::string formatTimestampDate(time_t timestamp);
    
    // Chuyển string thành timestamp (format: "YYYY-MM-DD HH:MM:SS")
    static time_t parseTimestamp(const std::string& str);
};
