#include "student.hpp"
#include <iostream>

// Constructor implementation
Student::Student(const std::string& name, int age, const std::string& level)
    : name(name), age(age), level(level) {
}

// Getter implementations
std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

std::string Student::getLevel() const {
    return level;
}

// Method implementations
void Student::introduce() const {
    std::cout << "はじめまして！(Hajimemashite!)\n";
    std::cout << "私の名前は " << name << " です。\n";
    std::cout << "年齢: " << age << " 歳\n";
    std::cout << "レベル: " << level << "\n";
    std::cout << "よろしくお願いします！(Yoroshiku onegaishimasu!)\n";
}

void Student::study(const std::string& topic) {
    std::cout << "\n📚 " << name << " は「" << topic << "」を勉強しています...\n";
    std::cout << "頑張って！(Ganbatte! - Good luck!)\n";
}
