#include <regex>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>

int main(int argc, char** argv) {

std::string test_string = "origin: [-28.126819, 27.423724, 0.000000]";
std::string ph_string = "010-123-1234";
// std::regex reg("[01]{3}-(\\d{3,4})-\\d{4}"); /////space is problem

std::regex reg("[-\\d\\s.,\\[\\]]+"); /////space is problem
std::smatch mat;
std::string found_str;
// std::cout << "match?: " << std::boolalpha << std::regex_match(test_string, reg) << std::endl;

if(std::regex_match(test_string, reg)) {
	std::cout << "match?: " << std::boolalpha << std::endl;
}

/// reg_match와 regex_search에서 같은 결과가 나오지는 않는다. 

if(std::regex_search(test_string, mat, reg)) {
	std::cout << "ok found it" << std::endl;
	std::cout << "mat size: " << mat.size() << std::endl;

	for(auto x: mat) {
		std::cout << x << " \n";
		found_str += x;  // concatenation
	}
}
/// IMPORTANT: 여기에서 (auto: x mat)으로 for loop가 될 수 있는 것은 reg() 매치를 그룹화를 했기 때문이다.
// [] 또는 ()로 그룹화를 하면, mat의 첫 번째는 전체에서 찾고, 두 번째는 그룹화 한 것에 찾는다.
// 그래서 mat[0] 으로 접근하게 되면 full match 한 것을 알 수가 있고
// mat[1] 로 하게 되면 캡쳐한 그룹화를 보여주게 된다.
/// 위의 test_string 에서 부호 포함 소수점포함한 숫자를 그룹으로 찾아야 하므로 위에 처럼 사용을 하면 될 듯 하고
// 만약 한 개만 찾기는 원하면 () 등을 빼고 reg()를 찾아주면 된다.
// e.g. std::regex reg("\\d+");

std::cout << "made: " << found_str << std::endl;

/// 첫번째 문자 찾기. 있으면 배열 인덱스 리턴 (해당 char가 어디에서 처음 시작하는지 리턴)
size_t start = found_str.find_first_of(" ");
std::cout << "start :" << start << std::endl;
std::cout << "result :" << found_str << std::endl;
std::cout << found_str.erase(start, 1) << std::endl; /// 해당 배열 제거

std::cout << "removed space :" << found_str << std::endl;

found_str.erase(0, 1);
found_str.erase(found_str.length()-1, 1);  /// 마지막 인덱스 지우기

std::cout << "finally removed :" << found_str << std::endl;
std::string delimiter = ", ";
// std::string token = found_str.substr(2, found_str.find(delimiter));
std::string token;

size_t pos = 0;
std::vector<double> extracted_xy;

while ((pos = found_str.find(delimiter)) != std::string::npos) {
	token = found_str.substr(0, pos);
	std::cout << token << std::endl;
	extracted_xy.push_back(stod(token));
	found_str.erase(0, pos + delimiter.length());
}

std::cout << "x :" << std::setprecision(8) << extracted_xy[0] << std::endl;
std::cout << "y :" << std::setprecision(8) << extracted_xy[1] << std::endl;

return 0;
}