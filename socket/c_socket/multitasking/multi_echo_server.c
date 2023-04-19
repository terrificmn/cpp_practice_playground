#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 30

실행은 되나, 클라이언트에 보내는 것에 대한 응답이 write가 안되는 듯 하다 
다시 테스트 해 볼 것 - 17apr 2023

void error_handling(char* msg);
void readChildProc(int sig);

int main(int argc, char *argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    struct sigaction act;
    socklen_t addr_size;
    int str_len, state;
    char buf[BUF_SIZE];
    pid_t pid;

    if(argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // 좀비 생성을 막기 위한 signal 핸들러 정의 연결;;
    act.sa_handler = readChildProc;
    sigemptyset(&act.sa_mask);
    act.sa_flags =0;
    state = sigaction(SIGCHLD, &act, 0);

    server_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if(bind(server_sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind() error");
    }
    if(listen(server_sock, 5) == -1) {
        error_handling("listen() error");
    }

    while(1) {
        addr_size = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
        if(client_sock == -1) {
            continue;
        } else {
            puts("new client connect...");
        }

        /// accept 이후에 자식 프로세스가 만들어짐. 파일 디스크럽터를 부모, 자식 하나씩 생김
        pid == fork();

        if(pid == -1 ) {
            close(client_sock);
            continue;
        }

        if(pid == 0) {
            // 자식 프로세스의 실행영역이 된다 
            close(server_sock);  // 자식 프로세스를 만들면 부모 프로세스의 서버 소켓의 파일 디스크럽터까지 복사되므로 일단 close
            while((str_len = read(client_sock, buf, BUF_SIZE)) != 0) {
                write(client_sock, buf, str_len);
            }

            close(client_sock);
            puts("client disconnected...");
            return 0;

        } else {
            // 소켓관련 자식 프로세스한테 복사되었으므로, 부모 자신의 socket도 소멸시켜준다
            close(client_sock);
        }

    }
    
    close(server_sock);
    return 0;

}

void readChildProc(int sig) {
    pid_t pid;
    int status;
    pid = waitpid(-1, &status, WNOHANG);
    printf("removed proc id: %d\n", pid);
}

void error_handling(char* msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
