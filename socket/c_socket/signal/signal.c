#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timeout(int sig) {
    if(sig == SIGALRM) {
        puts(".. Time out");
    }
    alarm(2);
}

void keycontrol(int sig) {
    if(sig == SIGINT) {
        puts("CTRL+c pressed");
    }
}

//참고로... 최근에는 sinal()함수를 많이 사용하지는 않고, 호환성을 위해서 있다고 한다..
int main(int argc, char* argv[]) {
    
    /// sinal()함수는 특정 시그널이 발생했을 경우 핸들링 할 수 있게 함수를 지정해준다
    
    // 이런 signal() 같은 함수는 signal handler 라고 함
    signal(SIGALRM, timeout);
    signal(SIGINT, keycontrol); //SIGINT가 발생했을 경우 처리할 함수를 지정해준다
    alarm(2);

    for(int i=0; i<3; i++) {
        puts("wait...");
        sleep(100);  // sleep 을 발생시키면 SIGALRM 이 발생한다. 그러면 signal 핸들러가 발생
        // sleep함수에서 지정한 초는 100초 이지만, 
        // 그래서 시그널 핸들러의 호출을 하기 위해 sleep함수가 호출되면 블로킹 상태에 있던 프로세스가 깨어나게 되고 
        // 다시 블로킹이 안되기 때문에(다시 잠들지 않는다) 그래서 100초가 안되게 됨

    }

    return 0;
}
