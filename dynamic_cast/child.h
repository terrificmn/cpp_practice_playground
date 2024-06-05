#ifndef CHILD_H
#define CHILD_H

#include <memory>
#include <iostream>
#include "parent.h"

class Child : public Parent {
public:
    std::unique_ptr<Parent> passPointer() const override;  // override해서 사용
    void testWhoAmI() const override;

};

#endif

