#ifndef _zookeeperutil_h_
#define _zookeeperutil_h_
#define THREADED  // 强制取消定义 THREADED，确保同步函数声明可见

#include<semaphore.h>
#include<zookeeper/zookeeper.h>
#include<string>

//封装的zk客户端
class ZkClient
{
public:
    ZkClient();
    ~ZkClient();
    //zkclient启动连接zkserver
    void Start();
    //在zkserver中创建一个节点，根据指定的path
    void Create(const char* path,const char* data,int datalen,int state=0);
    //根据参数指定的znode节点路径，或者znode节点值
    std::string GetData(const char* path);
private:
    //Zk的客户端句柄
    zhandle_t* m_zhandle;
};
#endif