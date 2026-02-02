#ifndef UTILS_H
#define UTILS_H

#include <string>

// Utility functions for the application
namespace Utils {
    // Print a decorated header
    void printHeader(const std::string& title);
    
    // Print a separator line
    void printSeparator();
    
    // Get greeting in Japanese based on time
    std::string getGreeting();
}

#endif // UTILS_H
