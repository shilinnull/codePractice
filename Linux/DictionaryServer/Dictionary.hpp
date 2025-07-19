#ifndef DICTIONARY_SERVER_HPP
#define DICTIONARY_SERVER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include "Logger.hpp"

static const std::string sep = ": ";

class Dictionary
{
private:
    void LoadDictionary ()
    {
        std::ifstream in(_path);
        if(!in.is_open())
        {
            LOG(LogLevel::FATAL) << "Failed to open dictionary file: " << _path;
            exit(1);
        }
        // 读取字典文件内容（按行）
        std::string line;
        while(std::getline(in, line))
        {
            auto pos = line.find(sep);
            if (pos == std::string::npos)
            {
                LOG(LogLevel::WARNING) << "format error: " << line;
                continue;
            }
            
            std::string word = line.substr(0, pos);
            std::string meaning = line.substr(pos + sep.size());
            if(word.empty() || meaning.empty())
            {
                LOG(LogLevel::WARNING) << "format error, word or value is empty: " << line;
                continue;
            }
            _dict[word] = meaning; // 插入数据
        }

        in.close();
    }
public:
    Dictionary(const std::string& _path)
        :_path(_path)
    {
        LoadDictionary(); // 加载字典内容
    }

    std::string Translate(const std::string &word, const std::string &whoip, uint16_t whoport)
    {
        auto it = _dict.find(word);
        if (it != _dict.end())
        {
            LOG(LogLevel::INFO) << "Translate word: " << word << " from " << whoip << ":" << whoport;
            return it->first + "->" + it->second;
        }
        else
        {
            LOG(LogLevel::WARNING) << "Word not found: " << word << " from " << whoip << ":" << whoport;
            return "Word not found";
        }
    }

    ~Dictionary()
    {}
private:
    std::string _path; // 字典文件路径

    std::unordered_map<std::string, std::string> _dict; // 存储字典内容
};


#endif // DICTIONARY_SERVER_HPP