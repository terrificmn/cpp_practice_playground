# cmke add_definition() 사용

CMakeLists.txt에서 변수로 셋팅한 후에  
cpp 파일에서 해당 변수를 불러서 사용할 수가 있다.  

```cmake
add_definitions(-DPACKAGE_SOURCE_DIR="${CMAKE_SOURCE_DIR}")  ## use this variable in a source file
```
뒤에는 CMAKE_SOURCE_DIR 은 공식으로 사용할 수 있는 변수 이고  
-D 로 시작하는 변수는 새로 생성하는 변수가 된다.    

이제 이를 cpp 코드에서 사용할 수 있다.
```cpp
std::string amrslam_app_path = std::string(PACKAGE_SOURCE_DIR);// from a cmake definition
```

따로 include 도 필요 없고 무난히 build가 된다.  

단, 이렇게 하면 빌드 단계에서 해당 경로가 아예 고정이 되므로   
install 이하 share 디렉토리에 생성된 파일 경로에는 경로 자체가 다르게 되므로   
symlink-install 빌드를 사용하거나   

아예 cmake 단계에서 install 를 이용해서 share 디렉토리 이하에  
설치가 되게 해주고 (예, 런치파일, config 파일 등)  

```cmake

```

이용해서 사용하면 shared 디렉토리를 찾아서 경로를 지정할 수 있으므로 도움이 될 수가 있다.
```cpp
#include <ament_index_cpp/get_package_share_directory.hpp>
```


