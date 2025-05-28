
lock 을 이용할 경우에 manually lock / unlock 을 할 수가 있는데  

std::unique_lock<std::mutex> lock(this->m_thread_mutex);
{
    lock.unlock();
    /// do some work
    
    lock.lock();
}
// to clean up
if(lock.owns_lock()) {
    lock.unlock();
}

이렇게도 할 수가 있지만, 수동으로 변경하는 것은 위험할 수도 있다.  
예를 들어서 lock 안 된 것을 unlock 하거나, 이미 unlock 되어 있거나  등등의 경우에 

__throw_system_error(int(errc::operation_not_permitted))  에러 발생   

unique_lock 을 사용할 경우에는 이런 경우에 
스코프를 지정해서 { } 해당 스코프를 빠져나오면 unlock 이 될 수 있게 해주면 해결된다   
{ 안에서 lock 을 소유하고 있다고 꼭 지정을 해줘야 한다 }


예

```
{
    std::unique_lock<std::mutex> lock(this->m_thread_mutex);
    this->m_thread_condition_variable.wait(lock, [this] {
        return this->is_connection_th_running.load();
    });
} // lock goes out of scope, automatically unlocked
```
