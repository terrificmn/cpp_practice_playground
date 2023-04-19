#include "example_a.h"

ExampleA* PtrExampleA = nullptr;

// 생성자에서 바로 할당
ExampleA::ExampleA() {
	PtrExampleA = this;
    std::cout << "ExampleA class has been constructed" << std::endl;
}

void ExampleA::printHello() {
	std::cout << "hello" << std::endl;
}