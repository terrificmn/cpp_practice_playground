// 긴 글;;;; 나중에 보면 생각이 잘 나려나? ㅋ

// 만약 thread 에서 while loop으로 계속 돌아가고 있는 상황에서는   
// async 함수가 계속 실행이 안 될 수 있게 해 줄 수 있는 flag 가 필요하다. bool 이나 std::atomic<bool> 로 flag 변수를 만들어주고   
// 무한 루프에서 async 함수가 계속 실행이 되게 되면 block이 되거나 원치않는 결과가 나오게 된다. 
// async 함수는 시작했을 경우에는 또 시작이 안되게 해줘야 한다.  

// 일단 flag로 예를 들어 is_running 이 false 일 경우에만 async 함수를 실행하게 하고   
// 이후 future로 리턴값을 받아 볼 수가 있는데 위에 예제에서는 async 함수가 void 이지만 bool 등을 리턴하게 한 후 
// std::future<bool> future_result 등으로 리턴을 받아서 그 결과 값을 확인할 수가 있는데   
// 이때 future_result 를 .get()으로 받게되면 이 역시 block이 된다. 
// 그래서 .wait_for(std::chrono::milliseconds(0)) 등을 이용해서 결과 값을 체크 할 수가 있다. 
// 0 초를 주게 되면 즉각적으로 체크한다. std::future_status::ready 이면 async 함수가 끝난 것을 의미한다.

// if(future_result.wait_for(std::chrono::milliseconds(0)) == std::future_status::ready))
// 이후 .get() 함수를 통해서 결과를 받아 오면 된다. 
// 이미 future 상태가 변경되었으므로 get()을 해도 block 없이 바로 결과를 받게 된다. 

// 마지막으로 주의할 것은 wait_for() 를 사용한다고 해도 async가 호출이 안되었을 경우에는 프로그램이 죽을 수 있으므로  
// 위에서 만든 flag 를 같이 체크한다. 예를 들어 is_running == true
// if(is_running && future_result.wait_for(std::chrono::milliseconds(0)) == std::future_status::ready)

// 로직은 이런식으로 작동하게 된다.

bool is_running = false;
std::future<bool> async_future;

while(true) {
    if(is_running) {
        //async started"
        async_future = startAsync(); // 이 함수에서 실제 std::async() 함수를 실행하고 future를 리턴
    } 

    // is_running flag를 확인해서 실제 작동할 때 future status를 확인할 수 있게 한다.
    if(is_running && async_future.wait_for(std::chrono::milliseconds(0)) == std::future_status::ready) {
        //"async finished"
        is_running = async_future.get();  // 퓨처를 리턴하는데 이를 그냥 is_running에 바로 할당해주자.
    }
}

std::future<bool> startAsync() {
    return std::async(std::launch::async ... /생략.., asyncfunc, /);
}

bool asyncfunc() {
    // do something
    return false;
}

