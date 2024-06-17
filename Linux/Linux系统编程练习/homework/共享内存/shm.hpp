#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

using namespace std;

const int gUser = 1;
const int gCreater = 2;

class Shm
{
public:
    Shm(const string &pathname, int procj_id, int who)
        : _pathname(pathname), _proj_id(procj_id), _who(who)
    {
        // 获取key
        _key = GetCommKey();
        // 通过不同身份创建共享内存，先创建
        if (_who == gUser)
            GetShmUseUser();
        else
            GetShmUseCreater();

        _addrshm = AddrShm(); // 挂接
    }

    // 将共享内存全部清空
    void Zero()
    {
        if (_addrshm)
        {
            memset(_addrshm, 0, 4096);
        }
    }

    void *AddrShm()
    {
        if (_addrshm != nullptr)
            DetachShm(_addrshm);
        void *shaddr = shmat(_shmid, nullptr, 0);
        return shaddr;
    }

    void DetachShm(void *_addrshm)
    {
        if (_addrshm == nullptr)
            return;
        shmdt(_addrshm);
    }

    void *Addr()
    {
        return _addrshm;
    }

private:
    void GetShmUseUser()
    {
        _shmid = GetShmHelper(_key, 4096, IPC_CREAT | 0666);
    }
    void GetShmUseCreater()
    {
        _shmid = GetShmHelper(_key, 4096, IPC_CREAT | IPC_EXCL | 0666);
    }

    int GetShmHelper(int key, int size, int flag)
    {
        int shmg = shmget(_key, size, flag);
        return shmg;
    }


    key_t GetCommKey()
    {
        // 生成key
        key_t k = ftok(_pathname.c_str(), _proj_id);
        return k;
    }
public:
    ~Shm()
    {
        if (_who == gCreater)
            shmctl(_shmid, IPC_RMID, nullptr);
    }

private:
    key_t _key;
    const string _pathname;
    int _proj_id;
    int _who;

    void *_addrshm;

    int _shmid;
};