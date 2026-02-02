#include "TiengNhat.hpp"

// Constructor
TiengNhat::TiengNhat() : kanji(""), hiragana(""), romaji("") {}

TiengNhat::TiengNhat(const std::string& kanji, const std::string& hiragana, const std::string& romaji)
    : kanji(kanji), hiragana(hiragana), romaji(romaji) {}

// Getters and Setters
std::string TiengNhat::getKanji() const {
    return kanji;
}

void TiengNhat::setKanji(const std::string& kanji) {
    this->kanji = kanji;
}

std::string TiengNhat::getHiragana() const {
    return hiragana;
}

void TiengNhat::setHiragana(const std::string& hiragana) {
    this->hiragana = hiragana;
}

std::string TiengNhat::getRomaji() const {
    return romaji;
}

void TiengNhat::setRomaji(const std::string& romaji) {
    this->romaji = romaji;
}

// Display method
void TiengNhat::hienThi() const {
    std::cout << "Kanji: " << kanji << " | Hiragana: " << hiragana;
    if (!romaji.empty()) {
        std::cout << " | Romaji: " << romaji;
    }
    std::cout << std::endl;
}
