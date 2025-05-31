// 自定义异常类
class ContactException
{
private:
    std::string message;

public:
    ContactException(std::string str = "A problem") : message{str} {}
    std::string what() const { return message; }
};