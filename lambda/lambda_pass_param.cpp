#include <functional>
#include <iostream>


// std::function 클래스 템플릿은 어떤 함수라도 매개 변수로 받을 수 있다 
// <int 부분은 함수의 리턴 자료형이고,  ()괄호 안은 파라미터임
void testFunc(const char *psz_param, std::function<int(const char*, int)> param) {
    std::cout << psz_param << std::endl;
    int result = param("hello", 10);
    std::cout << "result: " << result << std::endl;
}

int main(int argc, char *argv[]) {
    ::testFunc(
        "testFunc()",
        // 두 번째 인자는 람다함수,  파라미터는 2개, (char, int) 그리고 -> 의 자료형 int 는 리턴 자료형임
        [](const char *psz_param, int n_param) -> int {
            std::cout << psz_param << " : " << n_param << std::endl;
            return 0; // 람다 함수 리턴
        }
    );

    std::cout << "done\n";

    return 0;
}

// 람다 함수 자체를 다른 함수의 매개변수: 파라미터로 넘기는 방법
// testFunc() 함수 내에서 param 파라미터 자체가 람다 함수로 정의되어 있는 것임  
// main에서 testFunc()을 호출하게 되면, 두개의 파라미터가 넘어가는데, 하나는 문자열, 두번째는 람다 함수 자체
// 그러면 testFunc()에서 첫번째 파라미터 스트링을 프린트를 하고  
// 다시 param()으로 (2번째 파라미터로 받은: 람다) 호출을 하게 된다. 
// 그러면 param()에서 즉, 람다함수에 정의되어 있는 파라미터 형식으로 람다를 호출하게 됨
// 그래서 람다함수를 실행하고 리턴을 하게 되고 끝나게 됨

// 아흐 복잡하다 ㅠ
// 이름 없는 함수를 호출한 함수 testFunc()에서 매개변수로 넘겨주면서 다시 함수내에서 다시 또 람다함수를 실행할 수 있게 한것


