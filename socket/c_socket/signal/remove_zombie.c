#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void readChildProc(int sig) {
    int status;
    pid_t id = waitpid(-1, &status, WNOHANG);
    if(WIFEXITED(status)) {
        printf("Removed proc id: %d\n", id);
        printf("Child send: %d]\n", WEXITSTATUS(status));
    }
}

int main(int argc, char *argv[]) {
    pid_t pid;
    struct sigaction act;
    act.sa_handler = readChildProc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGCHLD, &act, 0);   // SIGCHLD 를  signal handler로 등록한다 
    // 이에 자식 프로세스가 종료되면 readChildProc 함수가 호출된다

    pid = fork(); /// 자식 프로세스 만들기 

    if(pid == 0) {  ///// child process area /////
        puts("Hi~ Im a child process");
        sleep(10);
        return 12;
    } else {
        /// parent process area ////
        printf("child proc id: %d\n", pid);
        pid = fork();
        if(pid == 0) {   /// another child process area ///
            puts("hi~ I'm another child process");
            sleep(10);
            exit(24);

        } else {
            printf("child Proc id: %d\n", pid);
            for(int i=0; i < 5; i++) {
                puts("wait....");
                sleep(5);  // 부모 프로세스를 5초 동안 sleep을 걸지만 자식 프로세스가 
            }
        }
        
        return 0;
    }


}



