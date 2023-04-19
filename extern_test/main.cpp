#include "example_a.h"
#include "example_b.h"

int main () {

	ExampleA A_class_object;
    A_class_object.printHello();
    
	ExampleB B_class_object;
	B_class_object.doSomething();
	
    return 0;
}