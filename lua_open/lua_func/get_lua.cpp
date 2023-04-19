#include "get_lua.h"

void luaMain() {
    std::cout << "lua load start" << std::endl;

    lua_State* L = luaL_newstate();  // lua instance 만들기
    luaL_openlibs(L);  // give lua access to basic libraries

    // register cpp function -- 2번째 arg는 lua의 함수, 3번째는 cpp함수
    lua_register(L, "passParamToCpp", getParamFromLua);  //function 등록  

    // lua파일 읽기
    luaL_dofile(L, "lua_func/lua_param/config.lua");

    lua_close(L); // cleanup lua

    std::cout << "Bye" << std::endl;

}

int main() {
    luaMain();
        
    return 0;
}