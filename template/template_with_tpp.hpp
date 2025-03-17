#ifndef TEMPLATE_WITH_TPP_HPP
#define TEMPLATE_WITH_TPP_HPP
#include <iostream>
#include <sstream>
#include "template_with_tpp.tpp"

void myFuntion();

template<typename T>
void myPrint(const T& msg);

template<typename... Args>
void myPrint(const Args&... args);


#endif // TEMPLATE_WITH_TPP_HPP