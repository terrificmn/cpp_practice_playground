#include <iostream>

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

struct MyParam {
    std::string name;
    int age;
    std::string class_name;
};

struct MyParamExample {
    int param1;
    int param2;
    std::string param3;
};

/// 클래스 형태로 만들어 봄
class LuaOpen {
private: 
    // lua_State* L 

public:
    LuaOpen() {
        lua_State* L = luaL_newstate();
        luaL_openlibs(L);
        const char* lua_path = "/home/sgtraphaelfed/Workspace/cpp_practice/lua_open/lua_table2.lua";

        if(luaL_dofile(L, lua_path)) {
            std::cerr << "lua_table2.lua not found." << std::endl;
            lua_close(L);
            return;
        }

        this->loadLua(L, "MY_PARAM");
        std::cout << "---------------" << std::endl;


        //////////////////
        // nested table (object)를 가져오는 방법은 loadLua()에서 사용했던 것과 아주 비슷하다. 
        // 대신에 먼저 최상위 table 자체를 lua_getglobal()로 읽은 다음에 다음 table을 하나씩 읽어주는 방식으로 진행
        // loadNestedLua()를 확인하자
        L = luaL_newstate();
        const char* lua_path2 = "/home/sgtraphaelfed/Workspace/cpp_practice/lua_open/lua_table3.lua";

        if(luaL_dofile(L, lua_path2)) {
            std::cerr << "lua_table3.lua not found." << std::endl;
            lua_close(L);
            return;
        }

        lua_getglobal(L, "MY_PARAM");
        if(!lua_istable(L, -1)) {
            std::cerr << "table is wrong." << std::endl;
            lua_close(L);
            return;
        }
        this->loadNestedLua(L, "myInfo");
        std::cout << "---------------" << std::endl;
        this->loadNestedLua(L, "myData");
        
        lua_close(L); // cleanup lua
    }


    bool loadLua(lua_State* L, const char* table_name) {
        lua_getglobal(L, table_name);
        if(!lua_istable(L, -1)) {
            std::cerr << "table is wrong." << std::endl;
            lua_pop(L, 1);
            return false;
        }

        MyParam myParam;

        lua_pushstring(L, "name");
        lua_gettable(L, -2);
        if(lua_isstring(L, -1)) {
            myParam.name = lua_tostring(L, -1);
        }
        lua_pop(L, 1);

        lua_pushstring(L, "age");
        lua_gettable(L, -2);
        if(lua_isnumber(L, -1)) {
            myParam.age = lua_tointeger(L, -1);
        }
        lua_pop(L, 1);

        lua_pushstring(L, "class_name");
        lua_gettable(L, -2);
        if(lua_isstring(L, -1)) {
            myParam.class_name = lua_tostring(L, -1);
        }
        lua_pop(L, 1);

        lua_pop(L, 1); // remove the nested table from stack


        std::cout << "name: " << myParam.name << std::endl;
        std::cout << "age: " << myParam.age << std::endl;
        std::cout << "class_name: " << myParam.class_name << std::endl;
        
        return true;
    }

    bool loadNestedLua(lua_State* L, const char* table_name) {
        lua_pushstring(L, table_name);
        lua_gettable(L, -2); // Get MyParm[tableName]

        if(!lua_istable(L, -1)) {
            std::cerr << table_name << " table is wrong." << std::endl;
            lua_pop(L, 1);
            return false;
        }
        
        MyParamExample myParam;
        std::cout << "table name: " << table_name << std::endl;
        // Read param1
        lua_getfield(L, -1, "param1");
        if (lua_isinteger(L, -1)) myParam.param1 = lua_tointeger(L, -1);
        lua_pop(L, 1);

        // Read param2
        lua_getfield(L, -1, "param2");
        if (lua_isinteger(L, -1)) myParam.param2 = lua_tointeger(L, -1);
        lua_pop(L, 1);

        // Read param3
        lua_getfield(L, -1, "param3");
        if (lua_isstring(L, -1)) myParam.param3 = lua_tostring(L, -1);
        lua_pop(L, 1);

        lua_pop(L, 1); // remove the nested table from stack

        std::cout << "param1: " << myParam.param1 << std::endl;
        std::cout << "param2: " << myParam.param2 << std::endl;
        std::cout << "param3: " << myParam.param3 << std::endl;
        return true;
    }

};

int main(int argc, const char* argv[]) {
    
    LuaOpen luaOpen;

    // TODO: pair 방식 업데이트 하기
    std::cout << "Bye" << std::endl;

    return 0;
}

// g++ -std=c++17 -o read_lua_table lua_table_open_without_func.cpp -llua
