#ifndef REFERENCE_KEY_H
#define REFERENCE_KEY_H
#include "bool_key.h"
#include <unordered_map>


// Parent class of BoolKey, IntKey, DoubleKey, StringKey, VectorKey
class ReferenceKeys {
public:
    virtual ~ReferenceKeys() = default;

};
#endif

int main() {
    std::unordered_map<std::string, std::shared_ptr<ReferenceKeys>> my_map;
    std::shared_ptr<bool> available = std::make_shared<bool>();
    my_map["available"] = std::make_shared<BoolKey>(available);

    // 이런식으로 unordered_map 을 클래스로 묶어서 처리할 수가 있다. 예를 들어서 BoolKey 컨스트럭터를 보면 포인터를 받아서 자기 멤버 변수에 
    // 저장하는 식으로 할 수가 있다. 
    // 만약 컨스트럭터를 pointer를 받지 않고, 값을 직접 받게 해서 넣어줄 수도 있다. 
    // 
    // 이걸 하는 이유는 흠.. 일단 std=c++14 에서는 다양한 형식으로 unordered_map을 조합할 수가 없다.  
    // 이거를 클래스로 묶어서 unoreder_map 에 다양한 클래스 (type별로) 조합을 할 수 있다는 점이 재미 있으나,  
    // 그래서 위의 available 이라는 smart 포인터의 값을 map을 이용해서 '키' 입력으로만 연결해서 추후 "available"
    // 키만 입력했을 때 실제 데이터가 변경될 수 있게 하려는 목적임.

    // 단
    std::cout << "available : " << *available << std::endl;
    // 위에서  my_map["available"] = std::make_shared<BoolKey>(available); 부분은 포인터를 넘겨준 부부인데, 이제 실제 데이터를 넣을려고 하면 어려움이 있다.
    my_map["available"] = true;  // 이런식으로 줄 수가 없다. smart_point bool 으로 되어 있었다면 바로 값을 derefence 할 수 있었겠지만, 
    // type이 스마트 포인터 클래스를 넘겨야 해서 그렇다.
    // 아마도 컨스트럭터를 다른 형식을 받아서, 포인터가 아닌 벨류를 받아보는 방법도 있을 듯 하다.
    my_map["available"] = std::make_shared<BoolKey>(true); // value를 받는 컨스트럭터를 만들어 본다.;;
    // 이렇게도 복잡하나 것이 먼저 available ptr을 가지고 있는 BoolKey의 멤버 변수에 값을 넣어줘야 key 만으로 값을 바꾸는데 그 과정이 너무 번잡한 듯 하다.
    // 아마도 포인터가 아닌 벨류를 받는 클래스에서 해당 member 포인터(available)을 가리키는 변수에 값을 할당해 주는 식으로 할 수 있을 것 같기도 하지만, 테스트 안해봄

    // 어쨋든 참고만 하자 ㅋㅋㅋ 그리고 cpp 17 버전이상에서는 std::any 등 다양한 unordered_map 에서 다양하게 타입을 받을 수 있다고 한다. 끝

}