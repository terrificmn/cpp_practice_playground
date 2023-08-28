# crc check 
모드 버스 테스트 

```
g++ -o test ./src/crc_check.cpp -I ./include
```

입력 받는 모드는 없고, 각각 함수에 지정된 data 값만 읽어서 crc 프린트 해주는 프로그램  

## libcrc2.0
libcrc는 빌드  
```
cd libcrc-2.0
make all
```

빌드시 에러 `'ignoring return value of fgets' in C` 이라면  
tstcrc.c 파일의 약 100번째 줄을 수정

```c
if ( do_ascii  ||  do_hex ) {
    printf( "Input: " );
    if(fgets( input_string, MAX_STRING_SIZE-1, stdin ) == NULL) {
    }
}
```
처럼 수정하고 다시 빌드   


실행 
```
./tstcrc -x
```

> -x 옵션은 HEX 코드 넣어주는 것

실행 입력 예 (띄어쓰기로 구분)
```
10 20 30 40
```

이 중 결과의 CRC16 (Modbus) 를 참고해주면 된다.  
**결과는 뒤 바뀌어서 나오게 되어 있다** 뒤의 2자리가 앞의 앞2자리 이다  
```
Input: 10 20 30 40
"" :
CRC16              = 0xFA10      /  64016
CRC16 (Modbus)     = 0xDE10      /  56848
CRC16 (Sick)       = 0x2030      /  8240
CRC-CCITT (0x0000) = 0xD030      /  53296
CRC-CCITT (0xffff) = 0x54F0      /  21744
CRC-CCITT (0x1d0f) = 0xDE20      /  56864
CRC-CCITT (Kermit) = 0x3C34      /  15412
CRC-DNP            = 0x0CC7      /  3271
CRC32              = 0xE08AB900  /  3767187712
```

즉, 10 DE 가 crc 체크된 값

