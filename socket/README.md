# basic example of socket 
A synchronous TCP/UDP socker communication   

13번 포트를 사용하는 daytime 이라는 프로토콜을 이용해서 클라이언트에서 통신을 하면  
서버에서 스트링값으로 현재 시간을 넘겨주는 프로그램 예제  


## 빌드 
*pthread 라이브러리 필요*

- tcp 버전
```
cd tcp
g++ -o sock_client soc_client.cpp -lpthread
g++ -o sock_server soc_server.cpp -lpthread
```


- udp 버전
```
cd udp
g++ -o udp_client udp_sock_client.cpp -lpthread
++ -o udp_server udp_sock_server.cpp -lpthread
``` 

> 실행파일 이름은 원하는 대로..


## 실행
각각의 디렉토리에서 서버 같은 경우에는 sudo 명령어가 필요  
```
sudo ./sock_server
```

다른 터미널에서 클라이언트 실행
```
./sock_client 127.0.0.1
```