#include <iostream>
#include <vector>
#include <iterator>
#include <charconv>

int main() {
    // ascii table은 char를 int로 바꿔주면 볼 수가 있다
    // vector 선언
    std::vector<int> ascii_vals {};
    std::vector<char> chars {'h', 'e', 'l', 'l', 'o'};


    // 변수 배열 크기 지정
    ascii_vals.reserve(chars.size());


    for(auto &n : chars) {
        ascii_vals.push_back(n);
    }

    //출력
    for(int i=0; i< ascii_vals.size(); i++) {
        std::cout << ascii_vals[i] << std::endl;
    }

    return 0;
}