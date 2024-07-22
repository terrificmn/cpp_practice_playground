# foreach

먼저 set으로 변수를 만들어 주고
```
set(EXAMPLES
    test_read1
    test_read2
    test_write1
    test_write2
)
```

이후 EXAMPLES에서 하나씩 꺼내와서 loop로 진행하면서 아래처럼 사용이 가능하다.
```
foreach(example ${EXAMPLES})
    add_executable(${example} src/${example}.cpp)
    target_include_directories(${example} PUBLIC ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries(${example} 특정_lib)
endforeach()
```

add_executable, target_include_directories, target_link_libraries 의 앞에 오는 example은 각각 패키지 이름이 되고   
그 이하에도 적절히 사용할 수가 있는 듯 하다.

