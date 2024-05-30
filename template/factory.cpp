#include "factory.h"

// Function to print the member values
void A::print() const {
    if (robot) std::cout << "robot: " << *robot << std::endl;
    if (id) std::cout << "id: " << *id << std::endl;
    if (name) std::cout << "name: " << *name << std::endl;
}


/// 현재 g++ 로 돌릴경우에는 별로 문제가 안되는데 -std=c++14  멤버 변수가 unique_ptr 일 경우에는 컴파일 에러가 발생할 수 있다.
/// A 클래스가 deleted 삭제 될 수 있다. copy나 이동이 안되는 unique_ptr이어서 그렇다. 쉽게 고치려면 shared_ptr로 바꾸면 해겷할 수 있다.
/* error: use of deleted function A::A(const A&)’
   28 |     return A;
*/

// Static factory method to create instances of A with selected members
A A::createA(const std::unordered_set<std::string>& memberNames) {
    A a;

    for (const auto& name : memberNames) {
        if (name == "robot") {
            a.robot = std::make_unique<int>(0); // or any default value
        } else if (name == "id") {
            a.id = std::make_unique<int>(0); // or any default value
        } else if (name == "name") {
            a.name = std::make_unique<std::string>(""); // or any default value
        }
    }

    return a;
}


int main() {
    // Example 1: Create an instance with "robot" and "id"
    A a1 = A::createA({"robot", "id"});
    if (a1.robot) *a1.robot = 42;
    if (a1.id) *a1.id = 101;
    std::cout << "a1:" << std::endl;
    a1.print();

    // Example 2: Create an instance with "robot", "id", and "name"
    A a2 = A::createA({"robot", "id", "name"});
    if (a2.robot) *a2.robot = 43;
    if (a2.id) *a2.id = 102;
    if (a2.name) *a2.name = "RobotName";
    std::cout << "a2:" << std::endl;
    a2.print();

    // Example 3: Create an instance with "name" only
    A a3 = A::createA({"name"});
    if (a3.name) *a3.name = "OnlyName";
    std::cout << "a3:" << std::endl;
    a3.print();

    return 0;
}


// g++ -std=c++14 -o factory factory.cpp