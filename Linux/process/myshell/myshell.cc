#include "myshell.h"

// 保存shell的当前路径
char pwd[SIZE];

// 命令行参数
#define ARGS 64
char *gargv[ARGS] = {NULL};
int argc = 0;


int lastcode = 0;

void InitGlobal()
{
    argc = 0;
    memset(gargv, 0, sizeof(gargv));
}

static std::string GetUserName()
{
    std::string username = getenv("USER");
    return username.empty() ? "None" : username;
}

static std::string GetHostName()
{
    std::string hostname= getenv("HOSTNAME");
    return hostname.empty() ? "None" : hostname;
}
static std::string GetHomePath()
{
    std::string homepath= getenv("HOME");
    return homepath.empty() ? "/" : homepath;
}

static std::string GetPwd()
{
    char temp[1024];
    getcwd(temp,sizeof(temp));
    // 更新一下shell自己的环境变量
    snprintf(pwd, sizeof(pwd), "PWD=%s", temp);
    putenv(pwd);
    
    // 拆分
    std::string pwd_lable = temp;
    const std::string pathsep = "/";
    auto pos = pwd_lable.rfind(pathsep);
    if(pos == std::string::npos)
    {
        return "None";
    }

    // 去掉/
    pwd_lable = pwd_lable.substr(pos + 1);
    return pwd_lable.empty() ? "/" : pwd_lable;
}

void PrintCommand()
{
    std::string user = GetUserName();
    std::string hostname = GetHostName();
    std::string pwd = GetPwd();
    printf("[%s@%s %s]&", user.c_str(), hostname.c_str(),pwd.c_str());
}

bool GetCommandStr(char *cmd, int len)
{
    if(cmd == NULL || len <= 0)
        return false;

    char *res = fgets(cmd, len, stdin);
    if(res == NULL)
        return false;
    // 最后的位置-1放\0, 否则会有\n
    cmd[strlen(res) - 1] = 0;
    
    return strlen(cmd) == 0 ? false : true;
}

void ParseCommandStr(char *cmd)
{
    if(cmd == NULL)
        return;
    gargv[argc++] = strtok(cmd, " ");
    while((bool)(gargv[argc++] = strtok(NULL, " ")));
    
    // 回退一次
    argc--;

//#define DEBUG
#ifdef DEBUG
        printf("argc: %d\n", argc);
        printf("----------------------\n");
        for(int i = 0; i < argc; i++)
        {
            printf("gargv[%d]: %s\n",i, gargv[i]);
        }
        printf("----------------------\n");
        for(int i = 0; gargv[i]; i++)
        {
            printf("gargv[%d]: %s\n",i, gargv[i]);
        }
#endif

}

bool BuiltInCommandExec()
{
    std::string cmd = gargv[0];
    bool ret = false;
    if(cmd == "cd")
    {
        if(argc == 2)
        {
            std::string target = gargv[1];
            if(target == "~")
            {
                ret = true;
                chdir(GetHomePath().c_str());
            }
            else
            {
                ret = true;
                chdir(gargv[1]);
            }
        }
        else if(argc == 1)
        {
            ret = true;
            chdir(GetHomePath().c_str());
        }
    }
    else if(cmd == "echo") 
    {
        if(argc == 2)
        {
            std::string args = gargv[1];
            if(args[0] == '$')
            {
                if(args[1] == '?')
                {
                    printf("lastcode: %d\n",lastcode);
                    lastcode = 0;
                    ret = true;
                }
                else 
                {
                    const char *name = &args[1];
                    printf("%s\n",getenv(name));
                    lastcode = 0;
                    ret = true;
                }
            }   
            else 
            {
                printf("%s\n",args.c_str());
                ret = true;
            }
        }
    }

    return ret;
}

void ForkAndExec()
{
    pid_t id = fork();
    if(id < 0)
    {
        perror("fork fail!");
        return;
    }
    else if(id == 0)
    {
        execvp(gargv[0], gargv);
        exit(0);
    }
    else
    {
        int status;
        pid_t rid = waitpid(id, &status, 0);
        if(rid > 0)
        {
            lastcode = WEXITSTATUS(status);
        }
    }
}








