#include "Task.hpp"

class Channel
{
public:
    Channel(int wfd, pid_t id, const std::string &name)
        : _wfd(wfd), _subprocessid(id), _name(name) {}

    int GetWfd() { return _wfd; }
    pid_t GetProcessId() { return _subprocessid; }
    std::string GetName() { return _name; }

    // 等待子进程
    void Wait()
    {
        pid_t rid = waitpid(_subprocessid, nullptr, 0);
        if (rid > 0)
        {
            std::cout << "wait " << rid << " success" << std::endl;
        }
    }

    // 关闭
    void CloseChannel()
    {
        close(_wfd);
    }

    ~Channel() {}

private:
    int _wfd;
    pid_t _subprocessid;
    std::string _name;
};

void CreateChannelAndSub(int num, std::vector<Channel> *channels, task_t task)
{
    for (int i = 0; i < num; i++)
    {
        // 1. 创建管道
        int pipefd[2] = {0};
        int n = pipe(pipefd);
        if (n < 0)
            exit(-1);

        // 2. 创建子进程
        pid_t id = fork();
        if (id == 0)
        {
            // 关闭多余的写端
            if (!channels->empty())
            {
                for (auto &channel : *channels)
                {
                    // 关闭
                    channel.CloseChannel();
                }
            }

            // child --- read
            close(pipefd[1]);
            dup2(pipefd[0], 0); // 将管道的读端，重定向到标准输入
            task();
            close(pipefd[0]);
            exit(0);
        }
        // parent
        // 3.构建一个channel名称
        std::string channel_name = "Channel-" + std::to_string(i);
        // a. 子进程的pid b. 父进程关心的管道的w端
        channels->push_back(Channel(pipefd[1], id, channel_name));
        close(pipefd[0]); // 父进程关心的管道的w端
    }
}

int NextChannel(int channels)
{
    static int next = 0;
    int channel = next;
    next++;
    next %= channels;
    return channel;
}

void SendTaskCommand(Channel &channel, int taskcommand)
{
    write(channel.GetWfd(), &taskcommand, sizeof(taskcommand));
}

void ctrlProcessOnce(std::vector<Channel> &channels)
{
    sleep(1);
    // a. 选择一个任务
    int taskCommand = SelectTask();
    // b. 选择一个信道和进程
    int channel_index = NextChannel(channels.size());
    // c. 发送任务
    SendTaskCommand(channels[channel_index], taskCommand);

    std::cout << std::endl;
    std::cout << "taskcommand: " << taskCommand << " channel: "
              << channels[channel_index].GetName() << " sub process: " << channels[channel_index].GetProcessId() << std::endl;
}

void ctrlProcess(std::vector<Channel> &channels, int times = -1)
{
    if (times > 0)
    {
        while (times--)
        {
            ctrlProcessOnce(channels);
        }
    }
    else
    {
        while (true)
        {
            ctrlProcessOnce(channels);
        }
    }
}

void CleanUpChannel(std::vector<Channel> &channels)
{
    // 方法一：
    // for (auto &ch : channels)
    // {
    //     ch.CloseChannel();
    // }
    // for (auto &ch : channels)
    // {
    //     ch.Wait();
    // }

    // 方法二：
    // int last = channels.size() - 1;
    // for (int i = last; i >= 0; i--)
    // {
    //     close(channels[i].GetWfd());
    //     waitpid(channels[i].GetProcessId(), nullptr, 0);
    // }

    // 方法三：需要在CreateChannelAndSub()关闭多余的写端
    for (auto &ch : channels)
    {
        ch.CloseChannel();
        ch.Wait();
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " processnum" << std::endl;
        return 1;
    }

    int num = std::stoi(argv[1]);
    LoadTask();

    std::vector<Channel> channels;
    // 1. 创建信道和子进程
    CreateChannelAndSub(num, &channels, work);

    // 2. 通过channel控制子进程
    ctrlProcess(channels, num);

    // 3. 回收管道和子进程. a. 关闭所有的写端 b. 回收子进程
    CleanUpChannel(channels);

    // sleep(100);
    return 0;
}