#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <map>

std::string opers = "+-*/%";

enum
{
    DivZero = 1,
    ModZero,
    Unknown
};

class Task
{
public:
    Task()
    {}
    Task(int x, int y, char op)
        : data1_(x), data2_(y), oper_(op)
    {
    }

    void Run()
    {
        std::map<char, std::function<void()>> CmdOp{
            {'+', [this](){ result_ = data1_ + data2_; }},
            {'-', [this](){ result_ = data1_ - data2_; }},
            {'*', [this](){ result_ = data1_ * data2_; }},
            {'/', [this](){ if (data2_ == 0) exitcode_ = DivZero; else result_ = data1_ / data2_; }},
            {'%', [this](){ if (data2_ == 0) exitcode_ = ModZero; else result_ = data1_ % data2_; }}
        };

        // auto it = CmdOp.find(oper_);
        std::map<char, std::function<void()>>::iterator it = CmdOp.find(oper_);
        if (it != CmdOp.end())
            it->second(); // 调用lambda函数
        else
            exitcode_ = Unknown; // 如果没有找到操作，设置错误代码
    }
    void operator()()
    {
        Run();
    }
    std::string GetResult() // 这里可以使用stringstream
    {
        std::stringstream s;
        s << data1_ << oper_ << data2_ << "=" << result_ << " [code: " << exitcode_ << "]";

        std::string r;
        r = s.str();
        return r;
    }
    std::string GetTask()
    {
        std::stringstream s;
        s << data1_ << oper_ << data2_ << "=?";

        std::string r;
        r = s.str();
        return r;
    }
    ~Task()
    {
    }

private:
    int data1_; // 操作数
    int data2_; // 操作数
    char oper_; // 操作符

    int result_;   // 结果
    int exitcode_; // 错误码
};