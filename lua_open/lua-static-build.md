# lua static build
lua 를 static 으로 빌드해서 a 파일로 만들 때 사용  

다운로드 및 압축 풀기
```
wget https://www.lua.org/ftp/lua-5.3.6.tar.gz  
tar xf lua-5.3.6.tar.gz
cd lua-5.3.6
```

우분투 20 경우
```
make clean
make linux MYCFLAGS="-fPIC" MYLDFLAGS=""
```
> -fPIC flag가 중요  

우분투 22 경우  
readline.h 을 못찾는다고 나와서 빌드가 안되므로 libreadline-dev 설치해서 진행  
```
sudo apt install libreadline-dev
```
대신, readline 관련해서는 필요가 없다고 하니 빌드 때 스킵   
이유는 extra dependency 가 불필요  

```
make clean
make linux MYCFLAGS="-fPIC -DLUA_USE_READLINE=0" MYLDFLAGS=""
```

확인해보기. 해당 src 이하에 liblua.a 가 생겼다면 ok  
```
ls src/liblua.a
```

시스템 인스톨  
```
sudo make INSTALL_TOP=/opt/lua-5.3-static install
```

## 내 프로젝트에 lua 포함하기
```
변수 셋팅
# Lua static paths
set(LUA_ROOT /opt/lua-5.3-static)
```

add_library() 및 target_link_libraries
```
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

## 여기에서 dl m 은 lua가 필요로 하는 dependency
```

내 프로젝트를 빌드한 후 확인
```
ldd myapp | grep lua
```
아무런 결과가 안나와야지 정상이다.없으면 오케이!

> 만약 so 파일이 link 되었다면 무조건 해당 so 파일이 어디 있는지 위치를 나타내주게 되어 있음  
예를 들어서 이렇게 포인팅을 하고 있다.  
`liblua-5.4.so => /lib64/liblua-5.4.so (0x00007ffa6ab19000)`  

## 내 프로젝트를 또 다시 link 시키는 경우  
내 프로젝트(1)에 so 파일에 static library를 포함시켜서   
다시 한번 다른 프로젝트(2)에 link를 시켜려는 경우에는   
header files 이 필요하다  

이미 so 파일에 lua를 가지고 있는 경우지만,  
프로젝트(2)에서는 lua 에서 정의한 함수 라든가 변수 등의 정보가 전혀 없다.  
그래서 include 에 헤더가 있어야지 프로젝트(2)를 빌드할 수가 있다.  

물론 이렇게 해서 빌드가 완료가 되면 해당 프로젝트(2)는 다이나믹 lua 라이브러리를 가리키지 않는다.  

(lua_headers-static-lib.tar.xz) 파일을 사용  (헤더파일들)  

