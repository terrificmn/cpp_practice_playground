#include "example_b.h"

ExampleB::ExampleB() {
    std::cout << "ExampleB class has been constructed" << std::endl;
}
ExampleB::~ExampleB() {
}

void ExampleB::doSomething() {
    std::cout << "ExampleB class uses a method of Example class >> ";
	PtrExampleA->printHello();
}
