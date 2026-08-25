#include "th_pool.hpp"

ThreadPool::ThreadPool(size_t num_threads) {
    for(size_t i=0; i < num_threads; ++i) {
        workers_.emplace_back([this] {
            workerLoop();
        });
    }
}

ThreadPool::~ThreadPool() {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        stop_ = true;
    }
    cv_.notify_all();
    for(auto& t : workers_) {
        t.join();
    }
}

// Submit a task, get a future back for the result
template <typename F, typename... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) -> std::future<std::invoke_result_t<F, Args...>> {
    using ReturnType = std::invoke_result_t<F, Args...>;

    auto task = std::make_shared<std::packaged_task<ReturnType()>> (
        std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );
    std::future<ReturnType> result = task->get_future();

    {
        std::lock_guard<std::mutex> lock(mutex_);
        if(stop_) throw std::runtime_error("enqueue on stopped ThreadPool");
        
        tasks_.emplace([task] {
            (*task)();
        });
    }

    cv_.notify_one();
    return result;
}

void ThreadPool::workerLoop() {
    while(true) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(mutex_);
            cv_.wait(lock, [this] {
                return stop_ || !tasks_.empty();
            });

            if(stop_ && tasks_.empty()) return;

            task = std::move(tasks_.front());
            tasks_.pop();
        }

        task();
    }
}


int main() {
    ThreadPool tp(4);

    auto fut = tp.enqueue([](int x) { 
        return x * x; 
    }, 21);


    auto fut2 = tp.enqueue([] {
        return std::string("hello");
    });


    std::cout << fut.get() << std::endl; // 42... well, 441
    std::cout << fut2.get() << std::endl;

    return 0;
}
