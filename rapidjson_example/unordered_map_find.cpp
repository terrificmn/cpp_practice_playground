#include <iostream>
#include <unordered_map>


int main() {

    std::unordered_map<std::string, int> u_map {
        {"test", 0 },
        {"number", 1234 }
    };

    // find() 함수를 사용하게 되면 해당 unordered_map< , >::iterator 식으로 만들어 지는데...
    // 발견된 게 없다면 iterator 의 end() 로 확인이 된다
    if(u_map.find("something") == u_map.end()) {
        // 이렇게 되면 없다는 상태가 됨
        std::cout << "'something' is not found\n";
    }

    if(u_map.find("test") != u_map.end()) {
        // 이렇게 되면 찾은 상태
        std::cout << "'test' found\n";
    }

    // 보통 for문으로 활용할 경우
    for(auto it = u_map.begin(); it != u_map.end(); ++it) {
        std::cout << "key {" << it->first << "} : ";
        std::cout << it->second << std::endl;
        // 식으로 접근해서 사용한다. second가 value
    }


}

//  g++ -std=c++17 -o unordered_map_find unordered_map_find.cpp 