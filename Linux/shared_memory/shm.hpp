#ifndef __SHM_HPP__
#define __SHM_HPP__

#include <iostream>
#include <cstdio>

#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define Creater 0
#define User 1

#define gdefaultsize 4096 // 共享内存的大小

#define gpathname "."
#define gproj_id 0x77

class SharedMemory
{
private:
    bool CreateHelper(int flags)
    {
        _key = ftok(gpathname, gproj_id);
        if (_key < 0)
        {
            perror("ftok");
            return false;
        }

        printf("形成键值对%x\n", _key);

        // 创建全新的shm
        _shmid = shmget(_key, _size, flags);
        if (_shmid < 0)
        {
            perror("shmget");
            return false;
        }
        printf("shmid：%d\n", _shmid);
        return true;
    }

    void CreateAndGet()
    {
        // 服务端创建共享内存
        if (_who == Creater)
        {
            // 创建，设置权限
            if (!CreateHelper(IPC_CREAT | IPC_EXCL | 0666))
            {
                perror("创建失败");
                exit(2);
            }
        }

        // 用户端需要获取已经存在的共享内存
        if (_who == User)
        {
            // 获取
            if (!CreateHelper(IPC_CREAT))
            {
                perror("CreateHelper");
                exit(2);
            }
        }
    }

    void Attach()
    {
        // 挂接到自己的内存空间
        _start_addr = shmat(_shmid, nullptr, 0);
        if ((long long)_start_addr == -1)
        {
            perror("shmat");
            exit(3);
        }
        std::cout << "将指定的共享内存挂接到自己进程的地址空间" << std::endl;
        printf("_start_addr : %p\n", _start_addr);

        // 前四个字节保存共享内存的数据个数
        _num = (int *)_start_addr;

        // 设置数据范围
        _datastart = (char *)_start_addr + sizeof(int);
    }

    void Detach()
    {
        int n = shmdt(_start_addr);
        if (n < 0)
        {
            perror("shmdt");
            exit(1);
        }
        std::cout << "\n将指定的共享内存从进程的地址空间移除" << std::endl;
    }

    void Remove()
    {
        // 移除共享内存
        if (_who == Creater)
        {
            int n = shmctl(_shmid, IPC_RMID, nullptr);
            if (n < 0)
            {
                perror("shmctl");
                exit(1);
            }
            std::cout << "删除shm成功" << std::endl;
        }
    }

public:
    SharedMemory(int who = User, int size = gdefaultsize)
        : _who(who), _key(0), _size(size - sizeof(int)), _shmid(-1),
          _num(nullptr), _datastart(nullptr), _windex(0), _rindex(0)
    {
        // 创建、获取共享内存
        CreateAndGet();

        // 挂接
        Attach();
    }

    void PushChar(char ch)
    {
        if (*_num == _size - 1) // 预留一个位置用于处理边界情况
            return;

        ((char *)_datastart)[_windex++] = ch;
        ((char *)_datastart)[_windex] = '\0';

// #define DEBUG
#ifdef DEBUG
        printf("%s\n", _datastart);
#endif
        _windex = (_windex) % _size;
        (*_num)++;
    }

    void PopChar(char *ch)
    {
        if (*_num == 0)
            return;
        *ch = ((char *)_datastart)[_rindex++];
#ifdef DEBUG
        printf("%c", *ch);
        fflush(stdout);
#endif
        _rindex = (_rindex) % _size;
        (*_num)--;
    }

    ~SharedMemory()
    {
        // 分离
        Detach();

        // 移除
        Remove();
    }

private:
    // 管理共享内存
    int _who;
    key_t _key;
    int _size; // 共享内存的大小
    int _shmid;
    void *_start_addr; // 共享内存地址的开始

    // 管理数据
    int *_num;        // 共享内存数据的大小
    char *_datastart; // 实际数据范围
    int _windex;      // 写
    int _rindex;      // 读
};

#endif