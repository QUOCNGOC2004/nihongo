#include <iostream>
#include <vector>
#include "TiengViet.hpp"
#include "TiengNhat.hpp"
#include <windows.h> // For setting console output code page

int main() {
    // Set console output to UTF-8 to display Vietnamese marks and Kanji correctly
    SetConsoleOutputCP(65001);

    std::cout << "=== Test Flashcards ===" << std::endl;

    // Test TiengViet
    TiengViet tv1("Quả táo");
    std::cout << "Vietnamese Side: ";
    tv1.hienThi();

    // Test TiengNhat
    TiengNhat tn1("林檎", "りんご", "ringo");
    std::cout << "Japanese Side: ";
    tn1.hienThi();

    // Combined usage simulation
    std::cout << "\n--- Card Pair ---" << std::endl;
    TiengViet vnCard("Nguoi hoc"); // Learner/Student
    TiengNhat jpCard("学生", "がくせい", "gakusei");

    vnCard.hienThi();
    jpCard.hienThi();

    return 0;
}
