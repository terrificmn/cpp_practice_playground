#include <iostream>
#include <array>

void testFunc() {
    // do something

    // error
    throw std::runtime_error("Yo runtime_error!!");
}

int main() {
    /// try catch 받지 못하는 상황에서는 바로 runtime 에러로 종료가 된다. 
    /// 심각한 오류로 실행 중에 종료가 필요할 경우에 아예 종료를 시킬 수 있다.
    // throw std::runtime_error("runtime_error!! 1");


    ///FYI: 런타임 에러나 throw 를 하게 되면 무조건 끝나는 줄, 잘못 알고 있었다.  
    // try catch로 받아줄 수 있다면 그게 함수에서 실행을 하던, nested 구조로 한 번더 try catch가 되는 상황이면
    // 처음 호출된 catch 쪽에서 에러를 잡아 낼 수가 있고, runtime_error라고 해도 종료 되지 않고 넘어갈 수 있다.  
    try {
        testFunc();
    } catch(const std::exception& e) {
        std::cerr << "catch: " << e.what() << std::endl;
    }

    //__________________________________________________________________________

    ///IMPORTANT: 해당 runtime 에러의 메세지를 파싱을 해서 다시한번 뭔가 처리를 해줄 수도 있다
    try {
        testFunc();

        /// 이렇게 catch도 많이 사용할 수 있지만, 한번 catch 가 발생한다면 그 이하는 실행이 안되게 된다. 
        // 위의 testFunc() 을 주석하고 테스트
        std::array<int, 2> a_array {1, 2};
        //// 에러 발생
        std::cout << a_array.at(3) << std::endl;

    } catch(const std::runtime_error& e) {
        std::string e_str = e.what();
        ///FYI: find rutime_error's unique string
        if(e_str.find("Yo runtime_error") != std::string::npos) {
            std::cerr << "Detected specific error: " << e.what() << std::endl;
        }
        /// 여기에서 종료하려면 throw 시킴 // 아래 주석 해제
        // throw;
    
    /// catch 는 여러개를 사용할 수 있다.
    } catch(...) {
        std::cerr << "Other error: " << std::endl;
    }

    std::cout << "Program ends here\n";
    return 0;
}

// g++ -std=c++17 nested_try.cpp -o nested_try
