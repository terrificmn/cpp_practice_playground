#include <stack>
#include <iostream>
#include <vector>

// 스택은 중간에 insert, erase 할 수 없다

int main(int argc, char* argv[]) {

    // stack 생성 - 기본은 deque (double ended queue) 데크를 이용해서 생성된다
    std::stack<std::string> stack;
    // 만약 파라미터를 2번째 파라미터를 추가하면, 기반 컨테이너를 변경할 수가 있다 
    std::stack<std::string, std::vector<std::string>> stack2;

    std::string sayings[3] = {
        "hello world1",
        "hello world2",
        "hello world3"
    };

    // 순차적으로 std::stack 에 넣어준다
    for(auto& saying : sayings) {
        stack.push(saying);
        stack2.push(saying);
    }

    // pop()은 마지막 요소를 꺼낸다. 없을 때까지 반복
    // LIFO : Last-In First-Out
    // 늦게 들어온 데이터가 빨리 나가는 구조
    // stack은 함수 호출 등에서 사용이 된다. 함수가 호출되고 원래 호출된 자리로 리턴할 때 스택에 저장된 순서대로 오게되는 원리라고 함
    while(!stack.empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }

    std::cout << "---------- stack2..\n";
    while(!stack2.empty()) {
        std::cout << stack2.top() << std::endl;
        stack2.pop();
    }

    // stack 주요 함수
    /*
    push(), pop()
    top() -- 가장 위(?) 마지막에 있는 요소 리턴
    empty() -- empty 이면 return true, 
    size() -- 개수
    */
    return 0;
}