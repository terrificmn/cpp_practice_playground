#include <iostream>
#include <string>

// Step 1: Template class definition
template <typename T>
class TemplateA {
public:
    T value;
    std::string name;

    // Constructor to initialize the value and name
    TemplateA(T val, const std::string& name_str) : value(val), name(name_str) {}

    // Method to print the name and value
    void print() const {
        std::cout << "member variable's 'value' is : " << value << ". and 'name' is " << name << std::endl;
    }
};

// Step 2: Macro to help instantiate the class with a specific name
#define INSTANTIATE_CLASS_WITH_NAME(type, value, name) \
    TemplateA<type> name(value, #name)

// Step 3: Example usage
int main() {
    // 이를 매크로로 활용하면 아래처럼 
    // Instantiate the class with different types and names
    INSTANTIATE_CLASS_WITH_NAME(int, 10, robot);
    INSTANTIATE_CLASS_WITH_NAME(std::string, "Hello, World!", greeting);

    // Use the objects, 위에 macro를 직접 입력한다면 ...
    TemplateA<int> test(10, "hello"); 
    
    test.print();
    robot.print();
    greeting.print();

    return 0;
}