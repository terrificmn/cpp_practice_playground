#include <iostream>
#include <yaml-cpp/yaml.h>
#include <fstream>


/// 그냥 문자열로 되어 있지만 숫자 Only 형태로 되어 있을 경우에는 직접 string을 부여해도  
/// 자동으로 숫자로 바뀌는 현상이 있다. 
/// 결론은 아래 처럼 직접 바꿔주거나 (조금 손이 감;;),. 
/// 아니면 차라리 yaml에서 int 형으로 만든 후에 사용할 때 필요시 스트링으로 바꿔서 사용 (단점은 변환은 쉽지만, 실제 타입과 일치 하지 않는다.)

int main() {
    // Load YAML
    YAML::Node config = YAML::LoadFile("input.yaml");
    
    std::cout << "original my_option" << config["my_yaml"]["my_option1"] << std::endl;

    // Modify value
    config["my_yaml"]["my_option1"] = std::string("1234123");

    /// 분명 스트링인데, 숫자형태 일때에는 yaml 에서 자동으로 숫자 형태로 바꺼버린다. 
    /// 가장 쉬운 법은 숫자옆에 하나의 문자만 있어도 스트링으로 정상 잒동하게 된다. 예: "1234n"
    // 하지만 단순 숫자만 사용하고 싶을 경우에는 문제가 생길 수가 있다.
    /*
    예:
    원 yaml - my_option1: "1234123"
    이후 yaml - my_option1: 1234123
    */
    // 단순하게 접근하면, 그냥 int로 사용을 하고 실제로 사용할 경우에는 프로그램 내에서 int로 읽고 스트링으로 변환해서 사용하면 되지만,
    // 데이터 type을 일치하려고 하면 이 부분은 조금 맘에 걸린다;;
    
   // Set Emitter flags
    YAML::Emitter emitter;
    emitter << YAML::DoubleQuoted << config;
    // 이렇게 해주면 좋으나 모두 " "이 생겨버리는 문제가 있다.
    // 위에서는 순수 숫자 형태의 문자열을 자동으로 int 로 바꿔버렸지만 이번에는 모두 key 값까지 모두 " " 으로 감싸준다.;;;
    // int도 string으로 바뀌어 버린다.;;;


    // Write to file
    std::ofstream outfile("output.yaml");
    // outfile << emitter.c_str();  // Use emitter
    outfile << emitter.c_str();  // Use emitter
    outfile.close();
    std::cout << "output.yaml created." << std::endl;
    
    return 0;
}


//  g++ -std=c++17 -o string-int string_keeps_number.cpp -l yaml-cpp