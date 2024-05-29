#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <memory>

// factory function 만들기 : 클래스의 멤버 변수를 상황에 맞게 사용할 수 있다.
class A {
public:
    std::unique_ptr<int> robot;
    std::unique_ptr<int> id;
    std::unique_ptr<std::string> name;

    // Function to print the member values
    void print() const;

    // Static factory method to create instances of A with selected members
    static A createA(const std::unordered_set<std::string>& memberNames);
};

#endif