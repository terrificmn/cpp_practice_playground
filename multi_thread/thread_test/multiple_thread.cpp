#include <iostream>
#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <mutex>

std::mutex g_lock;

int main() {

    auto wrongMyLambda = [](int x) {
        /// thread 에는 id가 있어서 확인할 수가 있다. join되면서 thread가 막 실행이 된다. 순서 상관 없이
        std::cout << "Lambda Thread: " << std::this_thread::get_id() << std::endl;
        std::cout << "argument passed in is " << x << std::endl;
    };

    auto goodMyLambda = [](int x) {
        /// thread 에는 id가 있어서 확인할 수가 있다. 
        std::lock_guard<std::mutex> lock(g_lock); // lock_guard 를 사용하면  thread 를 보다 안전하게 사용할 수가 있다.
        std::cout << "Lambda Thread: " << std::this_thread::get_id() << std::endl;
        std::cout << "argument passed in is " << x << std::endl;
        
    };

    int thread_number = 5;
    std::vector<std::thread> v_threads;

    std::cout << "======= a bad example thread...,\n";
    for(int i=0; i < thread_number; ++i) {
        v_threads.push_back(std::thread(wrongMyLambda, 100+i));
    }

    for(auto& thread : v_threads) {
        thread.join();
    }

    /// IMPORTANT: 쓰레드를 여러개를 만들 때에는 vector에 차곡차곡 emaplace_back(), push_back()등으로 넣어주면 되나
    /// 쓰레드를 한번 join 또는 detach 하게 되면, 해당 thread가 끝났을 경우에 다시  join/detach가 불가능하고   
    // 이를 다시 하게 되면 runtime에러가 발생하게 된다. 
    /// 그래서 해당 vector, 여기에서는 v_threads 를 clear 시키고 , 다시 람다함수를 등록해주는 것이다. 
    /// 그러면 해당 thread는  join을 해서 다 끝나게 되고, 다시 vector를 클리어 후 다시 넣어주면서 람다 함수를 등록하게 되면 또 다시 작동하게 되면서 
    /// 계속 재활용이 가능하게 된다.  다시 thread를 join하게 되면 해당 연결했던 함수가 작동하게 된다. funciton poiunter로 생각하면 될 듯 하다.
    /// 만약 lambda가 아닌 클래스의 멤버 메소드로 사용하게 되면   
    /// std::thread())연결을 할 때 bind 함수로 연결해줄 수가 있다. 
    /// 예: v_threads.push_back(std::thread(std::bind(&MyClass::threadMethod, this)  )); 이런식으로 활용 가능
    
    
    /// Thread 를 몇개 사용한다고 하면 가스레인지의 화구로 생각하면 될 듯 하다.
    /// 그래서 vector에 thread를 추가하게 되면 여러개의 후라이팬을 추가하는 것과 비슷한 듯 하다.
    /// 요리 할려고 하는 기능 또는 요리는 람다 or 함수로 만들어서 연결만 시켜주고,
    /// join이 되면 불을 붙여서 요리가 시작된다고 생각하면 될 듯 하다.
    /// 이후 join이 끝나게 되면 함수, 요리가 끝나게 되고, 
    /// 다시 새로운 후라이팬과 요리방법을 다시 연결해서 계속 사용하는 방식이라고 할까? 이때 thread 갯수, 가스레인지 화구는 그대로 둔다고 생각. (물론 조절도 가능하겠다)
    /// 비유가 맞는지 모르겠다 ㅋㅋㅋ

    v_threads.clear();
    std::cout << "\n\n======= wait for a good example thread...,\n";

    for(int i=0; i < thread_number; ++i) {
        v_threads.push_back(std::thread(goodMyLambda, 100+i));
    }

    for(auto& thread : v_threads) {
        thread.join();
    }
    v_threads.clear();


    std::cout << "Now hello from main thread." << std::endl;

    return 0;
}

// g++ -std=c++17 -o multiple_thread multiple_thread.cpp -lpthread