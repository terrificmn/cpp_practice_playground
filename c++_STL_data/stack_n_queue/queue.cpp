#include <iostream>
#include <queue>

int main(int argc, char *argv[]) {
    // 큐는 tail 끝에서 데이터를 추가를 하고(push), head 첫 부분에서 데이터를 삭제하게 된다
    // 중간에 insert, erase를 할 수 없다 (스택과 동일)
    std::queue<int> que;

    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);

    while(!que.empty()) {
        std::cout << que.front() << std::endl; // back() 함수도 있다 - 마지막원소 반환
        que.pop(); // 여기에서 pop()은 첫 번째 요소를 제거
        // 첫 번째 요소가 삭제되어서, 또 다시 front()로 새로 첫 요소가 된 부분을 또 출력하게 된다 
        // 처음 들어온 것이 먼저 나가게 된다 
        // FIFO: First-In First-Out
    }

    return 0;
}