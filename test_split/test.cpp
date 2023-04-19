#include <iostream>
#include <vector>

int main() {
    std::string str = "123, 4567, 890, ";
    std::string delimiter = ", "; // split by , and space  
    std::string token;

    size_t pos = 0;
    std::vector<int> extracted_xy;
    //참고:: 만약 delimiter가 마지막에 ",스페이스"가 없다면 최종적으로 요소는 2개 밖에 안 만들어진다
  
while ((pos = str.find(delimiter)) != std::string::npos) {
	token = str.substr(0, pos); // split it from found array index
	std::cout << "token: " << token << std::endl;
	extracted_xy.push_back(stoi(token));
	str.erase(0, pos + delimiter.length()); // caution: erased due to reference to variable
}

std::cout << extracted_xy[0] << std::endl;
std::cout << extracted_xy[1] << std::endl;
std::cout << extracted_xy[2] << std::endl;
}