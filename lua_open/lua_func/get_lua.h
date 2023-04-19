// ## 같은 내용임-- lua_open.cpp 와 그래도 head로 테스트 해보기

#ifndef GET_LUA_H
#define GET_LUA_H

#include <iostream>
#include <vector>

extern "C" {
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
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
    std::string str_param;

    // 에러 처리 -- lua파일에서 다른 값을 보내본다 (테스트 할 경우)
    // 스트링은 잘 안되는 듯.. 좀더 알아봐야할 듯 --lua_isstring(L, 5) 숫자를 넣던, 스트링은 넣던 효과가 없다
    // 오히려 lua_isnumber(L, 5) 로 스트링을 넣으면 number가 아니라고 나옴 -- ok
    // lua_isinteger(L, 1)는 인티져는 ok
    // if (!lua_isnumber(L, 5)) {
    //     std::cout << "not a number" << std::endl;
    // }

    // 포인터 L로 부터 넘어온 파라미터를 알 수가 있는데, lua_gettop(L) 을 하면 parameter 갯수를 알 수가 있고
    // 이를 활용해서 for 를 사용하거나 하며 됨  
    // 단, 파라미터는 0이 아닌, 1부터 시작한다 (i를 0을 설정할 경우는 1 을 주거나, i+1 을 시켜야할 듯 하다)

    std::vector<std::vector<double>> v_param_pos; 
    v_param_pos.push_back(std::vector<double>());
    
    int v_first_row = 0;
    int index_count = 0;
    std::vector<std::string> v_param_name;

    // position 관련만 3개로 묶기 위해서 index_count를 만들어서 사용, i는 실제 값을 주기 위해서 사용
    for (int i=0; i < n; i++) {
        if(index_count % 3 == 0 && index_count != 0) {
            v_first_row++;
            v_param_pos.push_back(std::vector<double>());
            // std::cout << "index added " << std::endl; 
        }
        
        if(lua_type(L, i+1) == LUA_TSTRING) {
            v_param_name.push_back(lua_tostring(L, i+1));
            // std::cout << "string added " << std::endl; 
            index_count = 0;
        } else {
            v_param_pos.at(v_first_row).push_back(lua_tonumber(L, i+1));
            index_count++;
        }
        
    }

    std::cout << "data: " << v_param_pos[0][0] << std::endl;
    std::cout << "data: " << v_param_pos[0][1] << std::endl;
    std::cout << "data: " << v_param_pos[0][2] << std::endl;
    std::cout << "data: " << v_param_pos[1][0] << std::endl;
    std::cout << "data: " << v_param_pos[1][1] << std::endl;
    std::cout << "data: " << v_param_pos[1][2] << std::endl;

    std::cout << "string data: " << v_param_name[0] << std::endl;
    std::cout << "string data: " << v_param_name[1] << std::endl;

    return 0; // return the number (push한 결과);
}


#endif