#include <map>
#include <iostream>
// #include <string>
// #include <iterator>

int main(int argc, char *argv[]) {

    // map은 key, value로 만들어진다. (앞이 key, 뒤 value)
    // Js의 Object라던가, PHP의 associative array 같은...
    std::map<std::string, std::string> my_map;

    my_map.insert(std::make_pair("John", "USA"));
    my_map.insert(std::make_pair("Mark", "Canada"));
    my_map.insert(std::make_pair("Kim", "Korea"));

    for(auto& iterator : my_map) {
        std::cout << iterator.first << ": " << iterator.second << std::endl;
    }

    /// find() 함수로 key 에 해당하는 요소를 찾아볼 수도 있다
    // 해당 문자열(key)를 못 찾으면 iterator 포인터를를 end() iterator로 리턴히게 된다
    if(my_map.find("Tim") == my_map.end()) {
        std::cout << "not found\n";
    }

    // 반대로 끝으로 안갔다는 것은: 리턴값이 end() 포인터로 이동이 아니라면, 찾았다는 것이 된다. 
    if(my_map.find("Mark") != my_map.end()) {
        std::cout << "found\n";
    }

    return 0;
}