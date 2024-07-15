/// in a header file.
// template <typename T>
// int getIndexType();

//// in a cpp file
// template <typename T>
// int TypeHandler::getIndexType() {
//     // use typeid from typeinfo.h
//     if(typeid(T) == typeid(std::shared_ptr<int>)) {
//         ROS_INFO("Yes int pointer");
//     } else if(typeid(T) == typeid(std::shared_ptr<double>)) {
//         ROS_INFO("Yes double pointer");
//     } else if(typeid(T) == typeid(std::shared_ptr<bool>)) {
//         ROS_INFO("Yes bool pointer");
//     } else if(typeid(T) == typeid(std::shared_ptr<std::string>)) {
//         ROS_INFO("Yes str pointer");
//     }
//     return 0;
// }




/// @brief important to explicitly instantiate the template (사용될 type이 있다면 미리 선언해줘야 한다. compiler)
/// @return 
// template int TypeHandler::getIndexType<std::shared_ptr<int>>();
// template int TypeHandler::getIndexType<std::shared_ptr<double>>();
// template int TypeHandler::getIndexType<std::shared_ptr<bool>>();
// template int TypeHandler::getIndexType<std::shared_ptr<std::string>>();


int main() {
            // int res;
        // res = ExPtrTypeH->getIndexType<decltype(this->robot_id)>();
        // res = ExPtrTypeH->getIndexType<decltype(this->x)>();
        // res = ExPtrTypeH->getIndexType<decltype(this->status)>();

}