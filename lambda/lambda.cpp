#include <iostream>

int functionTest(int n_param) {
    std::cout << "Function Pointer: " << n_param << std::endl;
    return n_param;
}

int main(int argc, char *argv[]) {
    // 람다식 선언
    // 이름이 없는 함수로, 
    /*
    [](파라미터가 온다) -> 화살표 지정에는 리턴자료형을 명시해준다 { 
        ...블럭안에 코드 작성
    }
    이를 auto로 변수를 하나 만들고 할당을 해주면 람다 함수 완성
    */
    auto func = [](int n_param) -> int {
        std::cout << "Lambda: " << n_param << std::endl;
        return n_param;
    };

    // call lambda function
    func(5);

    // 함수 포인터 호출
    // 함수포인터는 auto로 변수를 만들어서 기존 함수의 주소를 넘겨서 funtion pointer가 되게 하는 것  
    // 그래서 auto로 만들어진 변수를 함수처럼 사용하게 된다 
    // 이 함수포인터는 C sytle 이라고 할 수 있다 
    auto fpTest = functionTest;
    fpTest(10);

    return 0;
}