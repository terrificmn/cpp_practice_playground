#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

std::mutex g_lock;
std::condition_variable g_condition_variable;

// thread 가 spin이 계속 되고 있을 경우에, 예를 들어 t1, t2, t3... 등
// mutex 등으로 lock 을 걸면 다른 thread는 접근을 못하는데, 그래도 계속 체크가 되고 있는데 (나름 컴퓨팅 )
// 이를 thread/ multiple threads 를 block 시킬 수 있는 것이 std::condition_variable
// a synchronization primitive

/// synchronous 
// thread 에는 std::mutex 가 필요 (std::lock_guard 등)
// notify_one(), notify_all() 함수 등으로 사용가능하게 해주고, wait(뮤텍스) 으로 thread block을 시킨다.

/// condition_variable 은  a producer/consumer 같은 형태에서 사용이 될 수가 있다.
// 예를 들어 둘 다 무한 루프를 돌면서 queue등에서 활용할 때 사용할 수 있다.

///FYI: 확실히 loop 을 계속 사용하는 상태에서는 condition_variable 을 사용하면 효과적으로 thread를 제어할 수 있어서 좋을 것 같다. 
/// 다만, thread를 계속 만들어서 사용하는 경우: 예를 들어 vector에 만들어서 계속 사용하는 경우에 
/// 계속 while loop를 발생시키는 상황에서 g_condition_variable.wait(lock); 락을 걸고 
/// 또 다른 함수에서 trigger 를 시키면 다른 thread id 를 가지는 thread가 만들어지는데, 먼저 lock 이 걸린 thread 는 계속 있게 된다.   
/// 즉, 먼저thread가 종료가 안되었다면 계속 잠겨 있는 상태가 되고 새로운 thread에서 계속 작업이 될 수 있어서, thread가 실행이 되지 않도록  bool, condition_variable로 잘 제어를 해줘야 한다.  
/// (std::this_thread::get_id() 를 통해서 알 수 있음), mutex 와 condition_variable을 잘 활용해야한다.   
/// condition_variable2 를 확인하자.
/// thread 2개에서 계속 무한 loop로 사용하면서 뭔가 일을 할 때에 사용하면 좋을 듯 하다.

int main() {
    int result = 0;
    bool is_notified = false;

    // Reporting thread
    // Must wait on work, done by the working thread
    std::thread reporter([&] {  /// & reference 로 받는다.
        std::unique_lock<std::mutex> lock(g_lock);
        while(!is_notified) {
            /// wait causes tahe current thread to block
            g_condition_variable.wait(lock); // 특이하게도 contidion_variable 은 bool 형태의 while문을 한번 더 거친다. 
            /// **IMPORTANT test 시 is_notified 가 없더라도 wait은 작동 할 수 있으나, 
            /// false awakening 을 방지하기 위한 목적이 있다. - nofity_one()/all()을 받지 않았더라도 awakened 될 수가 있는데 
            // (이를 spurious wakeup 이라고 하는 듯 하다.)
            // 이를 확실하게 제어할 수 있게 bool 변수를 사용 - 이는 readability and maintainablity 에도 좋을 수 있다고 함
            /// if 보다는 while을 써야지 spurious wakeups 는 while  상요
        }
        std::cout << "Reporter, result: " << result << std::endl;
    }); 


    // working thread
    std::thread worker([&] {
        /// mutex lock을 쉐어 한다.
        std::unique_lock<std::mutex> lock(g_lock);

        /// do something
        result = 100;
        is_notified = true;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "Work Done!" << std::endl;

        // now wake up a thread, that is waiting for some condition to be true
        g_condition_variable.notify_one(); // sleep 중인 thread 를 lock() 풀렸다고? 알려줌. (Wake up 시켜준다)

    });

    // join threads.
    reporter.join();
    worker.join();

    return 0;

}


// g++ -std=c++17 -o condition condition.cpp -lpthread