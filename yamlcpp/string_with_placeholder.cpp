#include <iostream>
#include <yaml-cpp/yaml.h>
#include <fstream>

int main() {
    // Load YAML
    YAML::Node config = YAML::LoadFile("input.yaml");
    
    std::cout << "original my_option" << config["my_yaml"]["my_option1"] << std::endl;

    const std::string place_holder_for_myoption1 = "PLACE_HOLDER_DOUBLE_QUOTED_" + std::string("4321");
    // Modify value
    config["my_yaml"]["my_option1"] = place_holder_for_myoption1;

    std::stringstream ss;
    ss << config;
    std::string yaml_str = ss.str();

    // Replace the placeholder with the quoted string
    size_t pos = yaml_str.find(place_holder_for_myoption1);
    if (pos != std::string::npos) {
        yaml_str.replace(pos, place_holder_for_myoption1.length(), "\"1234\"");
    }

    // 일단 yaml-cpp 에서는 한개의 맵 또는 value 를 포맷팅 하는게 없는 듯 하다. 
    // (YAML 에서는 자동으로 숫자로 바꿔버린다. 물론 조금이라도 숫자가 아닌게 들어가 있음 문자열 그대로 인식하지만.. 숫자만으로 이뤄어진 문자열은 친절하게도? 숫자로 바꿔버린다;;)
    // 이는 결국 type이 달라져서 여러 문제를 야기한다. (예를 들어서 string "1234" 였는데 int 형 1234 로  바뀜.)
    
    /// 그래서 기존의 my_otion1이 string 을 유지하면서 PLACE_HOLDER_.... 데이터를 유지해서 숫자 데이터로 바꿔주고 
    /// 추후 이 값을 읽어서 숫자만 두고 넣어주면 원하는 결과가 잘 생성이 된다. 
    // 즉 순수 숫자로 되어 있는 value 가 문자열로 원할 경우. 
    // 기존의 int는 그대로 int를 유지하게 된다. 

    // Write to file
    std::ofstream outfile("output2.yaml");
    // outfile << emitter.c_str();  // Use emitter
    outfile << yaml_str;
    outfile.close();
    std::cout << "output2.yaml created." << std::endl;
    
    return 0;
}


//  g++ -std=c++17 -o string-int string_keeps_number.cpp -l yaml-cpp