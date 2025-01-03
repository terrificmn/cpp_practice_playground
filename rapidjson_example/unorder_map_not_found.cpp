
#include <unordered_map>

std::unordered_map<std::string, int> u_map;

// 대충 맞는지 모르겠지만 
if(u_map.find('something') == u_map.end()) {
    // 이렇게 되면 없다는 상태가 됨
}

보통 for문으로 사용할 경우
for(auto it = u_map.begin(); it != u_map.end(); ++it) {
    // it->first
    // it->second
    식으로 접근해서 사용한다. second가 value
}

