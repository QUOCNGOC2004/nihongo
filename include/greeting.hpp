#ifndef GREETING_HPP
#define GREETING_HPP

#include <string>

// Demo: File mới này sẽ tự động được CMake phát hiện!
class Greeting {
public:
    static void welcome();
    static void goodbye();
};

#endif // GREETING_HPP
