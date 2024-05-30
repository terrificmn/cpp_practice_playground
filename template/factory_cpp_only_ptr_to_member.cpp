#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <memory>

// factory function 만들기 : 클래스의 멤버 변수를 상황에 맞게 사용할 수 있다.

class A {
public:
    std::shared_ptr<int> robot;
    std::shared_ptr<int> id;
    std::shared_ptr<std::string> name;

    std::unordered_map<std::string, std::shared_ptr<int>> ptr_map;

    // Function to print the member values
    void print() const {
        if (robot) std::cout << "robot: " << *robot << std::endl;
        if (id) std::cout << "id: " << *id << std::endl;
        if (name) std::cout << "name: " << *name << std::endl;
    }

    // Static factory method to create instances of A with selected members
    static A createA(const std::unordered_set<std::string>& memberNames) {
        A a;

        for (const auto& name : memberNames) {
            if (name == "robot") {
                a.robot = std::make_shared<int>(0); // or any default value
            } else if (name == "id") {
                a.id = std::make_shared<int>(0); // or any default value
            } else if (name == "name") {
                a.name = std::make_shared<std::string>(""); // or any default value
            }
        }

        std::cout << "a robot : " << *a.robot << std::endl;
        //unorder_map을 만들어서 원하는 멤버 변수를 매칭을 시켜주고, 이를 unordered_map에 다가 대입해서, 실제 바꾸고자 하는 변수를 바꿔준다.
        // ptr_map 의 키 중에 "robot"이 있고 ----> 이것의 벨류는 robot member변수로 지정되어 있음
        // 이제 어떤 스트링, 키와 동일하다면 해당 벨류로 변경시켜준다.
        a.ptr_map["robot"] = a.robot;
        int test_value = 333;
        auto it = a.ptr_map.find("robot");
        if(it != a.ptr_map.end()) {
            *(it->second) = test_value;
        } else {
            std::cerr << " not found robot" << std::endl;
        }

        std::cout << "after -------------\n";
        std::cout << "a robot : " << *a.robot << std::endl;
        return a;
    }

    void setPtrMember(const std::unordered_set<std::string>& memberNames) {
        // this->ptr_map["robot"] = std::make_unique<int>(10);
        this->ptr_map["robot"] = this->robot;
    }
};


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


// g++ -std=c++14 -o factory_ptr_member factory_cpp_only_ptr_to_member.cpp 