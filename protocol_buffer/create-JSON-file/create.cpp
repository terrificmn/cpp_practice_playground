
#include <iostream>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/util/json_util.h>

int main() {
    std::string json;
    std::string path = "/home/myUser/myfile";
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = false;
    options.always_print_primitive_fields = true;
    // Proto message 상태에서 Json string으로 바꿀 때 글자 그대로 유지하는 옵션
    // false로 하게 되면 Camel case로 바꾼다. (snake case 가 있다면 camel case로 변경됨)
    options.preserve_proto_field_names = true; 
    
    // 아주 간단하게 한번에 string 으로 변경할 수가 있다. 
    google::protobuf::util::MessageToJsonString(MyProtoMessage, &json, options);

    std::ofstream myFile(path);

    if(myFile.is_open()) {
        myFile << json;
        std::cout << "Success!" << std::endl;
    } else {
        std::cerr << "not opened\n";
    }
}

// 이 외에도 proto file에서 camelcase 로 사용하더라도 protobuf 를 사용해서 cc 파일을 만들때 normalized 해버리게 때문에 
// 실제로 사용할 때에는 camelcase 함수가 아닌 함수로 불러야 할 경우가 있다.  
// 예 message {
//     optional currentTime  = 1;
// }

// 실제로 c++에서 사용할 때에는 
// /*..대충 생략...*/  MyMsg.currenttime();
