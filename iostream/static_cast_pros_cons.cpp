// 예제를 확인해보자

#include <iostream>

int main() {
    double pi = 3.14;
    int* ptr = (int*)&pi;  // Compiles, but is unsafe!
    std::cout << *ptr << std::endl;  // Undefined behavior!

    /// 주석해제 후 확인하기
    /// 컴파일에서 바로 에러가 발생한다.
    // double pi = 3.14;
    // int* ptr = static_cast<int*>(&pi);

    /// IMPORTANT: c++ ctyle cast 를 하는 이유는 Safety 때문, 유효한 conversions 만 허용하기 때문
    /// 디버깅 시에도 확실하게 찾기 편할 듯 하다. static_cast 로만 찾으면 됨
    /// Performance 는 c sytle 방식과 같다 . (int)u_red
    /// c style cast 는 간단하게 사용하기 정말 좋지만, 유효한 cast인지 체크하지 않는다.
}

// g++ -std=c++17 -o static_cast_pros static_cast_pros_cons.cpp 


