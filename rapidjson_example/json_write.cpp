#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
/*
{
    "MacAddress" : "de::9o::02::jc",
    "x" : 10,
    "y" : 20
}
*/
rapidjson::StringBuffer createJson(std::string mac_address, double robot_x, double robot_y) {

    rapidjson::StringBuffer strbuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);

    writer.StartObject();
        writer.Key("MacAddress");
        writer.String(mac_address.c_str()); //to char
        writer.Key("x");
        writer.String((std::to_string(robot_x).c_str())); //double에서 string 변환 후 다시 char로 변환
        writer.Key("y");
        writer.String(std::to_string(robot_y).c_str());
    writer.EndObject();
    std::cout << "in fuction: " << strbuf.GetString() << std::endl;
    return strbuf;
}


int main(int argc, char** argv) {
    rapidjson::StringBuffer result;
    result = createJson("De::0x::A3::jW::24", 10.00, 20.00);
    
    std::cout << "after fuction: " << result.GetString() << std::endl;
    std::string data = result.GetString();
    std::cout << "last data: " << data << std::endl;
    return 0;
}