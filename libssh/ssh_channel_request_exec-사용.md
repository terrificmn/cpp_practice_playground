## ssh_channel_request_exec() 사용
먼저 ssh session 만드는 것은 스킵 - 추후 정리 예정

`ssh_channel_request_exec`를 사용할 경우에 여러번 ssh로 명령을 수행하고 싶은데,  
여러번 수행할 경우 최초 한번만 수행을 하고 나서 이후 실행이 안 되는 것을 확인할 수가 있는데   

이유는 channel을 만들고 나서 한 채널에서 한번의 커맨드만 수행할 수 있다.   
interactive 형태이어서 한번에 한번씩 할 수 있게 되어있다. 수행을 한 후에 결과를 읽을 수도 있다.

TODO: read 부분도 이후 정리

약간의 트릭으로 커맨드 string 자체를 ';' 등으로 연결한 후 실행할 수 있는 방법이 있다.   
feedback이 필요없는 경우에 나쁘지 않을 듯 하다.   

```cpp
ssh_channel my_channel;

my_channel = ssh_channel_new(my_ssh_session);
if(channel == NULL) {
    fprintf(stderr, "Error channel: \n");
    return;
}

int rc = ssh_channel_open_session(my_channel);
if(rc != SSH_OK) {
    fprintf(stderr, "Error channel, channel freed: \n");
    ssh_channel_free(my_channel);
    return;
}

/// 여러 명령어를 ';' 결합해준다. 아마 '&&'도 가능할 듯 하다.
std::string new_command_in_a_row = "ll" + ";";
new_command_in_a_row += "pwd" + ";";
new_command_in_a_row += "cd" + ";";
std::cout << "----new command\n" << new_command_in_a_row << std::endl;


// 한번에 한번의 command 를 줘야해서 ';' 나 '&&'를 결합한 명령을 전달하면 여러 명령을 수행 가능하다.
rc = ssh_channel_request_exec(my_channel, new_command_in_a_row.c_str() );
if (rc != SSH_OK) {
    ssh_channel_close(my_channel);
    ssh_channel_free(my_channel);
} else {
    std::cout << "\nYes command worked.\n";
}

// channel 종료 및 free
ssh_channel_send_eof(my_channel);
ssh_channel_close(my_channel);
ssh_channel_free(my_channel);
```



## ssh_channel 을 여러번 만들기
';'로 연결하는 것이 아닌, 여러번 명령을 수행하면서 명령 수행을 확인할 경우에 사용할 수가 있다.   

일단 위의 channel 만드는 부분을 함수로 만들어준다.  
파라미터로 ssh_session과 ssh_channel 을 받을 수 있게 만들면 된다.

이런 느낌
```h
void newChannelOpen(ssh_session& my_ssh_session, ssh_channel& channel);
```

그리고 코드에서는 커맨드 스트링을 넣어주고 반복하면서 수행하게 하면 잘 작동한다.
```cpp
std::vector<std::string> v_commands = {
    "ll", "pwd", "cd"
};

for(int i=0; i < v_commands.size(); ++i) {
    ssh_channel my_channel;
    newChannelOpen(my_ssh_session, my_channel); // my_ssh_session 은 이미 for문 위에서 만들어져 있어야 한다.

    rc = ssh_channel_request_exec(my_channel, v_command(i).c_str());
    /// 딜레이 필요할지는 모르겠음?

    closeChannel(my_channel);
}

// 이후 ssh_session은 필요없을 때 종료/free 하게 해준다
```

세션을 열고, ssh_channel_request_exec(), 세션 닫기 가 한 세트로 진행되면   
ssh로 여러번 수행이 된다.


## read
TODO: 좀더 완성하기

read 같은 경우 `ls -l` 같은 명령은 feedback이 와서 출력이 가능하다.   

하지만 다 출력이 되는 경우는 아닌 듯, byte를 읽으면 처음부터 0으로 넘겨주는 명령들이 있는데, 

예를 들어서 `ll`  같은 경우에는 출력으로 read할 수 있는 게 없는 듯하다.  
git clone 같은 것도 그러하다 



