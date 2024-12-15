#include <iostream>
#include <unordered_map>

// include Lua header files
// extern "C" 는 c++에서 C-compatible code로 정의해주는 것 , 그리고 C 에서는 c++ code는 숨겨주는 것이라고 함 - c compiler는 c++를 컴파일 안함
// h 헤더파일에 따로 넣는다면 아래 방식을 사용
// #ifndef MY_HEADER_H
// #define MY_HEADER_H

// #ifndef __cplusplus
//     extern "C" {
//         #include ....
//     }
// #endif
// #endif

extern "C" {
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

int main(int argc, const char* argv[]) {
    lua_State* L = luaL_newstate();  // lua instance 만들기
    luaL_openlibs(L);  // give lua access to basic libraries

    // lua파일 읽기 - lua 파일 없거나, lua 형식이 올바르지 않을 경우에도 에러 발생할 수 있다.
    if( luaL_dofile(L, "lua_table.lua") != LUA_OK) {
        std::cerr << "lua_table.lua not found." << std::endl;
    };

    lua_getglobal(L, "passTableToCpp"); // lua에 있는 함수를 stack에 push
    if(!lua_isfunction(L, -1)) {
        std::cerr << "not a function in a lua script." << std::endl;
        return 1;
    }
    
    // call with 0 arguments  and return 1 , error handler 0
    // lua_pcall은 L, 제외 3개의 파라미터 - 
    // 첫 번째는 lua function 으로 보내는 아규먼트 수, 0 은 받는 아규먼트 없음, 아규먼트가 있으면 pua_pcall()하기 전에 stack에 push해야한다고 하나, 해보지 않음 
    // 두 번째는 return value 수 , 1은 리턴결과를 하나만 받는 것, function에서 multiple 로 리턴하게 되었을 시 이 수를 넘어가는 것은 받지 않는다.
    // 세 번째는 error 핸드러의 stack index , 0 은 커스텀 error handler 없음. 
    if(lua_pcall(L, 0, 1, 0) == LUA_OK) {
        std::cout << "function call" << std::endl;

        if(!lua_istable(L, -1)) {
            std::cerr << "table is wrong." << std::endl;
            return 1;
        }

        std::unordered_map<std::string, std::string> cpp_map;
        int index = lua_gettop(L);
        std::cout << "index: " << index << std::endl;
        lua_pushnil(L);  // Push the first key for table iteration
        while(lua_next(L, index )) { // index 에 주의
            std::string key = lua_tostring(L, -2); // get key
            std::cout << "key is " << key << std::endl;

            if(lua_isstring(L, -1)) {
                std::cout << lua_tostring(L, -1) << std::endl;
            } else if(lua_isnumber(L, -1)) {
                std::cout << std::to_string(lua_tonumber(L, -1)) << std::endl;
            } else if(lua_isboolean(L, -1)) {
                std::cout << std::boolalpha << lua_toboolean(L, -1) << std::endl;;
            }

            // cpp_map[key] = value;
            lua_pop(L, 1); // pop value, keep key for next iteration  // pop 기능을 사용해서 lua_isstring(L, -1) 등을 할 때 -1로 인덱스를 고정할 수 있는 듯 하다.
        }

    }

    lua_close(L); // cleanup lua

    std::cout << "Bye" << std::endl;

    return 0;
}

// g++ -std=c++17 -o lua_table lua_table_open1_lua_function.cpp -llua
