# AddMember() 시에 오류 
AddMember() 를 할 경우에 직접 char 형태로 직접 스트링을 넣어주면 크게 문제가 없으나, 

```
# document, AllocatorType 생략
rapidjson::Value scores(rapidjson::kArrayType);
scores.AddMember("score", "10", allocator); 
```

변수 스트링을 할당하려고 할 때 type 변환을 못해서 에러가 발생

```
# document, AllocatorType 생략
std::string score = "10";
rapidjson::Value scores(rapidjson::kArrayType);
scores.AddMember("score", score, allocator); 
```

보통은 .c_str() 함수를 사용하는 방식으로 잘 되었지만, AddMember()에서는 잘 안 됨.

에러는 
```
no matching function for call to 'rapidjson::GenericValue<rapidjson::UTF8<> >::GenericValue(std::__cxx11::basic_string<char>&)'
```

const 와 StringRef() 를 사용하라고 하는데 이것도 실패  

헤더파일에 
```
#define RAPIDJSON_HAS_STDSTRING 1
```
해주면 c_str() 함수 사용 안하고 바로 string 변수로 넣어주는게 된다. 

