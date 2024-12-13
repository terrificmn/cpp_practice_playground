# lua test
lua 파일과 cpp 파일간에 함수로 서로 호출 할 수 있고  
값들을 서로 넘겨 주고 넘겨 받을 수 있는 예제 프로그램   

lua는 5.4.4 에서 테스트 됨 (최신)

>lua 프로그램 설치는 codingClass md파일 참고  

빌드는 `g++ -o {실행파일이름} {소스파일.cpp} -llua -ldl` 처럼 해준다
```
g++ -o lua_test lua_open.cpp -llua -ldl
```
> 5.4 및 fedora 40 기준

우분투 20 및 5.3은 `-llua5.3` 으로 찾아야 함


### get_Lua_h이용하는 테스트 못함.cpp 
일단 클래스로 구성하게 되면 아래와 같이 함수로 인자를 넘겨야 하는데  
```
lua_register(L, "myCppFunctionFromCPP", TestCppFunc); 
```
클래스의 멤버 메소드로 넘겨줄 수가 없다  

~~아마도 C 위주로 되어 있어서 그런 듯 하다~~  

> 방법은 c 함수로 wrapper를 만드는 방식으로 할 수 있는 듯 한데.. 빌드만 되고   
> 실제 수행할 때는 에러 발생  - 그래서 일단 그냥 함수로 사용하는게 속편할 듯 하다  

만약 클래스의 멤버 변수에 값을 주고 싶으면   
~~기존 함수로 지정한 것의 파라미터외에 추가로 지정 할 수가 없어서 (`lua_State* L`)~~  

기존에는 static 함수를 제대로 이해를 못했다. 전혀 문제 없이 사용이 가능하다.  
lua 함수들이 static으로 구성이 되므로 클래스로 만들어 주더라도 네임스페이스 수준?이 된다.  
그래서 아래처럼 사용

```cpp
// include 생략
class LuaConfig {

public:
    LuaConfig();
    static int thisIsLua(lua_State* L) {
        int n = lua_gettop(L); // get number of argument
        /// lua 에서 불러온 내용 처리
        /// 예
        if(!lua_isboolean(L, 1)) {
            //
        }
        return 0;
    }
};


/// 그리고 main 등의 함수에서 register 시켜준다.
lua_register(L, "myLua", LuaConfig::thisIsLua); 
```

물론 실제 lua 파일에서는 
```lua
myLua(
    10,
    "20"
)
```
이렇게 한 후 lua와 연결 시킬 함수안에서 호출해서 사용하면 될 듯 하다