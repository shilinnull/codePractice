#ifndef __SHM_HPP__
#define __SHM_HPP__

#include <iostream>
#include <string>
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#include "Log.hpp"
const int gCreater = 1;
const int gUser = 2;

const std::string gpathname = "/root/111/code-exercise/Linux/lesson07";
const int gproj_id = 0x666;
const int gshmSize = 4096;

Log log;

class Shm
{
public:
    Shm(const std::string &pathname, int proj_id, int who)
        : _pathname(pathname), _proj_id(proj_id), _who(who), _addrshm(nullptr)
    {
        _key = GetCommKey(); // 获取key

        // 通过不同身份创建共享内存，先创建
        if (_who == gCreater)
            GetShmUseCreate();
        else if (_who == gUser)
            GetShmForUse();

        std::cout << "shmid: " << _shmid << std::endl;
        std::cout << "key: " << ToHex(_key) << std::endl;

        _addrshm = AttachShm(); // 后挂接
    }

    // 创建
    bool GetShmUseCreate()
    {
        if (_who == gCreater)
        {
            _shmid = GetShmHelper(_key, gshmSize, IPC_CREAT | IPC_EXCL | 0666);
            if (_shmid < 0)
                return false;
            log(Info, "GetShmUseCreate share memory success, shmid: %d", _shmid);
        }

        return true;
    }
    // 使用
    bool GetShmForUse()
    {
        if (_who == gUser)
        {
            _shmid = GetShmHelper(_key, gshmSize, IPC_CREAT | 0666);
            if (_shmid < 0)
                return false;

            log(Info, "GetShmForUse share memory success, shmid: %d", _shmid);
        }
        return true;
    }

    std::string ToHex(key_t key)
    {
        char buffer[128];
        snprintf(buffer, sizeof(buffer), "%#x", key);
        return buffer;
    }

    ~Shm()
    {
        if (_who == gCreater)
        {
            int res = shmctl(_shmid, IPC_RMID, nullptr);
            if (res < 0)
            {
                log(Fatal, "shmctl fail! : %s", strerror(errno));
                exit(3);
            }
        }
        log(Info, "shm remove done ...");
    }

    void *Addr()
    {
        return _addrshm;
    }

    // 将共享内存全部清空
    void Zero()
    {
        if (_addrshm)
        {
            memset(_addrshm, 0, gshmSize);
        }
    }

    void DebugShm()
    {
        // 获取共享内存的属性
        struct shmid_ds ds;
        int n = shmctl(_shmid, IPC_STAT, &ds);
        if (n < 0)
            return;

        std::cout << "ds.shm_perm.__key : " << ToHex(ds.shm_perm.__key) << std::endl;
        std::cout << "ds.shm_nattch: " << ds.shm_nattch << std::endl;
    }

private:
    // 创建key
    key_t GetCommKey()
    {
        key_t k = ftok(_pathname.c_str(), _proj_id);
        if (k < 0)
        {
            log(Fatal, "ftok, error: %s", strerror(errno));
            exit(1);
        }
        log(Info, "ftok success, key is %#x", k);
        return k;
    }

        int GetShmHelper(key_t key, int size, int flag)
    {
        int shmid = shmget(key, size, flag); // 获取key
        if (shmid < 0)
        {
            log(Fatal, "create share memory error: %s", strerror(errno));
            exit(2);
        }

        log(Info, "create share memory success, shmid: %d", shmid);
        std::cout << "create share memory success, key: " << ToHex(_key) << std::endl;
        return shmid;
    }

    std::string RoleToString(int who)
    {
        if (who == gCreater)
            return "Creater";
        else if (who == gUser)
            return "gUser";
        else
            return "None";
    }

    void DetachShm(void *shmaddr)
    {
        if (shmaddr == nullptr)
            return;
        shmdt(shmaddr); // 从进程的地址空间中分离一个共享内存段
        log(Info, "who: %s detach shm...", RoleToString(_who).c_str());
    }

    void *AttachShm()
    {
        if (_addrshm != nullptr)
            DetachShm(_addrshm);

        void *shaddr = shmat(_shmid, nullptr, 0); // 将共享内存挂接到程序地址空间当中
        if (shaddr == nullptr)
        {
            log(Fatal, "shmat fail!");
        }
        //std::cout << "who: " << RoleToString(_who) << " attach shm..." << std::endl;
        log(Info, "who: %s attach shm...", RoleToString(_who).c_str());

        return shaddr;
    }

private:
    key_t _key;
    int _shmid;

    std::string _pathname;
    int _proj_id;

    int _who;
    void *_addrshm;
};

#endif