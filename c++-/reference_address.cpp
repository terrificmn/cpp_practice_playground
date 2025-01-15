#include <iostream>
#include <vector>
#include <algorithm>

void passByValue(std::vector<int> arg) {
    arg[0] = 1;
}

void passByReference(std::vector<int>& alias) {
    alias[0] = 1;
}

int main() {
    std::vector<int> x(1000000000);

    std::fill(std::begin(x), std::end(x), 1);

    // 터미널에서 time 으로 실행해서 실제 수행되는 시간을 볼 수가 있다.
    // 터미널에서 실행----> time ./reference_address
    /// TODO: 테스트 시 주석 해제 후 빌드 , 비교
    // passByValue(x);
    /// 노트북 기준 real 0m3.643s 가 걸린다.

    passByReference(x);
    /// reference로 보내게 되면
    /// 노트북 기준 real 0m2.262s 가 걸린다.

    /// reference로 보냈을 경우에 시간이 더 단축되는 것을 알 수가 있다.
    /// 1000000000를 인덱스를 카피하느라고 더 오래 걸리게 된다.
    /// 단순 비교로는 큰 차이가 없을 수 있지만 
    /// loop 에서 계속 사용이 되면서 value로 카피가 많아 진다면 더 오래 걸릴 수 밖에 없다.

    
}

// g++ -std=c++17 -o reference_address reference_address.cpp

/// 실행 time ./reference_address
