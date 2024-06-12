#include <iostream>
#include <vector>
#include <initializer_list>

int main() {

    // {}, () 등으로 시작하게 할 수 있다. 
    // vector 등은 { }로 시작 , curly brace 는 initialize을 할 때 사용할 수가 있음..

    std::vector<int> v { 10, 5, 3 };
    
    for(auto& i : v) {
        std::cout << i << std::endl;
    }

    // 이렇게 하면 정상적으로 만들어짐, 
    // 단 ()을 사용해서 만들게 되면, 원하지는 않는 결과가 나올 수 있다. 10짜리, 12로 만들어 버린다
    std::vector<int> v2 ( 10, 3 );
    
    for(auto& i : v2) {
        std::cout << i << std::endl;
    }

    struct MyStruct {
        MyStruct(std::initializer_list<int> data) {
            std::cout << "init\n";
            m_data = data;  // 여기에서 카피를 방지하려면 컨스트럭터에서 바로 만들어 주면 된다.
        }
        // 여기에서 카피를 방지하려면 컨스트럭터에서 바로 만들어 주면 된다. 사실 아래 방법이 더 좋지만 알아서 사용 ㅋㅋ
        // MyStruct(std::initializer_list<int> data) : m_data(data) {
        //     std::cout << "init\n";
        // }

        ~MyStruct() { }

        void printTest() {
            for(auto& a : m_data) {
                std::cout << a << " ";
            }
            std::cout << std::endl;
        }
        private:
        std::initializer_list<int> m_data;
    };

    /// std::initializer_list 를 이용해서 만들어 줄 수도 있다.
    MyStruct myStruct{1, 2, 3};
    myStruct.printTest();



}