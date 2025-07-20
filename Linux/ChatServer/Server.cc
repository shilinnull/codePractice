#include "Route.hpp"
#include "ChatServer.hpp"
#include "ThreadPool.hpp"
#include <memory>


void Usage(std::string proc)
{
    std::cerr << "Usage: " << proc << " <Port>" << std::endl;
}

using task_t = std::function<void()>;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(1);
    }

    uint16_t port = atoi(argv[1]);

    // 1. 消息转发
    std::unique_ptr<Route> route = std::make_unique<Route>();
    
    // 2. 线程池
    auto tp = ThreadPool<task_t>::getInstance();

    //3. 服务器对象
    std::unique_ptr<ChatServer> server = std::make_unique<ChatServer>(port, 
    [&route, &tp](int sockfd, std::string message, InetAddr addr){
        task_t task = std::bind(&Route::RouteMessageToAll, route.get(), sockfd, message, addr); // bind任务 
        tp->Push(task); // 将任务添加到线程池
        LOG(LogLevel::DEBUG) << "task added to thread pool, message: " << message << ", sender: " << addr.ToString();
    });

    server->Init();
    server->Start();

    return 0;
}