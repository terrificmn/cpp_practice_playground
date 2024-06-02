#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <vector>

class MyClass {
public:
    void sub() {
        std::cout << "Starting sub method" << std::endl;

        // Launch multiple asynchronous serve tasks
        std::vector<std::future<void>> futures;
        for (int i = 0; i < 3; ++i) {
            futures.push_back(std::async(std::launch::async, &MyClass::serve, this, i));
        }

        // Perform other tasks while waiting for async operations to complete
        do_other_work();

        // Wait for all serve methods to finish
        for (auto& future : futures) {
            future.get();
        }

        std::cout << "Finished sub method" << std::endl;
    }

    void serve(int taskNumber) {
        std::cout << "Starting serve method " << taskNumber << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));  // Simulate a long-running task
        std::cout << "Finished serve method " << taskNumber << std::endl;
    }

private:
    void do_other_work() {
        // Simulate doing some other work
        std::cout << "Doing other work in sub method" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Finished other work in sub method" << std::endl;
    }
};

int main() {
    MyClass myClass;
    myClass.sub();
    return 0;
}