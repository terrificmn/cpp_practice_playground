 

RobotInfo robot;
robot.id
robot.name
robot.alias_id 등이 있다...
///FYI: lambda's '=' read only(const), this lambda can modify value captured by value when 'mutable' is added
///FYI: RobotInfo oject will be copied in the lambda function.(outside RobotInfo will not be updated though)


이런식으로 사용한다고 할 경우에 
request.extract_json().then([=](pplx::task<web::json::value> json_task) mutable {
 web::json::value jsonObj = json_task.get();
    // DbService::RobotInfo robot;
    // std::string name, ip, mac_address, type, model, sub_ip, sub_mac_address;
    if(jsonObj.has_field(U("name"))) {
        robot.alias_id = jsonObj[U("alias_id")].as_integer();
        robot.name = utility::conversions::to_utf8string(jsonObj[U("name")].as_string() );

    }
});

            
const readonly 에서 에러 발생
//         error: cannot bind rvalue reference of type ‘std::__cxx11::basic_string<char>&&’ to lvalue of type ‘const string’ {aka ‘const std::__cxx11::basic_string<char>’}
//   234 |  robot.sub_mac_address = utility::conversions::to_utf8string(jsonObj[U("sub_mac_address")].as_string() );




2가지 방법이 더 있음.  
1. [&] reference 로 사용이 가능,그래서 수정이 가능하지만,  
람다 밖에 오브젝트가 네트워크 request가 끝날 때까지 유지가 되는 경우에마 크래쉬 없이 잘 사용할 수가 있다. 
즉, pplx 가 task가 끝나기전에 function에서 리턴하게되면 클래쉬


2. 마지막은 shared_ptr로 만들어서 사용하는 방법  
  이렇게 하면 람다함수가 필요로 할 때까지 shared_ptr를 유지할 수 있으므로 가장 best practice 임  
  Recommended for asynchronous/multi-threaded code.
  [ptrRobot] 이렇게 넘겨준다. 


[=] catch all by value
local 변수 및 this 를 사용할 수 있다.  this는 주의해야 할 점이 async가 작동할 때 해당 클래스가 살아 있지 않으면 this 로 인해 크래쉬가 날 수 있다 

  