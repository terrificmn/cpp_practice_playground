iterator 를 사용해서 loop 돌리기 

기존 코드는 

std::set<int> set_int {
    1, 2, 3, 4
};

std::vector<RobotInfo> robotInfo;
RobotInfo (struct) 안에는 int robot_id가 있는 상황 

set_int 는 임의로 설정 (또는 입력받은 값) 이라고 할 경우에  
실제 robotInfo 안에 robot_id가 있고 이를 set_int 와 비교해서 실제로 있는지 확인할 해야하는 경우인데

for(auto& id : set_int) {
    bool is_user_input_valid=false;

    for(int i=0; i < robotInfo.size(); ++i) {
        if(robotInfo[i].robot_id == id) {
            this->sc.info("Found the id:", id, " in the RobotInfo");
            is_user_input_valid = true;
        }
    }

    if(!is_user_input_valid) {
        sc.warn("user's id:", id, "need to be removed.");
    }
}

이렇게 하면 set_int 를 ranged-loop 로 돌리면서 해당 id가(int)  robotInfo 안에 있는지 일일이 확인하는 방법인데 너무 비효율적이다.  
robotInfo가 많다면 그만큼 루프를 많이 돌게 된다.

그리고 치명적인 에러가 발생할 수 있는 부분은 
만약 set_int 에서 해당하는 id가 없다고 할 경우 erase 를 사용하게 되면 
 set_int.erase(robotInfo[i].robot_id);
포인터가 맞지 않기 때문에 에러가 발생한다. 


그래서 좋은 방법은 iterator 를 사용하는 방법이다.  
it 은 pointer가 되고
따로 for문 내에서 ++ 하는 코드는 없고, 직접 사용해야한다. 

for(auto it = set_int.begin(); it != set_int.end(); ) {
    if(u_set_robot_id.find(*it) != u_set_robot_id.end()) {
        this->sc.good("Yes, robot is", *it, "exists");
        ///IMPORTANT: iterator must ++ manually
        ++it;
    } else {
        this->sc.error("No, robot is", *it, "invalid");
        ///IMPORTANT: erase return next iterator
        it = set_int.erase(it);
    }
}

만약 erase를 사용하는 경우라면 자동으로 다음 iterator로 포인터가 넘어가게 된다. 
여기에서는 find 함수를 사용해서 해당 robot_id가 있는지 확인할 수가 있다.
robot_id가 확인 되었다면 ++it 으로 iterator 를 이동시켜준다.


Container	erase(it) returns	Iterator invalidation
set / map	next iterator	only erased invalid
vector	next iterator	all after erased invalid
list	next iterator	only erased invalid

