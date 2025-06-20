#include <iostream>
#include <vector>
#include "Thread.hpp"

using namespace std;

int gnum = 5;
void test()
{
    int cnt = 5;
    while (cnt--)
    {
        cout << "新的线程已经在运行了！！" << endl;
        sleep(1);
    }
}

int main()
{
    vector<Thread> threads;
    for(int i = 0;i < gnum; i++)
    {
        std::string name = "thread-";
        name += std::to_string(i + 1);
        Thread t(test, name);
        threads.push_back(t);
    }
    
    // 启动
    for(auto& e : threads)
    {
        e.Start();
    }
    for(auto&e : threads)
    {
        e.Join();
    }
    return 0;
}