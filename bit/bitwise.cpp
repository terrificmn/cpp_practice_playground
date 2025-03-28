#include <iostream>
#include <cstdint>
#include <format>


int main() {
    int8_t value1 = 16;
    // /0b 로 시작해서 binary bit 알려주고 시작 ' 로 4자리씩 끊어서 표현도 가능
    int8_t value2 = 0b0000'0011;
    int8_t value3 = 0b0000'0111;

    std::cout << "value1: " << (int)value1 << std::endl;
    std::cout << "value2: " << (int)value2 << std::endl;
    std::cout << "value3: " << (int)value3 << std::endl;
    // cout으로 출력을 해주려면 int로 cast를 해줘야 한다.  binary 값을 decimal로 표현


    // binary 자체를 표시하려면 format 을 사용 {:b} 가 binarny
    ///FYI: format 함수는 c++20 부터 가능
    std::cout << "value3: " << std::format("{:b}", value3) << std::endl;

    std::cout << std::endl;

    // shift operation
    int8_t shift_left_value3 = value3 << 3;
    std::cout << "value3(decimal): " << int(value3) << std::endl;
    std::cout << "value3(b): " << std::format("{:b}", value3) << std::endl;
    std::cout << "value3(b): " << std::format("{:b}", shift_left_value3) << std::endl;
    std::cout << "value3(decimal): " << int(shift_left_value3) << std::endl;

    std::cout << std::endl;

    int8_t shift_r_value3 = value3 >> 1;
    std::cout << "value3(decimal): " << int(value3) << std::endl;
    std::cout << "value3(b): " << std::format("{:b}", value3) << std::endl;
    std::cout << "value3(b): " << std::format("{:b}", shift_r_value3) << std::endl;
    std::cout << "value3(decimal): " << int(shift_r_value3) << std::endl;

    ///1. Bit Packing
    /// binary로 되어 있는 데이터를 쉬프트 시켜서 원하는 값만 뽑을 수가 있다. 

    // 0x로 Hex로 표시 각각 r, g, b, a 로 구분지을 수 있고, 각각 8bits 로 구성됨
    int pixel = 0xFF'A0'00'CC;

    // Bitwise right shift 를 할 때에는 구성되어 있는 bits 에서 가장 마지막까지 밀어낸다고 생각하면 된다.
    uint8_t r = pixel >> 24; // 첫 번째에서 오른쪽 끝까지 오려면 8bit x 3 만큼 이동
    uint8_t g = pixel >> 16;
    uint8_t b = pixel >> 8;
    uint8_t a = pixel >> 0;  // The last one is not nedded to shift to right.

    std::cout << "Bitwise right shift\n" <<
        std::hex << "r: " << static_cast<int>(r) << "\t"
        << "g: " << static_cast<int>(g) << "\t"
        << "b: " << static_cast<int>(b) << "\t"
        << "a: " << static_cast<int>(a) << std::endl;

    ///2. Bit masking
    // mask를 씌워서 & 연산 (AND) 으로 처리해서 원하는 값 외에는 0으로 처리할 수가 있다.
    int mask  = 0xFF'FF'00'00;
    // int mask = 0xFF'00'00'FF; // or 일 경우에는 00 을 살린다. 
    /// &
    int filtered_value = pixel & mask; // ff만 살린다. 또는 원래 값과 같은 값, 마스크 값을 변경 시켜서 원하는 값만 남기게 해줄 수가 있음 (&)
    /// | /// FYI: or 조건이 조금 헷갈리는 듯하지만, 일단 00 false 인 것만 살린다고 생각해야할 듯. 좀 더 공부필요?
    // int filtered_value = pixel | mask; // &의 반대로 생각할 수 있다. 00 인 것은 나두고 FF은 ff 로 변경
    uint8_t r2 = filtered_value >> 24;
    uint8_t g2 = filtered_value >> 16;
    uint8_t b2 = filtered_value >> 8;
    uint8_t a2 = filtered_value >> 0;
    /// 마스크 처리된 것에서 쉬프트 연산을 하게 되면 원하는 값 외에는 0이 된다.
    std::cout << "Bit Masking -right shift\n" <<
        std::hex << "r2: " << static_cast<int>(r2) << "\t"
        << "g2: " << static_cast<int>(g2) << "\t"
        << "b2: " << static_cast<int>(b2) << "\t"
        << "a2: " << static_cast<int>(a2) << std::endl;



    return 0;
}

// format 함수를 사용안하면 c++17도 가능
//  g++ -std=c++20 -o bitwise bitwise.cpp