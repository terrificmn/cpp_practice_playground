#include "child.h"

/// 여기에서 동일한 점은 Parent 형식으로 리턴해주는 및 파라미터까지 같다. 다만, 리턴만 unique_ptr로 만들어서 넘겨준다.
std::unique_ptr<Parent> Child::passPointer() const { 
    return std::make_unique<Child>(*this);
}

void Child::testWhoAmI() const {
    std::cout << "this is Child class" << std::endl;
}