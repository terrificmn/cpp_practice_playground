#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 30

void error_handling(char *msg);

int main(int argc, char* argv[]) {
    int sd;
    FILE *fp;

    char buf[BUF_SIZE];
    int read_cnt;
    struct sockaddr_in server_addr;
    if(argc !=3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    fp = fopen("received_file", "wb");
    sd = socket(PF_INET, SOCK_STREAM, 0);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    connect(sd, (struct sockaddr*)& server_addr, sizeof(server_addr));

    while((read_cnt = read(sd, buf, BUF_SIZE)) != 0) {
        fwrite((void*)buf, 1, read_cnt, fp);
    }

    puts("Received file data");
    write(sd, "Thank you", 10);
    fclose(fp);
    close(sd);
    
    return 0;
}