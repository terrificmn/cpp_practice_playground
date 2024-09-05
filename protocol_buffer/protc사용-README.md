 
현재 디렉토리에서 사용할 경우
protoc -I=`pwd` --cpp_out=`pwd` `pwd`/addressbook.proto

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

