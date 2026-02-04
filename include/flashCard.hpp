#pragma once
#include <string>
#include <iostream>
#include <ctime>

class flashCard {
private:
    std::string TiengViet;
    std::string TiengNhat;
    std::string GhiChu;
    time_t timestamp;

public:

    flashCard(const std::string& tv, const std::string& tn, const std::string& gc, time_t t = 0);

    void hienThi() const;

    void setGhiChu(const std::string& gc);
    void setTiengViet(const std::string& tv);
    void setTiengNhat(const std::string& tn);
    void setTimestamp(time_t t);

    std::string getGhiChu() const;
    std::string getTiengViet() const;
    std::string getTiengNhat() const;
    std::string getAll() const;
    time_t getTimestamp() const;
};