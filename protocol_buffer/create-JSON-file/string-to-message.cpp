#include <iostream>
#include <sstream>
#include <fstream>
#include <google/protobuf/util/json_util.h>
#include "myProtoData 의 헤더파일 /있다고 치고 ㅋ"


// 파일에서 읽거나 또는 string 이 있을 때 proto message로 만들기 
/// (파일) -> string으로 만들기 -> proto meesgae로 만들기

int main() {
    // 1. 파일을 열자
    std::string path = "/home/myUser/myfile";
    std::ifstream myFile(path, std::ios::in);
    if(!myFile.is_open()) {
        std::cerr << "Failed to open a file\n";
        return false;
    }

    // 2. stringstream 으로 파일에서 읽어서 string 으로 만듬
    std::stringstream ss_buf;
    ss_buf << myFile.rdbuf();
    std::string json_string = ss_buf.str();
    std::cout << json_string << std::endl;
    
    // proto가 있다고 치고..
    proto::MyProtoData myProtoData;

    // 이제 스트링을 proto message로 만드는데 JsonStringToMessage()를 사용
    google::protobuf::util::JsonParseOptions options;
    auto status = google::protobuf::util::JsonStringToMessage(json_string, &myProtoData, options);

    /// 
    if(status.ok()) {
        std::cout << "okay!\n";
    } else {
        std::cout << "Not okay!\n";
    }

    // 3. myProtoData 가 만들어지면 proto convention 에 따라서 사용한다

}