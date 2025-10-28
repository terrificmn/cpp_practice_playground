/etc/vsftpd.conf
```
listen_address=0.0.0.0
listen=YES
listen_ipv6=NO
anonymous_enable=NO
local_enable=YES
write_enable=YES
local_umask=022
dirmessage_enable=YES
xferlog_enable=YES
connect_from_port_20=YES
xferlog_std_format=YES
pam_service_name=vsftpd
userlist_enable=YES
userlist_file=/etc/vsftpd.userlist
userlist_deny=NO
chroot_local_user=YES
allow_writeable_chroot=YES
user_sub_token=$USER
local_root=/home/$USER
#rsa_cert_file=/etc/ssl/certs/vsftpd.pem
#rsa_private_key_file=/etc/ssl/private/vsftpd.key
rsa_cert_file=/etc/vsftpd/vsftpd.pem
rsa_private_key_file=/etc/vsftpd/vsftpd.pem
pasv_min_port=30000
pasv_max_port=31000
ssl_enable=YES
force_local_logins_ssl=YES
force_local_data_ssl=YES
ssl_sslv2=NO
ssl_sslv3=NO
ssl_tlsv1=YES
require_ssl_reuse=YES
ssl_ciphers=HIGH
allow_anon_ssl=NO
force_local_data_ssl=YES
force_local_logins_ssl=YES
implicit_ssl=NO
pasv_address=luhana.ddns.net
pasv_addr_resolve=YES
```

listen=NO 보다는 YES 로 사용 ipv4 를 사용하는데 , ipv6와 충돌이 날 수가 있어서 
둘다 YES 가 안될 경우는 아래처럼 ipv6 를 NO로 설정
listen_address=0.0.0.0
listen=YES
listen_ipv6=NO

포트 잘 리슨 하고 있는지 확인
```
sudo netstat -tuln | grep 21
```
결과가 
```
tcp        0      0 0.0.0.0:21              0.0.0.0:*               LISTEN 
```
이렇게 나오면 ok

단. tcp6로 나오면 ipv6 이고 tcp 결과가 없으면 ipv4로 리스닝을 안하고 있는 것
```
tcp6 0 0 :::21 :::* LISTEN 
```

## Explicit FTP를 사용할 경우에는 

ssl_enable=YES
force_local_logins_ssl=YES
force_local_data_ssl=YES
ssl_sslv2=NO
ssl_sslv3=NO
ssl_tlsv1=YES
require_ssl_reuse=YES
ssl_ciphers=HIGH
allow_anon_ssl=NO
force_local_data_ssl=YES
force_local_logins_ssl=YES
implicit_ssl=NO

implicit_ssl 은 사용안 헐 것이므로 NO

## Dns 또는 DDNS hostname
Dns 또는 DDNS hostname이 있다면 아래처럼 설정
pasv_address=luhana.ddns.net
pasv_addr_resolve=YES

vsftpd가 external address 가 DDNS name 을 알 수 있게 해주고  
client가 private ip로 192.168.x.x 로 접속하지 않도록 한다. 

## passive
pasv_min_port=30000
pasv_max_port=31000
임의로 지정가능하며 외부에서 사용하게끔 portforwarding 해준다. range 로 처리  30000-31000 


## certs
처음에 데비안 기준으로는 이렇게 했었는데 나눠서 해도 되고, 통합해도 된다.
/etc/vsftpd.conf 중.. 
```
rsa_cert_file=/etc/ssl/certs/vsftpd.pem
rsa_private_key_file=/etc/ssl/private/vsftpd.key
```
>  key 파일은 key 확장자  cert file이 pem 이고  
-keyout 이 key, -out pem

기존 방식
```
sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/vsftpd.key -out /etc/ssl/certs/vsftpd.pem
```

vsftpd.conf 에 지정된 경로에만 잘 넣어주면, 잘 지정하면 알아서 잘 만들어 진다.

하나로 통합해서 만들기
```
sudo mkdir -p /etc/vsftpd

sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048   -keyout /etc/vsftpd/vsftpd.pem   -out /etc/vsftpd/vsftpd.pem
```
> .key 파일은 만들지 않고 -keyout, -out 옵션모두 같은 경로 및 vsftpd.pem 파일이름으로 지정

물론 vi /etc/vsftp.conf 열어서 아래처럼 같은 장소로 지정
```
rsa_cert_file=/etc/vsftpd/vsftpd.pem
rsa_private_key_file=/etc/vsftpd/vsftpd.pem
```

재시작
```
systemctl restart vsftpd.service
```

status 문제가 없어야 한다.
```
systemctl status vsftpd.service
```

## 추가cert
FileZilla 에서는 trust 하겠냐고 묻고, Self-signed certificate 이라서 그렇다. trust 한다고하면 
문제가 없지만    

libcurl 에서는 이게 문제도 될 수 있는 듯 하다.  
그래서 아래 처럼 아예 trust 할 수 있게 만들어 준다. 서버쪽에서 수행  

vsftpd.pem 파일을 카피 한 후
```
 sudo cp /etc/ssl/certs/vsftpd.pem ~/vsftpd.crt
 sudo mv ~/vsftpd.crt /usr/local/share/ca-certificates/
 sudo update-ca-certificates 
Updating certificates in /etc/ssl/certs...
1 added, 0 removed; done.
Running hooks in /etc/ca-certificates/update.d...
done.
```

복사해주고 update-ca-certificates  해준다.