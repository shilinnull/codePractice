#pragma once

#include "Protocol.hpp"

class Calculator
{
public:
    Calculator(){}
    /**
     * code: 0 计算正确
     * code: 1 除零错误
     * code: 2 取模错误
     * code: 3 未支持
     */
    Response Exec(Request &req)
    {
        Response resp;
        switch (req.GetOper())
        {
        case '+':
            resp.SetResult(req.GetX() + req.GetY());
            break;
        case '-':
            resp.SetResult(req.GetX() - req.GetY());
            break;
        case '*':
            resp.SetResult(req.GetX() * req.GetY());
            break;
        case '/':
        {
            if (req.GetY() == 0)
            {
                resp.SetCode(1);
            }
            else
            {
                resp.SetResult(req.GetX() / req.GetY());
            }
        }
        break;
        case '%':
        {
            if (req.GetY() == 0)
            {
                resp.SetCode(2);
            }
            else
            {
                resp.SetResult(req.GetX() % req.GetY());
            }
        }
        break;
        case '^':
            resp.SetResult(req.GetX() ^ req.GetY());
            break;
        case '|':
            resp.SetResult(req.GetX() | req.GetY());
            break;
        case '&':
            resp.SetResult(req.GetX() & req.GetY());
            break;
        default:
            resp.SetCode(3);
            break;
        }
        return resp;
    }
    ~Calculator() {}
};