#include <iostream>
#include <memory>

#include "Http.hpp"
#include "TcpServer.hpp"
#include "daemon.hpp"

using namespace std;


HttpResponse Login(HttpRequest& req)
{
    HttpResponse resp;
    LOG(LogLevel::DEBUG)<< "-----Login: " << req.Body();
    resp.SetCode(200);
    // resp.SetCookie("Set-Cookie", req.Body());
    resp.SetCookie("Set-Cookie", "k1=1");
    resp.SetCookie("Set-Cookie", "k2=2");
    resp.SetCookie("Set-Cookie", "k3=3");
    resp.SetCookie("Set-Cookie", "k4=4");

    resp.SetHeader("Location", "/");
    return resp;
}
HttpResponse Register(HttpRequest& req)
{
    LOG(LogLevel::DEBUG)<< "-----Register" << req.Body();
    return HttpResponse();
}

HttpResponse Search(HttpRequest& req)
{
    LOG(LogLevel::DEBUG)<< "-----Search"<< req.Body();
    return HttpResponse();
}


void Usage(std::string proc)
{
    std::cerr << "Usage : " << proc << " <prot>" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(0);
    }

    // EnableFileLog();

    std::unique_ptr<Http> http = std::make_unique<Http>();
    // 注册服务
    http->Register("/login", Login);
    http->Register("/Register", Register);
    http->Register("/Search", Search);


    uint16_t serverport = std::stoi(argv[1]);
    std::unique_ptr<TcpServer> tsock = std::make_unique<TcpServer>(serverport, [&http](std::string& reqstr)->std::string{
        return http->HandlerRequest(reqstr);
    });

    tsock->Run();
    
    return 0;
}