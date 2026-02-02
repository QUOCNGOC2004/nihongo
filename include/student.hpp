#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
private:
    std::string name;
    int age;
    std::string level;  // N5, N4, N3, N2, N1

public:
    // Constructor
    Student(const std::string& name, int age, const std::string& level);
    
    // Getters
    std::string getName() const;
    int getAge() const;
    std::string getLevel() const;
    
    // Methods
    void introduce() const;
    void study(const std::string& topic);
};

#endif // STUDENT_HPP
