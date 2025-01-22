#include <iostream>
#include <algorithm>

int main() {
    std::string cmd_for_userid = "id -nu 1000"; // Linux user searching by uid. shell command
    std::string sys_user;

    /// FILE 및 popen 을 이용해서 쉘 커맨드를 실행한 후의 결과를 받을 수가 있다.
    FILE *fp;
    char var[20]; 
    fp = popen(cmd_for_userid.c_str(), "r");
    while (fgets(var, sizeof(var), fp) != NULL) {
        printf("%s", var);
        sys_user += var; // char 를 계속 더해준다.
    }
    pclose(fp);
    std::cout << std::endl;

    std::cout << "Before: user: " << sys_user << " . seperated line." << std::endl;

    // remove whitespace like \n
    sys_user.erase(std::remove_if(sys_user.begin(), sys_user.end(), [](unsigned char c) { return std::isspace(c); }), 
                    sys_user.end());
    /// 여기에서 람다 함수는 std::remove_if() 함수의 세번째 파라미터로서 사용이 되는데, 
    /// remove_if 에서 iteration이 begin(), end()까지 진행이 되면서 string의 한 글자 한 글자가 파라미터로 넘어가서 
    // isspace()로 확인을 한다. isspce에서 해당 캐릭터가 whitespace 일 경우 (탭, 엔터, 스페이스 \t, \n 등..) 일 경우 true 를 리턴하게 되고 
    /// 여기에서 주의할점은 type은  unsigned char c 로 넘겨야 함 (또는 EOF)
    // 리턴 받은 자리를 remove_if 가 지워준다. 그리고 해당 글자의 마지막으로 리턴을 하게 된다.
    // 최종적으로 erase 함수에서 remove_if 에서 지운 글자의 마지막 부터, string의 마지막까지 지워줌

    
    std::cout << "After: user: " << sys_user << " . space removed. This should be a line." << std::endl;

    return 0;
}


