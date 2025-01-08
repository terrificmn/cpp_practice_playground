#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <queue>
#include <chrono>
#include <functional>
#include <condition_variable>

/// 작동은 잘 되나, 조금 더 공부해보자 - 어떤식으로 활용할 수 있는지도 공부

// 여러개의 쓰레드를 사용할 경우에 사용
// 쓰레드를 만들고 계속 재사용 

// Thread 와, mutex, queue 등이 사용된다.

// 1. enqueue 작업으로 할당을 한 후 - 시그널을 줘서 (condition_variable 등) thread를 깨운다.
//     (기존 쓰레드는 계속 작업을 하고 있으면  cpu 컴퓨팅 파워가 낭비되므로 슬립을 시켜준다.)
// 2. mutex 를 사용해서 엑세스를 하는데 가드를 해준다.
// 3. vector를 이용해서 thread를 만들어준다.
// 4. function pointer를 가지는 queue를 만든다.
// thread를 계속 재활용한다. thread id를 보면 같은 것을 확인할 수가 있다.

class ThreadPoolExample {
private:
    bool is_stop;
    std::condition_variable condition_variable;
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;


public:
    ThreadPoolExample(int how_many_thread) : is_stop(false) {
        for(int i=0; i < how_many_thread; ++i) {
            /// store the thread -- // 람다 자체가 하나의 thread라고 보면 된다. 
            this->workers.emplace_back([this] {
                while(true) {
                    std::unique_lock<std::mutex> lock(this->queue_mutex);
                    // 예를 들어서 처음에는 is_stop은 fals, queue는 tasks는 아직 미할당. enqueue()로 할당을 시작하면 empty()가 아니니, 바로 wait이 해제
                    if(!this->is_stop && this->tasks.empty()) {
                        // wait
                        this->condition_variable.wait(lock);
                    }

                    /// 람다식으로 할 수 도 있는데, 아래 처럼 하면 제대로 작동, 다만, tasks.empty() 가 아닐 경우에는 ..이 부분이 헷깔림;;;
                    // this->condition_variable.wait(lock, [this] { return this->is_stop || !this->tasks.empty(); });

                    /// condition for the termination
                    if(this->is_stop && this->tasks.empty()) {
                        std::cout << "now is_stop & all tasks empty!!" << std::endl;
                        return;
                    }
                    auto task = std::move(this->tasks.front()); // tasks 에서 functional을 빼준다.
                    this->tasks.pop(); // queue tasks 에서 빼준다. 
                    lock.unlock();
                    task(); // Run the task // tasks queue에서 뽑아내면(?) 그 자체가 함수. 왜냐면 함수를 가지고 있다.
                    // 여기서의 funciton은 enqueue() 함수를 호출하는 부분의 내용이다.(람다로 되어 있음)
                    /// not block any thread
                }
            });  //lambda end
        }
    }

    ~ThreadPoolExample() {
        std::unique_lock<std::mutex> lock(this->queue_mutex);
        this->is_stop = true;
        lock.unlock();
        this->condition_variable.notify_all();
        for(std::thread& worker : this->workers) {
            worker.join();
        }
        std::cout << "All threads joined and finished.\n";
    }

    
    // enqueue 함수, F&& 는 rvalue 를 의미, function 을 rvalue로 받음
    template<class F>
    void enqueue(F&& task) {
        std::unique_lock<std::mutex> lock(queue_mutex);
        tasks.emplace(std::forward<F>(task));
        lock.unlock();
        // notify any thread to wake up
        condition_variable.notify_one(); // signal to wake up for thread
    } 


};

int main() {

    ThreadPoolExample threadPoolExample(4);
    std::cout << "Thread Pool started." << std::endl;
    
    std::cout << "now assign the tasks\n";
    // job 할당
    for(int i=0; i < 8; ++i) {
        // enqueue는 람다 함수 자체를 가지고 있다. queue
        threadPoolExample.enqueue([i] {
            std::cout << "Now Task: " << i << ", executed by thread id: " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        });
    }


    std::cout << "now program ends here." << std::endl;
    return 0;
}

// g++ -std=c++17 -o thread_pool pool.cpp -lpthread
