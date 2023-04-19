#include "pointer_class.h"

PointerClass::PointerClass() {
    std::cout << "Pointer Class Init" << std::endl;
}

PointerClass::~PointerClass() {
    std::cout << "Pointer Class Destructed" << std::endl;
}

void PointerClass::testCout() {
    std::cout << "test test test print string. ";
    std::cout << "number is: " << this->number << std::endl;
}


int main(int argc, char** argv) {

    PointerClass* ptr_class = nullptr;
    printf("First Address nullptr: %p\n", ptr_class);

    // PointerClass* ptr_class = new PointerClass; //  한번에 만들 때는 nullptr을 줄 필요가 없음
    ptr_class = new PointerClass;
    printf("Address after new : %p\n", ptr_class);

    delete ptr_class;
    ptr_class->testCout();
    ptr_class = nullptr;
    ptr_class->testCout();
    printf("Address after delete : %p\n", ptr_class);

    return 0;
}