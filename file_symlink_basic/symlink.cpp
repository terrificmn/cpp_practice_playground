#include <iostream>
#include <filesystem>

// 아마도 c++17이므로 qt, catkin build로는 잘 되지만  g++로 하려면, -std=c++17 버전을 명시해준다 
// vscode에서 하려면 
// symlink 알아내기. 실제 실행될 파일의 경로와, 
// symlink 일 경우에 나오는 리턴 주소를 가지고 실제 경로를 알 수 있게 되므로 이 부분 std::filesystem::read_symlink(p)
// 실제 경로를 알게 되었으면 뒤의 파일을 잘라버리고, 부모 경로만 취한다. std::filesystem::absolute(origin_path.parent_path());
// 위의 origin_path가 심링크일 경우 리턴받은 변수가 된다. 이렇게 되면 딱 프로그램의 실제 위치가 나오게 되므로 나온 결과로 잘 써먹으면 된다 
int main() {
    for(std::filesystem::path p : {"/usr/bin/gcc", "/bin/cat", "/bin/mouse"}) {
        std::cout << p;
        std::filesystem::exists(p)
            ? std::filesystem::is_symlink(p)
            ? std::cout << " -> " << std::filesystem::read_symlink(p) << '\n'
            : std::cout << " exists but it is not a symlink\n"
            : std::cout << " does not exist\n";
    }
}