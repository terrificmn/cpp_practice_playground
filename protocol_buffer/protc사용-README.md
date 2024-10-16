 
현재 디렉토리에서 사용할 경우 (.proto 파일이 있는 상위)  
```
protoc -I=`pwd` --cpp_out=`pwd` `pwd`/addressbook.proto
```

optional 옵션을 사용해서  proto 를 만드는 경우에는 (아마도 버전에 따라 다른 듯 하다.)   
--experimental_allow_proto3_optional 옵션을 넣어달라고 한다. 

proto파일이 있는 경로로 먼저 이동 후에, 아래 예시 처럼 입력
```
protoc -I=`pwd` --cpp_out=`pwd` `pwd`/my-filename.proto --experimental_allow_proto3_optional
```

현재 디렉토리에 addressbook.pb.h 파일과 addressbook.pb.cc 파일이 만들어 진다.

엄청 긴 내용 중에서 
```cpp
  // name
  inline bool has_name() const;
  inline void clear_name();
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline ::std::string* mutable_name();

  // id
  inline bool has_id() const;
  inline void clear_id();
  inline int32_t id() const;
  inline void set_id(int32_t value);

  // email
  inline bool has_email() const;
  inline void clear_email();
  inline const ::std::string& email() const;
  inline void set_email(const ::std::string& value);
  inline void set_email(const char* value);
  inline ::std::string* mutable_email();

  // phones
  inline int phones_size() const;
  inline void clear_phones();
  inline const ::google::protobuf::RepeatedPtrField< ::tutorial::Person_PhoneNumber >& phones() const;
  inline ::google::protobuf::RepeatedPtrField< ::tutorial::Person_PhoneNumber >* mutable_phones();
  inline const ::tutorial::Person_PhoneNumber& phones(int index) const;
  inline ::tutorial::Person_PhoneNumber* mutable_phones(int index);
  inline ::tutorial::Person_PhoneNumber* add_phones();
```

.proto 파일에 만들었던 클래스를 그대로 만들어 주는데   
각 변수로 지정했던 이름 앞에   
set_, has_ 가 붙은 메소드들이 만들어지고 모든 clear_ 메소드들도 만들어짐. un-sets 할 수 있음  

예를 들어서  name 있었고, set_name() has_name(), clear_name() 등이 만들어짐


string으로 만들었다면, mutable_ 의 getter가 생기고(포인터로 받을 수 있다.)  
예 mutable_email()  email 셋이 안되었다면 empty를 받게됨


repeated로 만들면 suffix _size() 통해서 크기 확인.  예 phones_size()  
phones(int index) 에서는 인덱스로 넘겨서 특정 전화번호 를 리턴받을 수 있다.


## standard message methods

bool IsInitialize() const;  특정 필드가 set 되었는지 확인   
string DebugString() const;  디버깅 용 스트링   
void CopyFrom(const Person& from);  아규먼트 들어 온 것으로 덮어쓸 수가 있다.   
void Clear(); clear   

## parsing and Serialization
bool SerializeToString(string* output) const;   string 들어온 것으로 byte로 만들어 저장. (binaray이고 text형태가 아님)  string은 편의상 사용   

bool ParseFromString(const string& data);   string으로 들어온 메세지 parse

bool SerializeToOstream(ostream* output) const;   c++ ostream 으로 들어온 것을 쓰기

bool ParseFromIstream(istream* input);     c++ istream 의 메세지를 parse



### 내 패키지에서 cmake 하기
지금 protocol_buffer 디렉토리의 CMakeLists.txt 를 참고하자.   

> abseil를 포함할 일은 없는 것 같다..  protobuf 가 의존성 abseil 이 의존성이 있다고 해서    
이것저것 해봤지만 오히려 안되기만 함   
따로 abseil을 포함하지 않아도 잘 빌드가 된다. (예: find_package 안하기 등..)   


### libprotoc 사용 시
cartographer 설치할 때 의존성으로 설치되는 libprotoc 버전은 3.12.4

직접 빌드해서 bazel 로 빌드하면 libprotoc 29.0-dev 버전이 되어서 버전이 크게 다르다.  (아마도 최신 버전)   
이 상태에서 colcon 빌드를 하게 되면 
google/protobuf/runtime_version.h 파일을 찾는데 이게 없어서 에러가 발생   

일단 버전 **3.12.4** 으로 사용하는 것이 편하고 쉬울 듯 하다.   
> 물론 runtime_version.h 가 필요 없음



### 중첩 되어 있는 오브젝트 등을 사용할 경우 
proto 로 다른 파일에서 같은 오브젝트를 적용할 경우에 실제 그 예를 들어 myproto.pb.cc 파일을 사용할 때  
이미 해당 오브젝트 등이 정의 되어 있다라고 하는 에러가 발생한다 

> protoc 로 빌드할 때는 별개로 문제가 없다. 

이럴 때에는 proto 파일에서 중복된 오브젝트가 있는 특정 파일을 import를 하고   
이후 사용할 수가 있다 


### proto로 만든 클래스가 인식이 안될 경우 tip
예를 들어서   
```
my_file.cpp:xxxxxx...생략.. undefined reference to 'proto::MyProtoFile::MyProtFile'
```

CMakeLists.txt 에서 proto 파일 관련 .cc .h 파일을 add_library() 등에   
경로 잘 맞춰서 넣었고, 
해당 proto 버퍼로 만들어진 클래스를 사용할 header 파일도 잘 인쿠르드해서 문제가 없는 경우에는  

CMakeLists.txt 파일을 한번 변화를 준다. 예를 들어서 스페이스바를 한번 입력을 해서 파일 자체가 변화되게 한다음에   
저장하고   
colcon build 를 해주면 해당 파일을 잘 찾아서 빌드를 해준다. 

> CMakeLists.txt 파일이 변화가 있어야지 새로 file들을 추가해 주는 듯 하다.   
`file(GLOB PROTO_HDRS "*.pb.h")` 이렇게 파일을 추가한 것과 관련이 있는 건지 잘 모르겠다.   


