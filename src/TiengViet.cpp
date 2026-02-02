#include "TiengViet.hpp"

// Constructor
TiengViet::TiengViet() : nghia("") {}

TiengViet::TiengViet(const std::string& nghia) : nghia(nghia) {}

// Getters and Setters
std::string TiengViet::getNghia() const {
    return nghia;
}

void TiengViet::setNghia(const std::string& nghia) {
    this->nghia = nghia;
}

// Display method
void TiengViet::hienThi() const {
    std::cout << "Nghia tieng Viet: " << nghia << std::endl;
}
