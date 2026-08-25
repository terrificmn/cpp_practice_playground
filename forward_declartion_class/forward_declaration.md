# forward_declaration
2개의 header 파일에서 서로 교차해서 인쿠르드를 하는 경우에 무한으로 계속 반복적으로(cycle) 반복이 되는데,  
이때 #ifndef 등을 만나서 더 이상 인크루드를 하지 않게 되고  

그래서 2개의 중의 하나의 cpp 파일에서는 필요한 클래스, 변수, 함수 등을 찾지 못하게 된다.  

그래서 필요한 경우에 forward declaration 을 이용해서 헤더파일에서 적어주면 된다.   

일단 forward declaration 은 class, struct, pointer 등 함수 등에서 정의하고 있는 타입 등을 사용할 수 있게 해준다.  
그래서 빌드할 경우에 문제 없이 넘어감.   


만약 A 클래스에서 B 클래스의 특정 타입 또는 포인터 등만 정의해 준다면 크게 문제 없이 사용이 가능  

A 클래스의 header 파일에 정의 
```cpp
#ifndef THIS_IS_ACLASS
#define THIS_IS_ACLASS

class BClass;  // forward declaration 이러면 끝

struct AClassMySturct {
    std::string my_name;
    int type;
};

class AClass {
    public:
        AClass(std::shared_ptr<BClass>);
        
    private:
        int my_number;
};
```

이렇게 하면  AClass constructor 에서 BClass 타입을 문제 없이 빌드할 수 있게 된다.   


B 클래스에서는 실제  A클래스에 있는 struct 등을 사용한다고 하면...

```cpp
#ifndef THIS_IS_BCLASS
#define THIS_IS_BCLASS

#include "a_class.hpp"

class BClass {
    public:
        BClass();

        AClassMyStruct myStruct;

};
```

기존 방식처럼 include 를 해서 사용하면 된다.   


> 물론 뭔가 공통으로 사용되거나 하는 것이 있으면 따로 header 파일을 만들어서 2개의 클래스에서 include 를 직접 하는 방식으로   
할 수도 있다.  

