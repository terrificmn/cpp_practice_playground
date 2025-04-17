// ros2 에서 파라미터의 타입을 확인할 수가 있다.
// 하지만 아마도, declare_parameter 를 먼저 해주고 해야해서 크게 쓰임은 없을 듯 하다.;;

// param을 만들어 준다. parsam 
rclcpp::Parameter param;
if(myNode->get_parameter("my_param", param)) {
    // 아니면 switch case 사용 
    if(param.get_type() == rclcpp::ParameterType::PARAMETER_INTEGER) {
        my_param = std::to_string(myNode->get_parameter("my_param").get_value<int>());
        std::cout << "currently int value detected -> to_string to use" << std::endl;

    } else if(param.get_type() == rclcpp::ParameterType::PARAMETER_STRING) {
        this->my_param = myNode->get_parameter("my_param").get_value<std::string>();
        std::cout << "currently string value detected -> just use it" << std::endl;
    }
}

