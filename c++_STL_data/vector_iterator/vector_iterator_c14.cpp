#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    // c++의 STL 의 컨테이너를 제공하는데 (컨테이너는 데이터들을 저장하는 클래스)
    // vector, queue, stack, list, set, map (key-value) 등이 있는데  
    // 인덱스로도 확인이 가능하지만, begin(), end()를 활용해서도 할 수가 있다
    // STL 에서는 위의 컨테이너들의 종류에 상관없이 요소들에 접근할 수 있게 iterator를 만들었다
    // generalized pointer 라고 불린다 
    for(auto p = vec.begin(); p != vec.end(); p++) {
        std::cout << *p << std:: endl;
    }

    std::cout << "------\n";
    // vector의 경우에는 그냥 범위 지정으로 쉽게 할 수가 있다 
    for(auto& n : vec) {
        std::cout << n << std::endl;
    }

    // 그리고 예전 방식으로는 (지금도 사용은 가능) 
    // iterator의 자료형을 선언해줘야하는 방식, 반복자의 자료형 지정
    for(std::vector<int>::iterator p = vec.begin(); p != vec.end(); p++) {
        std::cout << "old way: " << *p << std::endl;
    }
    
    return 0;
}