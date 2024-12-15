#include <iostream>
#include <unordered_map>

#include <sol/sol.hpp>
/// sol 을 이용하면 lua 를 쉽게 사용할 수 있다. - lua의 C api 통해서 호출을 안하고  
/// sol2 가 대신 처리해서 쉽게 적용이 가능

/// git clone https://github.com/ThePhD/sol2
// 다른 파일들은 필요 없고 include/sol 디렉토리만 복사해서 사용하면 된다. 
/// 프로젝트 root
///          | include/sol/sol.hpp 등등..
///          | src (필요시) 
/// vscode 에서 sol 인식할 수 있게 해주면 include sol 헤더 잘 찾는다.
/// .vscode 디렉토리 이하의 c_cpp_properties.json 파일에   
/*
"includePath": [
                "${workspaceFolder}/**",
                "/usr/local/include",
                "${workspaceFolder}/lua_open/include"
            ],
*/

int main(int argc, const char* argv[]) {
    sol::state lua;
    lua.open_libraries(sol::lib::base);

    /// load the lua script
    lua.script_file("lua_table.lua");

    /// call the lua function in a lua file.
    sol::function get_table = lua["passTableToCpp"]; // function in a lua
    sol::table lua_table = get_table(); // sol::function 
    
    for(const auto& [key, value] : lua_table) {
        std::string str_key = key.as<std::string>();
        std::cout << "key is " << str_key << "\t";
        if(value.is<std::string>()) {
            std::cout << value.as<std::string>() << std::endl;
        } else if(value.is<int>()) {
            std::cout << value.as<int>() << std::endl;
        } else if(value.is<float>()) {
            std::cout << value.as<float>() << std::endl;
        } else if(value.is<bool>()) {
            std::cout << value.as<bool>() << std::endl;
        }

    }

    std::cout << "Bye" << std::endl;

    return 0;
}

// g++ -std=c++17 -o lua_table_with_sol lua_table_open2_sol.cpp -I`pwd`/include -llua 
