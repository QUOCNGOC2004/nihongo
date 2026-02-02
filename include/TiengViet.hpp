#ifndef TIENGVIET_HPP
#define TIENGVIET_HPP

#include <string>
#include <iostream>

class TiengViet {
private:
    std::string nghia; 

public:
    // Constructor
    TiengViet();
    TiengViet(const std::string& nghia);

    // Getters and Setters
    std::string getNghia() const;
    void setNghia(const std::string& nghia);

    // Display method
    void hienThi() const;
};

#endif // TIENGVIET_HPP
