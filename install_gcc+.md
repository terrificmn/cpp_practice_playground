vscode 내에서 빌드를 진행하려면 Terminal 메뉴에서 Run Build Task를 눌러서
나오는 컴파일러를 선택해야하느데 

만약 아무것도 안나온다면 터미널을 열고
```
g++ --version
```
입력해서 없다고 하면 설치를 해줘야한다

> g++은 GNU프로젝트 C, C++ 컴파일러

아래 명령으로 설치할 수 있다
```
sudo dnf install gcc-c++
```

이제 vscode를 다 종료 시킨 다음에 다시 켜보면
cpp로 만든 프로그램에서 위의 메뉴를 다시 실행시키면 
g++ build acvtive file 이 보인다

빌드를 한 후에 실행 가능한 파일로 권한이 되어 있기 때문에

터미널을 열어서 실행을 하면됨
```
./example
```

참고로 
CLI에 입력해서 빌드를 하려면 g++ -std=c++14 [your_source.cpp] -o [your_binary] 형식으로 입력
```
g++ -std=c++14 example.cpp -o example
```
