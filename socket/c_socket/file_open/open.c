#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    int fd;
    char buf[] = "hello open\n";

    // 현재 예제에는 open을 사용했는데, c 표준 라이브러리는 fopen()을 사용하는 것이 좋다고 함
    // fopen()은 버퍼 IO를 이용 더 빠르고, fgets, fgetc, fscanf, fread 등을 사용할 수 가 있다 
    // open()은 low-level의 os (system call)에서 사용하고, none-buffered 임
    fd = open("data", O_CREAT | O_WRONLY | O_TRUNC);
    if(fd == -1) {
        printf("error");
    }

    printf("file descriptor: %d\n", fd);

    if(write(fd, buf, sizeof(buf)) == -1) {
        printf("error write");
    }

    close(fd);

    return 0;
}