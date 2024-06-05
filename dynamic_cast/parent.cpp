#include "parent.h"
#include "child.h"

//// Parent::Parent() {}
//// Parent::~Parent() {} 
// virtual ~Parent() = default; 로 header파일에 정의할 경우에 위 처럼 사용할 필요가 없어진다. 디폴트 디스트럭터 사용
void Parent::commonMethod(const std::string& str) {
    std::cout << "hello using parent's method: " << str << std::endl;
}


int main() {
    // 자식 클래스를 만든다.
    Child child;
    /// 부모 클래스를 unique_ptr로 만든다.
    std::unique_ptr<Parent> parentObj = child.passPointer();

    /// parent 인스턴스로 만들었는데 상속 받아서 override된 passPointer를 사용하게 되면 자식 클래스의 override 된 메소드 접근이 가능
    parentObj->testWhoAmI();
    parentObj->commonMethod("hello from main");

}

// g++ -std=c++14 -o parent-child-pass parent.cpp child.cpp