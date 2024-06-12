#include "static_variable.h"

MyStatic::MyStatic() {
    std::cout << "hello static. this is the constructor of MyStatic.\n";
}
MyStatic::~MyStatic() {}

/// static 함수
void MyStatic::myStaticFunc() {
    std::cout << "This is a static function!\n";
    std::cout << "also static function can deal with only static variable, " <<  s_variable << std::endl;
    // this 등의 키워드를 사용할 수가 없다.
}

int MyStatic::s_variable = 10;
