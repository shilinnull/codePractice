#include "myshell.h"


int main()
{
    char commandstr[SIZE];

    while(true)
    {
        // 0. 初始化操作
        InitGlobal(); 
        
        // 1. 输出命令行提示符
        PrintCommand();
        
        // 2. 获取用户输入的命令
        if(!GetCommandStr(commandstr,SIZE))
            continue;
        // 2.1 重定向检测
        CheckRedir(commandstr);
        
        // 对命令字符串，进行解析 -> 命令行参数表
        ParseCommandStr(commandstr); 
        // 4. 检测命令，内键命令，要让shell自己执行！
        if(BuiltInCommandExec())
            continue;

        // 5.执行命令, 让子进程来进行执行
        ForkAndExec();
    }

    return 0;
}
