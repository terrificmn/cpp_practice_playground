# option 과 연계해서 compile flags 만들기
compiler flag는 일단 string,  등을 지원하지 않기 때문에  
true, false, 1, 0  만 가지고 해야하기 때문에 두 개의 케이스를 설정하려고 할 경우에  
아래처럼도 사용할 수가 있다.

compile flags 를 두 개를 사용할려고 할 경우에 하나를 기본으로 두고 
기본이 아닐 경우에 다른 플래그를 셋팅하는 방법처럼 사용할 수 있음  
```cmake
option(MY_COMPILE_FLAG "my compile option" ON)  ## OFF
if(MY_COMPILE_FLAG)
    add_compile_definitions(MY_COMPILE_FLAG=1)
else()
    add_compile_definitions(ANOTHER_COMPILE_FLAG=1)
endif()
```

이제 MY_COMPILE_FLAG 는 defalut 가 ON (또는 OFF) 이므로 MY_COMPILE_FLAG 는 definition은 설정이 되었고  
cmake 를 할 경우에 해당 option을 ON OFF 함에 따라서 definition을 달리 사용할 수가 있다. 

```
cmake -DMY_COMPILE_FLAG=ON
cmake -DMY_COMPILE_FLAG=OFF
```

g++ 에 직접 적용하려면 하나씩 해주면 된다. 
```
g++ -DMY_COMPILE_FLAG=1
g++ -DANOTHER_COMPILE_FLAG=1
```


## c++ code preprocess 사용
`#ifdef or #ifndef` 도 사용할 수가 있으나, 이는 definition이 되었는지 유무만 확인한다. 
즉, 존재 유무만 확인하고 안의 value 는 확인하지 않는다.  
예) -DMY_COMPILE_FLAG=1 또는 0 이라고 설정해도 0은 캐치하지 못한다.   
`#ifndef`에서 캐치하려면 아예 -DMY_COMPILE_FLAG 자체를 사용안하면 된다.   

> 한개의 flag 일 때는 유용하게 사용할 수가 있다. 

`#if, #elfi #else #endif` 등을 사용  

이때는 true, false (1 / 0) 을 따질 수가 있어서 좀 더 유연하게 사용할 수가 있다. 

```cpp
#if MY_COMPILE_FLAG
    myCompileFlagFunc()
#elif ANOTHER_COMPILE_FLAG
    anotherCompileFlagFunc()
#else
    #error "No compile definition"
#endif
```


## string 도 사용은 가능

version tagging 에 유용할 수도 있음

```cpp
#if MYPROJECT_BUILD
constexpr const char* BUILD_NAME = "myProject";
#else
constexpr const char* BUILD_NAME = "public";
#endif
```
