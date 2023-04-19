#include <cstdlib>
#include <iostream>
#include <time.h>

int main() {

    /// rand()함수를 이용해서 랜덤 문자 출력
    // for (int i=0; i < 5; i++) {
    //     std::cout << rand() << " ";
    // }

    // srand is an inbuilt funciton in c++ STL from a cstdlib header file
    std::srand(time(0)); // srand를 한번 콜 한 후에 seed를 (time함수) 해서 생성 후 rand()로 여러번 출력해서 사용가능
    for(int i=0; i < 5; i++) {
        std::cout << rand() << " ";        
    }
    std::cout << std::endl;

    std::string str_rand = std::to_string(rand());
    std::cout << "str_rand :" << str_rand << std::endl;

    return 0;
}