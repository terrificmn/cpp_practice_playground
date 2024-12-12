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

/**
 * @brief Lua function must be this format
 * 
 * @param L 
 * @return int 
lua 파일에는 이런식으로 함수로 호출하게 되어 있다. 
passParamExample(10, 'function from Lua to C++')
lua_State* L 로 받아서 사용하게 된다.
 */

static int TestCppFunc(lua_State* L) {
    const int num = (int)lua_tonumber(L, 1);  // get the first param from stack
    const char* str = lua_tostring(L, 2); // get the second param from stack
    std::cout << "Hello Lua. this is cpp function" << std::endl;
    std::cout << "num : " << num << ", str : " << str << std::endl;
    return 0; // return 0을 하면 lua파일로 파라미터를 pushing 하지 않는다?
}


/**
 * @brief lua 파일로부터 넘겨받는 순서대로 파라미터 받는 cpp 함수 예제
 * 함수의 파라미터는 lua_State포인터로 파라미터를 넘겨야 하고,int 값을 리턴해야한다 
 * (지정되어 있으므로 같은 형식을 사용하면 된다)
 * 여기에서는 스택 처럼 처음 1부터 순서대로 뽑아서 쓰게 된다. 
 * @param L 
 * @return int 
 */
static int getParamFromLua(lua_State* L) {
    int n = lua_gettop(L); // get number of argument
    std::cout << "how many params: " << n << std::endl;
    double double_param1 = 0.0;
    double double_param2 = 0.0;
    int int_param1 = 0;
    int int_param2 = 0;
    std::string str_param;

    // 에러 처리 -- lua파일에서 다른 값을 보내본다 (테스트 할 경우)
    // 스트링은 잘 안되는 듯.. 좀더 알아봐야할 듯 --lua_isstring(L, 5) 숫자를 넣던, 스트링은 넣던 효과가 없다
    // 오히려 lua_isnumber(L, 5) 로 스트링을 넣으면 number가 아니라고 나옴 -- ok
    // lua_isinteger(L, 1)는 인티져는 ok
    if (!lua_isnumber(L, 5)) {
        std::cout << "not a number" << std::endl;
    }
    // lua_isboolean()
    // lua_isinteger()
    // lua_isstring() 등 많다.

    // 포인터 L로 부터 넘어온 파라미터를 알 수가 있는데, lua_gettop(L) 을 하면 parameter 갯수를 알 수가 있고
    // 이를 활용해서 for 를 사용하거나 하며 됨  
    // 단, 파라미터는 0이 아닌, 1부터 시작한다 (i를 0을 설정할 경우는 1 을 주거나, i+1 을 시켜야할 듯 하다)
    double_param1 = lua_tonumber(L, 1);
    double_param2 = lua_tonumber(L, 2);
    int_param1 = lua_tonumber(L, 3);
    int_param2 = lua_tonumber(L, 4);
    str_param = lua_tostring(L, 5);


    std::cout << "double_param1 is " << double_param1 << std::endl;
    std::cout << "double_param2 is " << double_param2 << std::endl;
    std::cout << "int_param1 is " << int_param1 << std::endl;
    std::cout << "int_param2 is " << int_param2 << std::endl;
    std::cout << "str_param is " << str_param << std::endl;

    // 오히려 lua 파일로 전송할 때 사용하는 것 같다. lua_pushnumber()를 했다면 return 도 그 수만큼 해준다 
    // 여기에서는 return 4가 됨 (4개)
    // lua_pushnumber(L, double_param1);
    // lua_pushnumber(L, double_param2);
    // lua_pushnumber(L, int_param1);
    // lua_pushnumber(L, int_param2);
    // lua_pushstring(L, "not number");

    return 0; // return the number (push한 결과);
}



int main(int argc, const char* argv[]) {
    std::cout << "C++ start" << std::endl;

    lua_State* L = luaL_newstate();  // lua instance 만들기
    luaL_openlibs(L);  // give lua access to basic libraries

    // stack 구조로 c++ lua 간 커뮤니케이션 가능하게 됨 (real stack과는 조금 다르다고 함)
    // 아래의 두 개의 예제는 같은 방식임
    ///IMPORTANT: register cpp function -- 2번째 arg는 lua의 함수, 3번째는 cpp함수가 된다.
    // register를 한 후에 lua 파일을 읽으면 된다. 
    lua_register(L, "passParamExample", TestCppFunc); 
    lua_register(L, "passParamToCpp", getParamFromLua);  //function 등록  // lua file에서의 함수 이름이 정확히 맞아야 작동한다
    // 한 쌍이라고 생각하면 될 듯 하다. lua쪽은 퍼블리셔, cpp쪽은 서브스크라이브 같은 느낌이지만 (조금 헷깔리므로)
    // 같은 함수를 호출 한다고 생각하면 함수 이름을 같은 것을 사용해도 될 듯 하다. 
    /* lua file에는 예 lua.lua 파일에는 
        passParamToCpp(
            param1,
            param2
        )
        식으로 구성해준다.
    */

    // lua파일 읽기
    luaL_dofile(L, "lua.lua");

    // 아래 방법은 cpp에서 lua 파일내의 함수를 호출하는 방법, 미리 register 하지 않고 바로 사용
    // 함수 호출 후, 파라미터를 하나씩 넘겨준다.
    // call lua function from c++
    lua_getglobal(L, "myLuaFunction"); // find lua function
    lua_pushnumber(L, 73); //push int
    lua_pushstring(L, "From C++ to Lua"); // push string as second param
    
    constexpr int NUM_ARGS = 2;
    constexpr int NUM_RETURNS = 0;
    // lua_pcall(L, 2, 0, 0); // call the function passing 2 params   // basic  아래와 같은 효과(좀더 보기 편하다)
    lua_pcall(L, NUM_ARGS, NUM_RETURNS, 0);  // 보낼 아규먼트 수, 리턴 받을 수

    lua_close(L); // cleanup lua

    std::cout << "Bye" << std::endl;

    return 0;
}
