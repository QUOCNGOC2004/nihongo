#include "flashCard.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

flashCard::flashCard(const std::string& tv, const std::string& tn, const std::string& gc, time_t t) 
    : TiengViet(tv), TiengNhat(tn), GhiChu(gc) {
    // Nếu timestamp = 0, sử dụng thời gian hiện tại
    timestamp = (t == 0) ? time(nullptr) : t;
}


void flashCard::hienThi() const {
    std::cout << "Tieng Viet: " << this->TiengViet;
    std::cout << " | Tieng Nhat: " << this->TiengNhat;
    std::cout << " | Ghi Chu: " << this->GhiChu;
    std::cout << " | Time: " << getFormattedTime() << std::endl;
}


void flashCard::setGhiChu(const std::string& gc) {
    this->GhiChu = gc;
}

void flashCard::setTiengViet(const std::string& tv) {
    this->TiengViet = tv;
}

void flashCard::setTiengNhat(const std::string& tn) {
    this->TiengNhat = tn;
}

void flashCard::setTimestamp(time_t t) {
    this->timestamp = t;
}



std::string flashCard::getGhiChu() const {
    return this->GhiChu;
}

std::string flashCard::getTiengViet() const {
    return this->TiengViet;
}

std::string flashCard::getTiengNhat() const {
    return this->TiengNhat;
}

time_t flashCard::getTimestamp() const {
    return this->timestamp;
}

std::string flashCard::getFormattedTime() const {
    struct tm* timeinfo = localtime(&timestamp);
    std::ostringstream oss;
    oss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

std::string flashCard::getAll() const {
    return "Tieng Viet: " + this->TiengViet + ", Tieng Nhat: " + this->TiengNhat + ", Ghi Chu: " + this->GhiChu + ", Time: " + getFormattedTime();
}