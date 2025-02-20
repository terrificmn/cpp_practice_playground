// 리눅스 방식인 LF '\n' newline  
// 윈도우 방식인 CRLF '\r\n'  carrage return 과 rewline 케릭터를 포함해서 줄 바꿈을 해준다.

// 이게 std::getline() 함수를 사용하면 `\n`는 알아서 없에주는데 
// CRLF 에는 \n 만 제거가 되고 \r 이 남아 있어서 해당 line 을 변환하거나 사용할 때 잘 작동 안 할 수가 있다.

// ex) \r 이 있으니 empty() 상태는 아니므로, 숫자로 변환한다던가 할 경우에 문제가 발생할 수 있음.

#include <iostream>
#include <fstream>

std::string trimLeft(const std::string& line) {
    size_t index = 0;

    /// case CRLF
    while(index < line.size()) {
        /// to find the index of any space or '\r' by adding start_index
        if(std::isspace(static_cast<unsigned char>(line[index]))) {
            index++;
            ///space 등이 있으면 index를 증가 시켜준다.
        } else {
            break;
        }
    }
    // 스타트 index가 증가 된 만큼 substr을 끝까지 해서 스페이스 등이 있다고 하면 예를 들어 2칸 있었다고 하면 거기 에서 부터 끝까지 밀어 버리는 효과
    return line.substr(index);
}

int main() {

    /// IMPORTANT: my_lf_crlf 파일을 LF 또는 CRLF 로 변경해서 저장한 후 실행해본다. vscode 에서 쉽게 변경할 수 있음
    std::ifstream myFile("my_lf_crlf");
    if(myFile.is_open()) {

        std::string line;
        while(std::getline(myFile, line)) {
            /// 1번째 방법,, 주석을 풀고 테스트 (2번째 방법을 주석 처리)
            /// FYI: CRLF 형식일 때 '\r' 로 검출할 수도 있지만. 아예 std::isspace() 를 통해서 할 수도 있다.
            // if(line[0] != ' ' && line[0] != '\r') {
            //     std::cout << "line: " << line << std::endl;
            // } else {
            //     std::cout << "space found\n";
            // }

            /// 2번째 방법
            /// 아예space를 제거하는 함수를 사용해서 다시 line 변수에 넣어준다. LF/ CRLF 상태와 상관없이 \r, ' '스페이스 등을 지울 수가 있다.
            line = trimLeft(line);
            if(line.empty()) {
                std::cout << "space found\n";
            } else {
                std::cout << "line: " << line << std::endl;
            }
        }
    }

    

    return 0;

}

// g++ -std=c++17 -o crlf_lf crlf_lf_getline.cpp 