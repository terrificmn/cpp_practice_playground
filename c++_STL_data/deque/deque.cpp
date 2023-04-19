#include <iostream>
#include <deque>

int main(int argc, char *argv[]) {

    std::deque<int> deque = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // 처음에 삭제하고 마지막에 추가하기
    deque.pop_front(); // 첫 인덱스에서 삭제
    deque.push_back(11); // 마지막 인덱스에 추가

    for(auto &n : deque) {
        std::cout << n << "\t";
    }
    std::cout << "\n";

    // string으로 하는 예
    std::deque<std::string> deque_str = { 
        "copy", "paste", "cut", "move", "delete", "input"
    };

    // 위의 경우와는 반대로..
    // 처음에 추가하고 마지막에 삭제하기
    deque_str.push_front("link"); // 처음에 추가
    deque_str.pop_back(); // 끝의 요소를 삭제

    for(auto &n : deque_str) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}

// Deque는 Double-ended queue 이다
// Deque와 Vector에 비해서 앞부분과 뒷부분에서 추가/삭제가 가능하다.
// 덱의 처음과 끝에 요소를 추가하는 것이 빠름
// 히스토리 기능 (새로운 것이 첫부분에 등록이 되고, 마지막은(시간이 오래된 것은) 삭제가 된다)
// 또는 undo와 같은 기능을 만들 수도 있다