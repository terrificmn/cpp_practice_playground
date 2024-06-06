#include <iostream>
#include <unordered_map>
#include <any>
#include <string>

int main() {
    std::unordered_map<std::string, std::any> myMap;
    
    myMap["integer"] = 42;
    myMap["double"] = 3.14;
    myMap["string"] = std::string("Hello");

    // Accessing and printing the values
    for (const auto& [key, value] : myMap) {
        std::cout << key << ": ";
        if (value.type() == typeid(int)) {
            std::cout << std::any_cast<int>(value) << std::endl;
        } else if (value.type() == typeid(double)) {
            std::cout << std::any_cast<double>(value) << std::endl;
        } else if (value.type() == typeid(std::string)) {
            std::cout << std::any_cast<std::string>(value) << std::endl;
        }
    }

    return 0;
}

// 17 이상 부터 가능, std::variant 로 있다고 함(17이상)
// g++ -std=c++17 -o any unordered_map_any.cpp 