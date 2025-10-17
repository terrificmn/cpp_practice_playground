# utility::string_t

cpprestsdk 는 cross-platform & Unicode-aware 를 하기 때문에   
다른 OS에서도 잘 돌아갈 수 있게 되어 있어서  
text를 처리할 때에도 Windows 는 utf-16 (wchar_t)  
Linux는 utf-8 (char_t) 를 사용  

utility::string_t type를 제공하게 되는데 이는 각각
리눅스에서는 std::string 을 의미하고, 윈도우에서는 std::wstring 이 된다.  

## U 매크로
U 매크로를 사용하게되는 알아서 conversions 을 시켜주는데  
위에 처럼 리눅스, 윈도우 알아서 변경을 해주게 된다.  
`#define U(x) utility::conversions::to_string_t(x)` 이렇게 define 매크로 로 되어 있음   
예를 들어 `U("name")` 처럼 사용하면  utility::string_t 로 사용한다는 것임  

단 type 자체가 utility::string_t 되었으므로 실제 값을 넣어줄 때에는 std::string 이였다면 또는 char*  
에서는 utility::conversion::to_string_t("스트링")을 거쳐야 한다.  


## utility::conversions
```cpp
#include <cpprest/asyncrt_utils.h>
```
여기에 포함되어는 있는 기능으로  

```cpp
// JSON key, uri 등에 사용 std::string 을 utility::string_t 로 변경 
utility::conversions::to_string_t("abc")

// utility::string_t 를 std::string (utf8) 로 변경 : print 하거나 std::string이 다시 필요할 경우
utility::conversions::to_utf8string(str_t)

// window 용으로 변경 (std::wstring, utf-16)
utility::conversions::to_utf16string("abc") 
```

> to_string_t 는 그냥 std::string 이 아닌 utility 의 string임  


## 사용예
```cpp
#include <cpprest/json.h>
#include <cpprest/asyncrt_utils.h>
#include <iostream>

using namespace web;

int main() {
    // std::string from your app
    std::string name = "Alice";

    // Convert to utility::string_t (needed for cpprestsdk)
    json::value obj;
    obj[U("name")] = json::value::string(utility::conversions::to_string_t(name));

    // Convert back for printing
    std::wcout << L"JSON: " << obj.serialize() << std::endl;
}
```

이렇게 되면 Linux 에서는 UTF-8 기반으로 컴파일이 되고,  윈도우는 알아서 UTF-16으로 컴파일 된다. 

