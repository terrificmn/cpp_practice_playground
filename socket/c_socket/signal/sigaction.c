#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timeout(int sig) {
    if(sig == SIGALRM) {
        puts(".. Time out");
    }
    alarm(2);
}

int main(int argc, char* argv[]) {
    struct sigaction act;  // sigaction 구조체를 선언하고
    act.sa_handler = timeout;  // sa_handler 에 function 포인터 값을 지정해준다
    sigemptyset(&act.sa_mask);  // sigaction 구조체의 sa_mask 는 모든 비트를 0으로 초기화해야함 // sigemptyset() 함수로비트를 0으로 초기화 하는데 
    act.sa_flags = 0;  // reset
    sigaction(SIGALRM, &act, 0);  // sigaction()을 해서 handler를 지정하게 된다. 
    // SIGALRM 이 발생하면 act의 주소의 sa_handler에 해당하는 함수가 호출되게 됨

    alarm(2);

    for(int i=0; i < 3; i++) {
        puts("Wait..");
        sleep(100);
    }

    return 0;
}