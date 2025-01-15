#include <iostream>
#include <functional>

/// suffix PFn Point Function을 의미
typedef int (*PFntIntergerOperation)(int, int);

int add(int x, int y) {
    return x+y;
}

int multiply(int x, int y) {
    return x*y;
}

int main() {
    // function pointer for functions: 
    /// 1. 방식
    // 리턴타입 함수이름(파라미터1 타입, 파라미터2 타입);
    // 예: int name(int, int)
    int (*op)(int, int);

    /// 2. 방식 typedef 를 먼저 정의 해놓고 만드는 방법이 있다.
    PFntIntergerOperation pf_op;

    /// 3. 방식
    std::function<int(int, int)> std_pf_op;

    // 기존의 함수를 호출할 경우에는 아래 처럼 보통 사용하지만
    std::cout << add(10, 20) << std::endl;
    std::cout << multiply(10, 20) << std::endl;

    /// function pointer 를 사용하게 되면 좀 더 유연하게 사용할 수 가 있고, 특정 event 가 발생하는 경우에 함수를 다르게 사용할 경우에 사용을 많이 한다고 함
    std::cout << "1 for add or 2 for multiply..." << std::endl;
    int n;
    std::cin >> n;

    if(n == 1) {
        op = add;
        pf_op = add;
        std_pf_op = add;
    } else if(n == 2) {
        op = multiply;
        pf_op = multiply;
        std_pf_op = multiply;
    }

    std::cout << "Now type numbers at one for each time." << std::endl;
    int x, y;
    std::cin >> x;
    std::cin >> y;
    std::cout << "1.function pointer, result: " << op(x, y) << std::endl;
    std::cout << "2.function pointer, result: " << pf_op(x, y) << std::endl;
    std::cout << "3.function pointer, result: " << std_pf_op(x, y) << std::endl;

    

    return 0;
}


// g++ -std=c++17 -o function_pointer function_pointer.cpp 