#include "flashCard.hpp"
#include <iostream>

flashCard::flashCard(const std::string& tv, const std::string& tn, const std::string& gc) 
    : TiengViet(tv), TiengNhat(tn), GhiChu(gc) {
}


void flashCard::hienThi() const {
    std::cout << "Tieng Viet: " << this->TiengViet << std::endl;
    std::cout << "Tieng Nhat: " << this->TiengNhat << std::endl;
    std::cout << "Ghi Chu: " << this->GhiChu << std::endl;
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

void flashCard::setAll(const std::string& tv, const std::string& tn, const std::string& gc) {
    this->TiengViet = tv;
    this->TiengNhat = tn;
    this->GhiChu = gc;
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

std::string flashCard::getAll() const {
    return "Tieng Viet: " + this->TiengViet + ", Tieng Nhat: " + this->TiengNhat + ", Ghi Chu: " + this->GhiChu;
}