
# FEP 文件交换协议 (File Exchange Protocol) 

某所用于传输文件的协议实现，已实现：
- UDP发送
- UDP接收
- TCP发送
- TCP接收


### 接收端

```cpp
auto recv = make_fep_server(fep_protocol::TCP);
recv->set_local_host({ "127.0.0.1", 28001 });
recv->run([](auto &&progress) {
    std::cout << "received file: " << progress.filename << " progress: " << progress.progress << std::endl;
});
```



### 发送端

```cpp
auto sender = make_fep_client(fep_protocol::TCP);
sender->set_local_host({ "127.0.0.1", 29001 });
sender->set_remote_host({ "127.0.0.1", 28001 });
sender->send("somefile.zip", [](auto &&progress) {
    std::cout << "send " << progress.filename << " progress: " << progress.progress << std::endl;
});
```



