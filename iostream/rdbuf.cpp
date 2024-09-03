#include <iostream>
#include <fstream>

int main() {
    std::ofstream output("output.txt");
    auto originalCoutBuffer = std::cout.rdbuf(); // stdout 를 가지고 있음

    std::cout.rdbuf(output.rdbuf());
    std::cout.write("hello\n", 6);  // 이제 파일에는 hello 가 들어간 파일이 만들어짐

    ///TODO: 
    // 아직 정확히는 이해를 못했지만, 로그를 저장하거나 할 때 유용할 수 있다고 하는데 더 해보기
    std::cout.rdbuf(originalCoutBuffer);
    std::cout << "back to normal" << std::endl;
    
}

//  g++ -std=c++17 rdbuf.cpp -o rdbuf