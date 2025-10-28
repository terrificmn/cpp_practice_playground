# libcurl ftps
plain ftp 상황에서는 
```cpp
    curl_easy_setopt(curl, CURLOPT_USERNAME, "ftpuser");
    curl_easy_setopt(curl, CURLOPT_USERPWD, pwd.c_str());
    // Set passive/active modes
    curl_easy_setopt(curl, CURLOPT_FTPPORT, passive_ ? nullptr : "-");
```
Plain FTP 는 *ftp://..* 이렇게 시작을 하면 된다. 

## SSL 을 사용해야하는 경우
plain 방식으로 접속하면  
```
> USER ftpuser
< 530 Non-anonymous sessions must use encryption.
* Access denied: 530
* Closing connection 0
```
이런식으로 에러가 발생한다. 

ftp 서버가 FTP server 에서 ssl_enable=YES 등이 되어 있다면 사용  
Explicit FTPS 등으로 접속해야 한다.

## version error
```
SSL routines::wrong version number
```
이 경우에는 
1. ftps:// 로 했지만 Explicit FTPS 인 경우   
2. 21번 포트로 접속했지만 Implicit FTPS 90번 포트인 경우 
등 ..


## Explicit FTPS
Ftp Server에서 explicit FTPS over TLS 를 사용하는 경우에는   

Explicit FTPS 를 사용하는 경우에는 ftp plain ftp로 시작하고 CURLOPT_USE_SSL 로 업그레이드를 해준다.   
주소는 **ftp://** 로 사용해야한다.   
> ftps:// 아님!

이렇게 나오는 경우라면 일단 Explicit FTPS 에 해당하고 *ftp://* 로 url 를 만들고 SSL 옵션을 넣어준다.  
```cpp
    /// // Set passive mode options (Recommended for most clients)
    curl_easy_setopt(curl, CURLOPT_FTP_USE_EPSV, 1L); // Use modern passive mode
    curl_easy_setopt(curl, CURLOPT_FTP_USE_EPRT, 0L); // Disable modern active mode
    curl_easy_setopt(curl, CURLOPT_FTP_FILEMETHOD, CURLFTPMETHOD_MULTICWD); 

    //// 여기서부터가 TLS 셋팅
    // Upgrade connection to TLS (explicit FTPS)
    curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);

    // Optional for testing: skip certificate checks
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

     curl_easy_setopt(this->curl, CURLOPT_FTP_FILEMETHOD, CURLFTPMETHOD_MULTICWD); // Recommended for directory path
     curl_easy_setopt(this->curl, CURLOPT_FTP_SSL_CCC, CURLFTPSSL_CCC_NONE);

```

FULL 예제 참고
```cpp
#include <curl/curl.h>
#include <iostream>

int main() {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        // ✅ Use ftp:// for explicit TLS (port 21)
        curl_easy_setopt(curl, CURLOPT_URL, "ftp://example.com:21/path/upload.txt");

        // ✅ Login credentials
        curl_easy_setopt(curl, CURLOPT_USERNAME, "ftpuser");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "ftppass");

        // ✅ Upgrade connection to TLS (explicit FTPS)
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);

        // Optional for testing: skip certificate checks
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        // ✅ Use passive mode (important behind NAT/firewall)
        curl_easy_setopt(curl, CURLOPT_FTP_SSL_CCC, CURLFTPSSL_CCC_NONE);
        curl_easy_setopt(curl, CURLOPT_FTPSSLAUTH, CURLFTPAUTH_DEFAULT);
        curl_easy_setopt(curl, CURLOPT_FTP_USE_EPSV, 1L);

        // ✅ Upload file
        FILE *file = fopen("localfile.txt", "rb");
        if (!file) {
            std::cerr << "Cannot open local file\n";
            return 1;
        }
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READDATA, file);

        // ✅ Perform upload
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

        fclose(file);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}
```


## Implicit FTPS 
이 경우에는  
*ftps://..* 주소를 시작하고 포트를 990 으로 맞춰야 한다. 주소 및 포트가 바뀌어야 하고   
위의 설정은 똑같이 해주면 된다. 
다만, 주소는 ftps 가 된다.  

예)
`ftps://192.168.0.2:990`


## sftp 사용하는 경우
완전히 다른 데몬 및 포트가 달라지는데, sshd 및 포트가 22 으로 사용  

주소가 *sftp://* 로 시작하면 되고, 일단 포트는 생략  

curl_easy_setopt() 에서 CURLOPT_USE_SSL 는 하지 않으며,  

다만 아래가 필요할 수도 있다. 단, optional  

```cpp
// Optional: specify SSH key or known hosts
// curl_easy_setopt(curl, CURLOPT_SSH_AUTH_TYPES, CURLSSH_AUTH_PASSWORD | CURLSSH_AUTH_PUBLICKEY);
// curl_easy_setopt(curl, CURLOPT_SSH_PUBLIC_KEYFILE, "~/.ssh/id_rsa.pub");
// curl_easy_setopt(curl, CURLOPT_SSH_PRIVATE_KEYFILE, "~/.ssh/id_rsa");
// curl_easy_setopt(curl, CURLOPT_SSH_KNOWNHOSTS, "~/.ssh/known_hosts");
```

