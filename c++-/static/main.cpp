#include "static_variable.h"

int main() {
    // static 변수는 어떤 스코프 즉 클래스 등에 속해있더라도 실제로는 해당 스코프, 클래스 외부에서 만들어 지게 되어
    // 계속 지속적으로 사용할 수 있게 된다.

    // 그 증거로 이는 심지어 static 변수는 현재 MyStatic 클래스 안에 있지만 
    // 오브젝트 인스턴스를 안 만들어도 variable 사용이 가능하다

    // 물론 초기화는 해줘야지 사용할 수 가 있다. 초기화를 해주는 것이 정말 중요한데, 최초 한번만 define을 할 수가 있다. 
    // 헤더파일에 넣으면 multiple 정의가 되므로 cpp 파일에 넣어줘서 사용한다. 또는 main 함수 위에다 정의할 수도 있다.
    // static_variable.cpp 파일 참고

    std::cout << "static variable : " << MyStatic::s_variable << std::endl;
    std::cout << "const static can be defined with the class : " << MyStatic::s_const_var << std::endl;

    MyStatic::myStaticFunc();
    // static 함수에서는 다른 처리는 안되고 즉, member 변수, 함수등을 사용하는 것이 안되고, static관련 변수만 사용 가능, 
    // 리턴도 static 관련 내용만 리턴 가능하다

    // static 클래스 자체는 없으로 인스턴스로 해서 사용하 ㄹ수 가 있고, 특정 함수나 변수들만 static으로 사용할 수가 있다.
    // static으로 선언되면 그 해당 클래스의 scope안에 있지만 실제 메모리 할당은 클래스 외부에서 있다고 생각하면 된다.

    MyStatic myStatic;
}

// g++ -std=c++17 main.cpp static_variable.cpp -o static