#include <iostream>
#include <memory>

// Base class
class Base {
public:
    virtual ~Base() = default;

    // Virtual function to return a std::unique_ptr to Base
    virtual std::unique_ptr<Base> clone() const = 0;

    virtual void display() const = 0;
};

// Derived class 1
class Derived1 : public Base {
public:
    std::unique_ptr<Base> clone() const override {
        return std::make_unique<Derived1>(*this); // Covariant return type with smart pointer
    }

    void display() const override {
        std::cout << "Derived1 instance" << std::endl;
    }
};

// Derived class 2
class Derived2 : public Base {
public:
    std::unique_ptr<Base> clone() const override {
        return std::make_unique<Derived2>(*this); // Covariant return type with smart pointer
    }

    void display() const override {
        std::cout << "Derived2 instance" << std::endl;
    }
};

// Function to demonstrate cloning
void demonstrateCloning(const Base& obj) {
    // Clone the object
    std::unique_ptr<Base> clonedObj = obj.clone();
    
    // Display the cloned object
    clonedObj->display();
}

int main() {
    Derived1 d1;
    Derived2 d2;

    // Demonstrate cloning
    demonstrateCloning(d1);
    demonstrateCloning(d2);
    
    // 바로 적용한다면, 재미 있는 점은 Base 를 상속받아서 넘겨줄 수가 있고,  clone()이 override함수로 실행되면서 자기 포인터를 넘겨주는 것이 포인트다.
    std::unique_ptr<Base> obj = d1.clone();
    /// 넘겨줄 데이터가 서로 다를 경우 하나의 데이터로 만들기가 여려운데, 예를 들어 이 경우도 상속을 안 받았다고 하면,
    /// Base와 Derived1 은 다르기 때문에 위의 코드가 에러가 날 수 밖에 없다.
    /// 같은 클래스 혹은 type을 유지할 경우에 위의 방식이 도움이 많이 될 듯 하다.

    // dynamic_cast로 위와 비슷한 효과를 낼 수 있다. runtime에서 실행되며 좋은점이 많다고 함.

    return 0;
}