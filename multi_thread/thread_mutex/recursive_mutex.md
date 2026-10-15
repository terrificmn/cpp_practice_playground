# recursive mutex

A normal std::mutex has one strict rule: the same thread must not lock it twice.  
If it tries, the thread waits for itself forever. This is called a deadlock.  

A std::recursive_mutex relaxes this rule. The same thread may lock it many times.   
It keeps a counter: each lock adds one, each unlock removes one.   
The lock is really released only when the counter reaches zero.  
Other threads are still blocked the whole time, so the protection is the same.   

I used it because updateRobotInfoFile locks the mutex and then calls the read helpers, which lock the same mutex again on the same thread.  
With a normal mutex that pattern would deadlock. With a recursive mutex it works.  
