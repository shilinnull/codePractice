#pragma once
#include <iostream>
#include <string>

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
    Task(int x, int y, char op)
        : data1_(x), data2_(y), oper_(op)
    {
    }

    void Run()
    {
        switch (oper_)
        {
        case '+':
            result_ = data1_ + data2_;
            break;
        case '-':
            result_ = data1_ - data2_;
            break;
        case '*':
            result_ = data1_ * data2_;
            break;
        case '/':
        {
            if (data2_ == 0)
                exitcode_ = DivZero;
            else
                result_ = data1_ / data2_;
        }
        break;
        case '%':
        {
            if (data2_ == 0)
                exitcode_ = ModZero;
            else
                result_ = data1_ % data2_;
        }
        break;
        default:
            exitcode_ = Unknown;
            break;
        }
    }
    void operator()()
    {
        Run();
    }
    std::string GetResult() // 这里可以使用stringstream
    {
        std::string r = std::to_string(data1_);
        r += oper_;
        r += std::to_string(data2_);
        r += "=";
        r += std::to_string(result_);
        r += "[code: ";
        r += std::to_string(exitcode_);
        r += "]";

        return r;
    }
    std::string GetTask()
    {
        std::string r = std::to_string(data1_);
        r += oper_;
        r += std::to_string(data2_);
        r += "=?";
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
