#pragma once
#include <string>
#include <iostream>

class flashCard {
private:
    std::string TiengViet;
    std::string TiengNhat;
    std::string GhiChu;

public:

    flashCard(const std::string& tv, const std::string& tn, const std::string& gc);

    void hienThi() const;

    void setGhiChu(const std::string& gc);
    void setTiengViet(const std::string& tv);
    void setTiengNhat(const std::string& tn);
    void setAll(const std::string& tv, const std::string& tn, const std::string& gc);

    std::string getGhiChu() const;
    std::string getTiengViet() const;
    std::string getTiengNhat() const;
    std::string getAll() const;
};