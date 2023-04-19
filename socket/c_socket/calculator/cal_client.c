#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 1024
#define RLT_SIZE 4
#define OPSZ 4
// tcp_clientv2.c 파일은 read() 함수를 while문에서 반복을 해서 전송한 데이터 만큼 수신하기 위해서 반복 호출하게 된다   
// iterative_echo 패키지의 echo_s 서버와 실행을 같이 해주면 된다

void error_handling(char *msg);

int main(int argc, char* argv []) {
    int sock;
    char op_msg[BUF_SIZE];
    struct sockaddr_in serv_addr;
    char message[BUF_SIZE];
    int result, opnd_cnt, i;

    if(argc !=3) {
        printf("Usage : %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    // socket 생성  //Sock_stream 연결지향형
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        error_handling("socket() error");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // client 에는 connect()가 있음
    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("connect() error");
    } else {
        puts("Connected.......");
    }

    fputs("Operand count: ", stdout);
    scanf("%d", &opnd_cnt);
    op_msg[0] = (char)opnd_cnt; // type change

    // 서버에서 보내주는 데이터를 읽는다. 메세지의 카운트로 하나씩 read해보면 바이트만큼 함수가 호출되서 사용된다 
    for(i=0; i < opnd_cnt; i++) {
        printf("Perand %d", i+1); 
        scanf("%d", (int*)&op_msg[i * OPSZ +1]);

        fgetc(stdin);
        fputs("Operator: ", stdout);
        scanf("%c", &op_msg[opnd_cnt * OPSZ +1] );
        write(sock, op_msg, opnd_cnt * OPSZ +2);
        read(sock, &result, RLT_SIZE);

        printf("Operation result: %d\n", result);
    }

    close(sock);
    return 0;
}


void error_handling(char* msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
