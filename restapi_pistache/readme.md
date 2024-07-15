
## 디펜던시
(rapidJson이 필요할 수도 있음)
meson 빌드

```
sudo dnf install meson
```

적당한 곳에 디렉토리 만들고 깃허브에서 다운

```
git clone https://github.com/pistacheio/pistache.git
cd pistache
meson setup build
meson install -C build
```

## CMakeLists.txt
CMakeLists.txt 파일을 만들어 준다. 현재 있는 CMakeLists 파일을 참고

build 디렉토리를 만들고 cmake
```
mkdir build; cd build; cmake ..
```



## 간단 후기
사용 예제가 많은 것 같지는 않다. 
차라리 crow 가 더 좋은 듯 하다.
