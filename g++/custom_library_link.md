# custom library link 빌드
`/usr/local/lib/my_custom_lib/libmycustomlib.so` 에 다이나믹 라이브러리가 있다고 할 경우에  

*-L* 로 경로를 지정해주고, *-l* 라이브러리 이름을 지정해서 빌드 해줄 수가 있음.  
 
```
g++ -std=c++17 main.cpp -o test_proc -L/usr/local/lib/my_custom_lib -lmycustomlib
```

> -l 옵션에서 여기에서 so 파일의 prefix 인 lib 및 .so 확장자는 생략해준다.  


이후 빌드가 되었다면 LD_LIBRARY_PATH 에 넣어서 실행할 수 있게 해야한다.

빌드가 되더라도 실제 사용할 때는 환경 변수가 설정이 되어 있어야 하는데  
실제 실행을 해보면 아래와 같이 에러가 발생할 수가 있다.  
```
./testcpp: error while loading shared libraries: libmycustomlib.so: cannot open shared object file: No such file or directory
```

그래서 변수를 셋팅해서 사용을 하는데, 임시로 사용할 경우에는  
```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/my_custom_lib
```
> 디렉토리까지만 지정

영구적으로 사용하게 하려면 `/etc/ld.so.conf.d/custom_libs.conf` 을 열어서 경로를 추가해준다.  
*/usr/local/my_custom_lib* 을 추가해주고  
> 실제 파일은 없으므로 새로 생성한다.  
```
sudo ldconfig
```
을 해준다.  



## 실제 std_cout 예시
```
g++ -std=c++17 main.cpp -o my_proc -I/usr/local/include/std_cout -L/usr/local/lib/std_cout -lstd_cout
```

