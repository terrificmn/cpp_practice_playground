#include <iostream>
#include <vector>
#include "crc_check.hpp"

CrcCheck::CrcCheck() {
    std::cout << "CRC INIT" << std::endl;
}

uint16_t CrcCheck::compute(std::vector<uint8_t>& data) {
    uint16_t crc = 0xFFFF;
    for (int i=0; i< data.size(); ++i) {
        // crc = (uint16_t)((crc>>8) ^ CrcTable[(crc ^ data[i]) & 0xFF]); === 아래의 함수 내용과 같음
        this->crcUpdate16(&crc, data[i]);
    }

    return crc;
}

void CrcCheck::crcUpdate16(uint16_t* crc, uint8_t data_i) {
    uint16_t tmp;
    uint16_t short_c;

    short_c = 0x00FF & (uint16_t)data_i;   // origin 은 short_c = 0x00FF & (uint16_t)data_i;  == 같은 uint8_t를 uint16_t에 넣어주면 같은 효과
    // short_c = (uint16_t)data_i;   // 같음

    // // calculate crc
    tmp = *crc ^ short_c;
    *crc = (*crc >> 8) ^ CrcTable[tmp & 0xFF];
}


void CrcCheck::setEnable() {
    std::vector<uint8_t> data;
    data.push_back(0x01); //id
    data.push_back(0x06); //write 1 value to adress
    data.push_back(0x20);  //0x 200E : control word
    data.push_back(0x0E);
    data.push_back(0x00); //0x0008  : enable
    data.push_back(0x08);
    uint16_t crc = this->compute(data);
    std::cout << "crc: " << std::hex << crc << std::endl; 

    uint8_t high = (crc & 0xFF00) >> 8;
    uint8_t low = crc & 0xFF;
    data.push_back(low);
    data.push_back(high);
    this->myPrint(data);
}

void CrcCheck::setZero()
{
    std::vector<uint8_t> data;
    data.push_back(0x01); //id
    data.push_back(0x06); //write 1 value to adress
    data.push_back(0x20);  //0x 2005 : clear feedback position
    data.push_back(0x05);
    data.push_back(0x00); //0x0000: invalid, 0x0001 left, 0x0002 right,  0x0003  : both left & right
    data.push_back(0x03);
    uint16_t crc = this->compute(data);
    std::cout << "crc: " << std::hex << crc << std::endl;    
    uint8_t high = (crc & 0xFF00) >> 8;
    uint8_t low = crc & 0xFF;
    data.push_back(low);
    data.push_back(high);
    this->myPrint(data);
}




void CrcCheck::myPrint(std::vector<uint8_t>& data) {
    std::cout << "------" << std::endl;
    std::cout << "crc1: " << std::hex << (int)data.at(6) << std::endl;    
    std::cout << "crc2: " << std::hex << (int)data.at(7) << std::endl;        
    
}

int main(int argc, char* argv[]) {

    CrcCheck crcChecker;
    crcChecker.setEnable();

    std::cout << "\n";
    crcChecker.setZero();

    serial::Serial ser;
    ser.set



    std::cout << "CRC END - Bye\n";

    return 0;
}