#ifndef CLASS_A_HPP
#define CLASS_A_HPP

#include "class_a.hpp"
#include <iostream>

ClassA::ClassA() {
    std::cout << "init! " << this->m_str << std::endl;

}

ClassA::~ClassA() {
    std::cout << "Destroied!" << std::endl;
}

#endif