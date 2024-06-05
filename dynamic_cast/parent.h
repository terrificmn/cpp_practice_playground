#ifndef PARENT_H
#define PARENT_H

#include <memory>
#include <iostream>

class Parent {
public:
    virtual ~Parent() = default;
    virtual std::unique_ptr<Parent> passPointer() const = 0;  // 0을 해놓으면 cpp파일에는 정의를 안해도 되고, 이렇게 되면
    // 상속 받는 클래스에서 override 해서 사용을 해야한다.
    virtual void testWhoAmI() const = 0;

    void commonMethod(const std::string& str);  // virtual 이 아니면 부모의 메소드, 자식클래스에서 사용가능
};

#endif

