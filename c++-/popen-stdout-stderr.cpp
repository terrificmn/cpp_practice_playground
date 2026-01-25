bool FileHandler::checkGitRepo() {
    std::string status_str = this->getGitBasicInfo(pkg_path, GitType::GIT_STATUS);
    int status = status_str.find("fatal");
    this->m_sc.warn("status", status);
    if(status != std::string::npos || status_str.empty()) {
        this->m_sc.error("Not a git repository. Please check this dir:", pkg_path);
        return false;
    }

    return true;
}

위에서는 getGitBasicInfo() 깃 정보 결과를 리턴하는 함수인데, 결과 스트링에 fatal 이 있을 경우 에러메세지를 띄우는 코드 

만약 `std::system("git ~~~~");` 만 사용하는 경우라면  
stderr 로 출력되는 것은 확인할 수가 없다. 아예 empty 스트링이기 때문에 확인이 불가능  

계속 간단한 system 명령어만 사용하는 경우라면   
1. stderr 에서 stdout 리다이렉트를 해준다.  
std::string cmd = "your_command 2>&1";   // redirect stderr → stdout


2. 또는 popen 를 사용해서 파일을 열어주면 문제 없이 결과를 확인할 수가 있다.  

std::unique_ptr<FILE, decltype(&pclose)>
pipe(popen(cmd.c_str(), "r"), pclose);

char buffer[256];
while (fgets(buffer, sizeof(buffer), pipe.get())) {
    std::cout << buffer;
}


3. 또는 fork 를 이용해서 따로따로 확인할 수가 있다.  아래는 예제  

int outPipe[2];
int errPipe[2];
pipe(outPipe);
pipe(errPipe);

pid_t pid = fork();
if (pid == 0) {
    // child
    close(outPipe[0]);
    dup2(outPipe[1], STDOUT_FILENO);

    close(errPipe[0]);
    dup2(errPipe[1], STDERR_FILENO);

    execl("/bin/sh", "sh", "-c", cmd.c_str(), (char*)0);
    _exit(1);
}

// parent
close(outPipe[1]);
close(errPipe[1]);

// read stdout
char buffer[256];
while (read(outPipe[0], buffer, sizeof(buffer)) > 0) {
    std::cout << "[stdout] " << buffer;
}

// read stderr
while (read(errPipe[0], buffer, sizeof(buffer)) > 0) {
    std::cerr << "[stderr] " << buffer;
}

waitpid(pid, nullptr, 0);