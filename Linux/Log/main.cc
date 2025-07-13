#include "Logger.hpp"

int main() 
{
    // EnableConsoleLog();
    EnableFileLog();

    LOG(LogLevel::ERROR) << "hello world" << ", 3.14 " << 123;
    LOG(LogLevel::WARNING) << "hello world" << ", 3.14 " << 123;
    LOG(LogLevel::ERROR) << "hello world" << ", 3.14 " << 123;
    LOG(LogLevel::ERROR) << "hello world" << ", 3.14 " << 123;

    return 0;
}
