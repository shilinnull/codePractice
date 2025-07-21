#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <vector>
#include <string>

class Command
{
private:
    bool IsSafe(const std::string &cmd)
    {
        for (auto &s : _command_white_list)
        {
            if (cmd == s)
            {
                return true;
            }
        }
        return false;
    }

public:
    Command()
    {
        _command_white_list.push_back("ls -a -l");
        _command_white_list.push_back("tree");
        _command_white_list.push_back("whoami");
        _command_white_list.push_back("who");
        _command_white_list.push_back("pwd");
    }

    std::string Exec(const std::string &cmd)
    {
        if (!IsSafe(cmd))
        {
            return "cannot execute this command!";
        }
        std::string result;
        FILE *fp = popen(cmd.c_str(), "r");
        if (!fp)
        {
            result = cmd + "exec error";
        }
        else
        {
            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), fp))
            {
                result += buffer;
            }
            pclose(fp);
        }
        return result;
    }

private:
    std::vector<std::string> _command_white_list;
};

#endif