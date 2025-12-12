# g++ define marco 
g++ 만 사용할 경우에는 -DMY_VARIABLE=true 같은 방식으로 사용할 수 가 있다.  
바로 매크로 변수가 만들어져서 cpp 코드 내에서 사용할 수 있고, 빌드할 경우에도 유용하게 사용 가능

-DMY_VARIABLE=true  
-DMY_VARIABLE=false  
-DMY_VARIABLE=0  
-DMY_VARIABLE=1  

```
g++ --std=c++17 -o my_prog main.cpp -DMY_VARIABLE=true
```
원하는 값으로 만들 수가 있다.  

cpp 코드에서 사용할 경우에는 #ifdef, #if #else 등을 사용할 수가 있는데,  
#ifdef 또는 #ifndef 는 무조건 만들어져 있는지 여부를 보기 때문에 변수 자체가 선언되었다면 작동   
아예 빌드시에 사용하지를 않아야지 반대 조건이 성립한다.  

true, false 에는 대응하기 어렵다. 그래서 이럴때에는 #if 를 사용하면 된다.  

또한 이 변수들은 cpp 코드내에서 바로 출력하거나 사용할 수가 있다.  
```cpp
#if DMY_VARIABLE
    std::cout << "My variable set: true" << DMY_VARIABLE << std::endl;
#else
    std::cout << "My variable set: false" << DMY_VARIABLE << std::endl;
#endif
```


## cmake
cmake 할 때에도 비슷하게 사용할 수가 있다. 

```
cmake -S . -B build -DMyVariable=1   # true
cmake -S . -B build -DMyVariable=0   # false
```

## modern cmake
CMakeLists.txt 에서 아래처럼 사용  
add_compile_definitions(MY_VARIABLE)

or value 로 설정  
add_compile_definitions(MY_VARIABLE=${MyVariable})
