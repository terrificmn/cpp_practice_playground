#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

int main() {

    ///TODO: 그냥 주저리 주저리 정리해봤는데 추후 코딩으로 정리하기

    condition_variable 을 사용할 때에는 unique_lock 으로 사용해서 wait 함수를 사용하게 되는데  
    이를 사용할 때 bool 의 변수가 하나 필요하다, 또는 std::atomic<bool>   


    먼저 해당 bool 을 조건으로 넣어서 true가 되면 해당 조건에서 빠져나올 수 있게 된다. 

    그래서 bool 변수 하나 먼저 true 로 셋팅 후에 
    condition_variable.notify_one() 또는 notify_all() 등을 사용해서 한번 깨우게 되는데  
    만약 이때 위의 bool 변수가 true로 조건이 맞게 되면 바로 빠져나오게 되고 

    false 라면 다시 sleep 상태로 잠기게 되는 원리 이다.

    //  여기는 thread 함수 안이라고 가정
    while(true) {
        std::unique_lock<std::mutex> lock(my_mutex);
        my_condition_variable.wait(lock, [this] {
            return is_thread_running;
        });

        // do something
        if(!is_thread_running) {
            std::cout << "thread break" << std::endl;
            break;
        }
    }


    해당 쓰레드 함수를 실행할 때에는 해당 함수에서 
    {
        // 처음부터 is_thread_running 이면 튕겨낼 수도 있다.
    is_thread_running = true;
    my_condition_variable.nofity_all();


    myThread(&MyThread::threadTask, this); 처럼 연결하고 
    }

    종료하고 싶은 함수를 만든다면 
    {
        is_thread_running = false;
        my_condition_variable.nofity_all();
        처럼 만들어 주면 되는데 
        이때 is_thread_running false 되면 notify_all()을 통해서 깨어나면
        다시한번 condition_variable 에서 is_thread_running 을 확인하는데 이때 false 값이 므로 
        빠져나오지 못하고 break를 if문에 도달하지 못한다. 
        그래서 종료 함수를 만들고 싶으면 stop을 하고 싶은 변수를 하나 더 만들고 조건을 false 조건으로 달아서 만들면 해결된다.

        bool stop_need = true;

        다시 실제 thread의 while 루프안에 
        std::unique_lock<std::mutex> lock(my_mutex);
        my_condition_variable.wait(lock, [this] {
            return is_thread_running || stop_need ;
        });
        이렇게 해주면 stop_need 가 셋팅이 되면 OR 조건때문에 빠져나오게 되고  
        이후 break 문에 걸려서 thread를 종료할 수 있게 된다.

        이를 활용하면 thread 함수를 계속 sleep 을 시켜놓을 수가 있다. 
        bool is_standby 등을 만들어서 비슷하게 셋팅하면 된다. 
        std::unique_lock<std::mutex> lock(my_mutex);
            my_condition_variable.wait(lock, [this] {
            return (is_thread_running && !is_standby) || stop_need ;
        });
        is_thread_running 이 true, is_standby 가 false 일 때 TRUE 가 되어서 빠져나와 to do  something 하면 되고 ㅋ
        종료 함수에서 stop_need 를 true를 걸고 notify_one() 을 해서 해서 다시 한번 wait()함수에서 확인할 수 있게 해서 
        빠져나오게 되면 된다.

    }




    return 0;
}

// g++ -std=c++17 -o condition condition.cpp -lpthread