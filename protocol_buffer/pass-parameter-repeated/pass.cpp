
/*
proto 파일에서 repeated 로 만들어서 array 형태인 경우에는 프로토 버퍼로 클래스가 만들어졌다면  

예
message MyType {
    optional int32 my_variable1 = 1;
    optional bool my_variable2 = 2;
}

message MyData {
    repeated MyType myType = 1;
}

*/

// 정의
void passRepeated(const google::protobuf::RepeatedPtrField<proto::MyType>& myTypes);

식으로 넘길 수가 있다. 

for loop에서 
배열로 되어 있으므로 const proto::MyType& myType = myTypes[i] 식으로 받거나   

for(auto& myType : myTypes) {
    std::cout << myType.my_variable1() << std::endl;
} 





