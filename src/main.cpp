#include "student.hpp"
#include "utils.h"
#include "greeting.hpp"  // New file - auto-detected by CMake!
#include <iostream>
#include <vector>

int main() {
    // Set console to UTF-8 for Japanese characters
    system("chcp 65001 > nul");
    
    // Print greeting
    Utils::printHeader("日本語学習アプリ (Nihongo Learning App)");
    std::cout << "\n" << Utils::getGreeting() << "\n\n";
    
    // Demo: New Greeting class (auto-detected!)
    Greeting::welcome();
    
    // Test: rebuild.bat should be faster than build.bat!
    std::cout << "💡 Tip: Sử dụng rebuild.bat để build nhanh hơn!\n\n";
    
    // Create students
    std::vector<Student> students;
    students.push_back(Student("Nguyen", 20, "N5"));
    students.push_back(Student("Tanaka", 22, "N3"));
    students.push_back(Student("Sakura", 19, "N4"));
    
    // Introduce all students
    Utils::printHeader("学生紹介 (Student Introductions)");
    for (const auto& student : students) {
        std::cout << "\n";
        student.introduce();
        Utils::printSeparator();
    }
    
    // Study session
    Utils::printHeader("勉強時間 (Study Time)");
    students[0].study("ひらがな (Hiragana)");
    students[1].study("漢字 (Kanji)");
    students[2].study("文法 (Grammar)");
    
    // Farewell
    std::cout << "\n";
    Utils::printHeader("さようなら！(Sayounara!)");
    std::cout << "\nまた明日！(Mata ashita! - See you tomorrow!)\n\n";
    
    Greeting::goodbye();
    
    return 0;
}
