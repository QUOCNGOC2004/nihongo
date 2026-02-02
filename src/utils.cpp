#include "utils.h"
#include <iostream>
#include <ctime>

namespace Utils {
    void printHeader(const std::string& title) {
        std::cout << "\n";
        printSeparator();
        std::cout << "  " << title << "\n";
        printSeparator();
    }
    
    void printSeparator() {
        std::cout << "========================================\n";
    }
    
    std::string getGreeting() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        int hour = ltm->tm_hour;
        
        if (hour >= 5 && hour < 12) {
            return "おはようございます (Ohayou gozaimasu - Good morning)";
        } else if (hour >= 12 && hour < 18) {
            return "こんにちは (Konnichiwa - Good afternoon)";
        } else {
            return "こんばんは (Konbanwa - Good evening)";
        }
    }
}
