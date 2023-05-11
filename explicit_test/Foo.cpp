// g++ -o explicit Foo.cpp   // 빌드 시

#include <iostream>

class Foo {
public:
    Foo(int num);
    Foo(const char ch_);

};

Foo::Foo(int num) {
    std::cout << "class Foo- Constructor1 coverted int: " << num << std::endl;
}

Foo::Foo(const char ch_) {
    std::cout << "class Foo- Constructor2 coverted char: " << ch_ << std::endl;;
}


class FooExplicit {
public:
    explicit FooExplicit(int num);
    FooExplicit(const char ch_);

};

FooExplicit::FooExplicit(int num) {
    std::cout << "class FooExplicit- Constructor1 coverted int: " << num << std::endl;
}

FooExplicit::FooExplicit(const char ch_) {
    std::cout << "class FooExplicit-Constructor2 coverted char: " << ch_ << std::endl;;
}


int main() {
    
    Foo myString = 'a';
    // 결과는 첫 번째 생성자가 생성이 되버린다 - implicitly 타입이 변환이 되어서 생성자가 자동으로 생성
    // char인 'a'였지만, int 로 만들어짐

    FooExplicit myStringExplicit = 'a';
    // 이름만 다른 클래스 이지만 int를 받는 생성자에서 explicit 키워드가 있어서   
    // 자동변환이 되지 않고, type char에 맞는 생성자가 실행이 되어서 'a'가 출력

    // explicit은 원치않는 결과가 나오지 않게 하기 위해서 키워드로 생성자 앞에 넣어서 만들게 된다

    return 0;
}

