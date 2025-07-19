#include "DictServer.hpp"
#include "Dictionary.hpp"

#include <memory>

void Usage(std::string proc)
{
    std::cerr << "Usage: " << proc << " <Port>" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(1);
    }

    uint16_t port = atoi(argv[1]);

    // 1. 创建字典对象
    Dictionary dict("dict.txt");

    std::unique_ptr<DictServer> server = std::make_unique<DictServer>
    (port, [&dict](const std::string &word, const std::string &whoip, uint16_t whoport) -> std::string
    {
        // 2. 调用字典对象的查询方法
        return dict.Translate(word, whoip, whoport);
    });

    server->Init();
    server->Start();

    return 0;
}