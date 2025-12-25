# static lib 만들어서 빌드하기  
특정 라이브러리를 static 으로 만들어서 빌드하는 방법이다.  

내 프로젝트를 라이브러리화는 해봤지만, 필요한 의존성 라이브러리를 static으로 사용할 수가 있다. 

이번에는 lua 를 예시로 들어서 기록함  

일단 리눅스 distro 가 다른 Fedora, Ubuntu 등에서는 라이브러리가 호환이 안될 수가 있는데  
일반적으로 버전이 높은 쪽에서 만든 것이 낮은 버전에서 안 돌아가게 된다.  

## glibc rule 
```
A binary built against an older glibc will run on newer systems.
A binary built against a newer glibc will NOT run on older systems.
```
실행 파일에 link된 symbols 이 낮은 버전의 ubuntu에서는 없어서 실행이 안 되게 됨  
> ABI symbols  
glibc 는 하위 호환 ABI는 가능하다. backward ABI compatibility, 단 상위 호환은 안됨.

그래서 fedora 42에서 빌드한 것이 심지어 ubuntu 22 에서 안 될 수 있다. 물론 ubuntu 20 에는 더더욱 안될 경우가 많다.  

예를 들어서 Fedora에서 빌드한 것은  
GLIBC_2.34+  
GLIBCXX_3.4.29+  
를 요구하는데  

우분투 20에는 GLIBC_2.31 등으로 아예 해당 버전이 없다 . 

그래서 반대로 낮은 버전에서 빌드를 하게 되면  
높은 버전에서는 glibc 호환이 되므로 사용을 할 수가 있다. 

예) Ubuntu 20에서 빌드하고 Ubuntu22 또는 Fedora 같은 다른 distro 에서 사용하는 것  


## 단, 
여기에서 문제가 되는 것은 다른 다이나믹 so파일 라이브러리를 사용할 때  
버전은 같더라도 다른 이름을 사용하는 부분이 있다.  
이게 문제가 되어 다른 버전 혹은 다른 distro 에서는 해당 버전이 있더라도 찾지 못하게 된다.  

예를 들어서 
우분투 20에서는 liblua5.3 를 사용한다.  
liblua5.3.so.0

Fedora 42에서는 liblua 식으로 사용. 심지어 다른 버전의 이름도 다름  
liblua-5.4.so

이래서 프로그램을 실행을 하게 되면 run time에서 dynamic so 파일 라이브러리가 필요한데  
해당 라이브러리의 SONAME 이 맞지 않게 되어서 실행이 안되게 된다.  

그래서 lua 를 static 라이브러리로 만들어서  내 프로젝트에서 사용하게 되면  
실행파일에 아예 link가 되어서 runtime 시에 따로 lib를 필요로 하지 않게 된다.
> ubuntu 20에서 빌드하기

그러면 Fedora에서 실행을 하면 해당 lua so 파일은 런타임 시 필요가 없고  
오직 하위 호환성을 가지는 glibc 등만 남아서 실행이 잘 되게 된다.  

실제 ldd 명령을 사용해보면 실행 파일이 필요한 라이브러리를 잘 찾아 주고 있다. 

예)
우분투
```
libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f1567fe3000)
libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f1567fc8000)
...
```

페도라
```
libstdc++.so.6 => /lib64/libstdc++.so.6 (0x00007f1444c00000)
libgcc_s.so.1 => /lib64/libgcc_s.so.1 (0x00007f1444f02000)
...
```
필요한 라이브러리가 위치는 다르지만 각각의 위치를 잘 포인팅을 해주고 있어서 실행에 무리가 없다. 


### static 라이브러리 만들기
sudo apt update
sudo apt install -y build-essential


먼저 lua 파일 다운
wget https://www.lua.org/ftp/lua-5.3.6.tar.gz
tar xf lua-5.3.6.tar.gz
cd lua-5.3.6

**중요** PIC 로 static으로만 빌드해준다. 
```
make clean
make linux MYCFLAGS="-fPIC" MYLDFLAGS=""
```

이렇게 하면 src 이하에 src/liblua.a static 라이브러리가 생김

인스톨하기 
private prefix 로 /opt 이하로 만들어서 설치를 해준다. 
```
sudo make INSTALL_TOP=/opt/lua-5.3-static install
```
이렇게 하면  
해당 경로에 static 라이브러리가 최종 설치가 된다.  
include 에 헤더파일들이   
lib 에서 liblua.a  
bin 에 lua 실행 파일들   

이제 이 static 라이브러리를 내 프로젝트에서 linking 을 해서 빌드를 해주면 된다.

## cmake 빌드
```
# Lua static paths
set(LUA_ROOT /opt/lua-5.3-static)

add_library(lua_static STATIC IMPORTED)
set_target_properties(lua_static PROPERTIES
    IMPORTED_LOCATION ${LUA_ROOT}/lib/liblua.a
    INTERFACE_INCLUDE_DIRECTORIES ${LUA_ROOT}/include
)

target_link_libraries(myapp
    PRIVATE
        lua_static
        dl
        m
)
```
lua static 라이브러리 패스를 만들고 add_library 등을 해주고 내 실행 파일에 target_link_libraries 를 해주게 된다.   
> lua 에서는 dl, m 이라는 필요하다고 한다.  

실제 fedora 다른 ubuntu 22 등의 버전에 배포할 경우에는  
오직 실행파일만 있으면 된다.  
lua 관련 헤더 파일, 실제 /opt/lua-5.3-static 에 설치한 라이브러리도 **필요가 없다**. 

물론 프로젝트 빌드할 경우에는 lua 헤더파일은 
```
extern "C" {
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}
```
처럼만 사용하면 된다.  
원래 우분투 20 에서 lua5.3 을 사용하려면  
```
#include <lua5.3/lua.h>
#include <lua5.3/lualib.h>
#include <lua5.3/lauxlib.h>
```
이런식으로 사용해야 했다.  


### 확인 하기
확인  
`objdump -t getudev | grep luaL_newstate`

*luaL_newstate* 가 보이면 OK

`readelf -d getudev | grep lua`  
결과가 아무것도 안나와야 한다.

`ldd getudev`  
결과를 보면 s libstdc++.so.6, libgcc_s.so, libc.so.6 libm.so.6 다이나믹 라이브러리만 보여야하고 (실제 파일들을 포인팅하고 있음)   
lua 관련이 없어야 한다.  
 
`ldd getudev | grep lua`  
아무것도 안나와야 함


여기에서 비교해보면 lua5.3 일반 방식으로 사용했다면  
liblua5.3.so.0 => /lib/x86_64-linux-gnu/liblua5.3.so.0 (0x00007f15681c5000)  
이런식으로 나오게 되고 이게 문제가 되는게   
Fedora에서 확인해보면 해당 라이브러리를 찾을 수가 없게 된다.  
liblua5.3.so.0 => not found   
이래서 실행이 안 되는 것.. 다이나믹 so파일을 활용하게 되면 실행할 때 런타임으로 라이브러리가 필요하고  

glibc 관련을 위반하지 안해서 다른 libstdc libc 등을 그대로 사용할 수 있게 되는 것.  


## 팁
옵션으로 빌드할 때 좀 더 유연하게 static 라이브러리를 사용안하고  
다아나믹 라이브러리 , 시스템 라이브러리를 사용하게 할 수 있다.

```
option(USE_STATIC_LUA "Use static Lua 5.3" ON)

if (USE_STATIC_LUA)
    set(LUA_ROOT /opt/lua-5.3-static)
    add_library(lua STATIC IMPORTED)
    set_target_properties(lua PROPERTIES
        IMPORTED_LOCATION ${LUA_ROOT}/lib/liblua.a
        INTERFACE_INCLUDE_DIRECTORIES ${LUA_ROOT}/include
    )
else()
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(LUA REQUIRED lua5.3)
endif()
```
이렇게 하고 cmake configure를 할 때 해당 옵션 -DUSE_STATIC_LUA=OFF 이렇게 사용하면 develop 버전이 된다.  
> 만약 fedora에서 빌드를 할 경우  
또한 else 케이스에서 target_include_directories, target_link_libraries, target_compile_options 등을  
Lua 로 통일 해주면 좋다.

