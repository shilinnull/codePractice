#include <iostream>
#include <memory>


const int defaultnum = 1;


// 只关心PV操作
class Semaphore
{
public:
    Semaphore()
    {}
    ~Semaphore()
    {}
private:
};

// 使用简单的建造者模式
class SemaphoreBuilder
{
public:
    SemaphoreBuilder()
    {
    }
    ~SemaphoreBuilder()
    {
    }

    std::shared_ptr<Semaphore> Build(int flag, int num = defaultnum)
    {
        
    }


private:
};