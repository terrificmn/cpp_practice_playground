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