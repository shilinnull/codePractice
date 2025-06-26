#ifndef __MSG_QUEUE__
#define __MSG_QUEUE__

#include <iostream>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

const std::string PATHNAME = "/tmp";
const int PROJID = 0x77;
const int default_fd = -1;

// 创建方式
#define GET_MSGQUEUE (IPC_CREAT)
#define CREATE_QUEUE (IPC_CREAT | IPC_EXCL | 0666)

// 默认大小
const int defualt_size = 1024;

// 定义消息类型
#define MSG_TYPE_CLIENT 1
#define MSG_TYPE_SERVER 2

class MsgQueue
{
private:
    struct msgbuf
    {
        long mtype;
        char mtext[defualt_size];
    };

public:
    MsgQueue()
        : _msgfd(default_fd)
    {
    }
    void Create(int flag)
    {
        // 1. 创建key
        key_t key = ftok(PATHNAME.c_str(), PROJID);
        if (key == -1)
        {
            std::cerr << "ftok error" << std::endl;
            exit(1);
        }

        std::cout << "key: " << std::hex << key << std::endl;
        // 2. 创建消息队列
        _msgfd = msgget(key, flag);
        if (_msgfd == -1)
        {
            std::cerr << "msgget error" << std::endl;
            exit(2);
        }
        std::cout << "msgqueue created: " << _msgfd << std::endl;
    }

    void Destory()
    {
        int n = msgctl(_msgfd, IPC_RMID, 0);
        if (n == -1)
        {
            std::cerr << "msgctl error" << std::endl;
            return;
        }
        std::cout << "msgqueue destroyed" << std::endl;
    }

    void Send(int type, const std::string &text)
    {
        struct msgbuf msg;
        memset(&msg, 0, sizeof(msg));

        msg.mtype = type;
        memcpy(msg.mtext, text.c_str(), text.size());

        int n = msgsnd(_msgfd, &msg, sizeof(msg.mtext), 0);
        if (n == -1)
        {
            std::cerr << "msgsnd error" << std::endl;
            return;
        }
    }

    void Recv(int type, std::string &text)
    {
        struct msgbuf msg;
        int n = msgrcv(_msgfd, &msg, sizeof(msg.mtext), type, 0);
        if (n == -1)
        {
            std::cerr << "msgrcv error" << std::endl;
            return;
        }

        msg.mtext[n] = '\0';
        text = msg.mtext;
    }

    // 获取消息队列中的属性
    void GetAttr()
    {
        struct msqid_ds outbuffer;
        int n = msgctl(_msgfd, IPC_STAT, &outbuffer);
        if (n == -1)
        {
            std::cerr << "msgctl error" << std::endl;
            return;
        }
        std::cout << "outbuffer.msg_perm.__key: " << std::hex << outbuffer.msg_perm.__key << std::endl;
    }

    ~MsgQueue()
    {
    }

private:
    int _msgfd;
};

class Server : public MsgQueue
{
public:
    Server()
    {
        MsgQueue::Create(CREATE_QUEUE);
        std::cout << "server create msgqueue done" << std::endl;
        MsgQueue::GetAttr();
    }
    ~Server()
    {
        Destory();
    }
};

class Client : public MsgQueue
{
public:
    Client()
    {
        MsgQueue::Create(GET_MSGQUEUE);
        std::cout << "client get msgqueue done" << std::endl;
    }
    ~Client()
    {
    }
};

#endif