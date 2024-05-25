#include <iostream>
#include <chrono>
#include <functional>
#include <thread>
#include <future>

// 시간 설정으로 async타이머 돌리면서 main thread 에서는 While 루프에서 뭔가를 실행할 수 있는 프로그램

using namespace std::chrono_literals;

template<class _Rep, class _Period>
std::future<void> TimerAsync(std::chrono::duration<_Rep, _Period> duration, std::function<void ()> callback) {
    return std::async(std::launch::async, [duration, callback]() {
        std::this_thread::sleep_for(duration);
        // Dispatch()
        callback(); // callback()을 통해서 원래 호출한 곳으로 돌아간다.
    });
}

int main() {
    // 람다, 위의 TierAsync 람다 함수가 끝나면 메세지 출력
    auto future = TimerAsync(10s, []() {
        std::cout << "Timer finished." << std::endl;
    });

    while(true) {
        // Process main thread queue here
        std::cout << "now processing..." << std::endl;
        std::this_thread::sleep_for(1s); // work simulation

        // Optionally terminate program when timer is complete. 리턴이 void이지만, 상태를 계속 확인할 수가 있다.
        auto status = future.wait_for(1ms);
        if(status == std::future_status::ready) { // ready 는 끝난 상태 
            break;
        }
    }

    std::cout << "Program Finished.\n";

    return 0;
}
