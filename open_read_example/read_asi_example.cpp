#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>  //file open
#include <sstream>

int main() {

    std::fstream myFile;
    std::string AsiFileName = "asi_text_file";
    std::vector<int> convertedNum {};
    std::vector<char> chars {};

    // read file
    myFile.open(AsiFileName, std::ios::in); //ios::in read
    if (myFile.is_open()) {
        std::string line;
        while (std::getline(myFile, line, ' ')) { // until no line, it loops. ' '로 구분해서 넣어준다
            convertedNum.push_back(std::stoi(line));  //line 읽어온 것이 string이어서 int로 바꿔서 다시 넣어준다. int로 되어있어야 변환이 가능
        }
        myFile.close();
    }

    // int로 담긴 convertedNum 에서 하나씩 꺼내서 영어로 바꿔주면서 chars2에 넣어주기
    chars.reserve(convertedNum.size());
    for(auto &n : convertedNum) {
        chars.push_back((n));
    }

    // chars 출력하기
    std::cout << "ASCII to String\n";
    copy(chars.begin(), chars.end(), std::ostream_iterator<char>(std::cout, ""));

    return 0;
}