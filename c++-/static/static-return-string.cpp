#include "static-return-string.hpp"

// DO NOT include the "static" keyword here in the definition (in a cpp file)
std::string MyClass::getStaticString() {
    std::string localStr = "Hello from static function!";
    return localStr; 
    // Modern C++ automatically optimizes this return using RVO (Return Value Optimization)
}

// Example of returning a reference to a function-local static variable
const std::string& MyClass::getPersistentString() {
    // This variable is initialized only once and persists across function calls
    static const std::string staticStr = "I am a persistent static string";
    return staticStr;
}


int main() {
    ///  static functions belong to the class type, not an instance.
    // They are called directly using the scope resolution operator (::).
    std::string result_str1 = MyClass::getStaticString();
    std::string result_str2 = MyClass::getPersistentString();
    
    std::cout << result_str1 << std::endl;
    std::cout << result_str2 << std::endl;       

    return 0;
}

// g++ -o static-return-string static-return-string.cpp