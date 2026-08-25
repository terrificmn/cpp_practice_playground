#ifndef MY_CLASS_HPP
#define MY_CLASS_HPP

#include <string>
#include <iostream>

class MyClass {
public:
    // Declare the function as static here
    static std::string getStaticString();
    
    // Alternative: Return by const reference if returning a persistent static variable
    static const std::string& getPersistentString();
};

#endif // MY_CLASS_HPP