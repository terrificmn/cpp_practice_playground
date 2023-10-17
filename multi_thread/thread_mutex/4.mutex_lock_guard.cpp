#include <iostream>
#include <thread>
#include <mutex>

std::mutex carMutex;

void driveCar(std::string driver_name){
    ///1. unique_lock lock을 사용할 instance를 만든다. 이때 std::mutex 인 carMutex를 넘겨준다
    // std::unique_lock<std::mutex> carLock(carMutex);  
    
    ///2. 또는 lock_guard를 만든다. 만드는 과정은 unique_lock과 같다
    std::lock_guard<std::mutex> carLock(carMutex);

    /// critical secssion 한 코드 부분 
    std::cout << driver_name << " is driving" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << driver_name << " is done driving" << std::endl;
    // carLock.unlock(); // unique_lock으로 만들었을 때에는 unlock을 해주는 작업이 꼭 필요하다!!
    // unlock() 으로 release를 안하게 되면 계속 block되는 현상이 생길 수 있다 
    
    // 단, lock_guard는 필요 없다
    // lock_guard는 simple and easier way to use mutex!
    // lock_guard는 소멸 되는 순간, 즉, end of function 등에서 unlock이 되게 된다. (자동)
    // 대신 - 매뉴얼적으로 수동으로 unlock할 수는 없다 
}
int main(){
    //thread 설정 시, 함수 이름, 함수에서 지정한 파라미터
    std::thread t1(driveCar, "Gunther"); 
    std::thread t2(driveCar, "Mike"); 

    t1.join(); // main에서 프로그램이 끝나기 전까지 thread t1의 작업을 끝날 때까지 기다림
    t2.join();
    // 이렇게 프로그램을 돌리게 되면 동시에 메세지가 뜬다. 예를 든 것이지만, 실제로 공유되는 변수는 없지만 
    // 자동차 자체는 동시 사용할 수가 없다
    // 그래서 원하는 결과는 Gunther가 driving이 끝나면 Mike가 사용할 수가 있어야 하는데  
    // 이를 가능하게 해주는 것이 lock 이다

    std::cout << "Press any key..will exit the program";
    std::cin.get();
}