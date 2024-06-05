#include <iostream>
#include <memory>
#include <vector>

class Base {
public:
    virtual ~Base() = default;  // Polymorphic base class with a virtual destructor
};

class Derived1 : public Base {
public:
    void show() {
        std::cout << "Derived1::show()" << std::endl;
    }
};

class Derived2 : public Base {
public:
    void display() {
        std::cout << "Derived2::display()" << std::endl;
    }
};

void process(Base* base) {
    if (Derived1* d1 = dynamic_cast<Derived1*>(base)) {
        d1->show();  // Safe to call Derived1 methods
    } else if (Derived2* d2 = dynamic_cast<Derived2*>(base)) {
        d2->display();  // Safe to call Derived2 methods
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

int main() {
    std::vector<std::unique_ptr<Base>> objects;
    objects.push_back(std::make_unique<Derived1>());
    objects.push_back(std::make_unique<Derived2>());
    objects.push_back(std::make_unique<Derived1>());

    for (auto& obj : objects) {
        process(obj.get());
    }

    return 0;
}