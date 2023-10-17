#include <iostream>
#include <thread>
#include <list>
#include <algorithm>

std::list<int> myList;

// list에 추가를 하는데 파라미터로 들어온 값을 나머지가 0이면 list에 추가
void addToList(int max, int interval) {
    for(int i =0; i < max; i++) {
        if( (i% interval) == 0) {
            myList.push_back(i);
        }
    }
}

void printList() {
    for(auto itr = myList.begin(), end_itr = myList.end(); itr != end_itr; ++itr ) {
        std::cout << *itr << ", ";
    }
}

int main() {
    int max = 100;

    std::thread worker_thread1(addToList, max, 1); // 1로 나누면 모두 자기자신? max100까지 리스트로 채운다 
    std::thread worker_thread2(addToList, max, 10); // 10 자리만 list에 들어가게 됨
    std::thread worker_thread3(printList);

    worker_thread1.join();
    worker_thread2.join();
    worker_thread3.join();


    // 예제에서는 worker_thread1, worker_thread2 가 동시에 실행되면서 뭔가 뒤섞여야 하는데  
    // 실제로 실행해보면 전혀 섞이지 않고 잘 된다.. 동시에 실행이 되어야 하는데 잘 안되는 듯 함
    // 어쨋든 multithread 예제 

    // 사실 여기저기에서 multi thread로 사용하다보면 data가 보호가 안되고 문제가 있어서 
    // 이것을 해결하는 것이 std::mutex 임
    return 0;
}