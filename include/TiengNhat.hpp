#ifndef TIENGNHAT_HPP
#define TIENGNHAT_HPP

#include <string>
#include <iostream>

class TiengNhat {
private:
    std::string kanji;    // Kanji representation
    std::string hiragana; // Hiragana reading
    std::string romaji;   // Romaji reading (optional but useful)

public:
    // Constructor
    TiengNhat();
    TiengNhat(const std::string& kanji, const std::string& hiragana, const std::string& romaji = "");

    // Getters and Setters
    std::string getKanji() const;
    void setKanji(const std::string& kanji);

    std::string getHiragana() const;
    void setHiragana(const std::string& hiragana);

    std::string getRomaji() const;
    void setRomaji(const std::string& romaji);

    // Display method
    void hienThi() const;
};

#endif // TIENGNHAT_HPP
