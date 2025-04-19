#pragma once

#include <iostream>
#include <vector>
#include <functional>

using func_t = std::function<void()>;


class Tool
{
public:
    void pushFunc(func_t f)
    {
        _funcs.push_back(f);
    }

    void Execute()
    {
        for(auto& f : _funcs)
        {
            f();
        }
    }

private:
    std::vector<func_t> _funcs;
};


