#include <iostream>
#include <unistd.h>
#include <mysql/mysql.h>

using namespace std;

// const std::string host = "127.0.0.0"; // 默认
const std::string host = "0.0.0.0"; // 这里是我自己修改的
const std::string user = "lsl";
const std::string passwd = "123456";
const std::string db = "conn";
const unsigned int port = 3306;

int main()
{
    // 初始化数据库
    MYSQL *my = mysql_init(nullptr);
    if (!my)
    {
        std::cerr << "init mysql error" << std::endl;
        return 1;
    }

    // 连接数据库
    if (!mysql_real_connect(my, host.c_str(), user.c_str(), passwd.c_str(), db.c_str(), port, nullptr, 0))
    {
        std::cerr << "connect MySQL error" << std::endl;
        return 2;
    }

    std::cout << "mysql success" << std::endl;

    // 设置字符集
    mysql_set_character_set(my, "utf8");

    // 插入数据
    std::string sql_insert = "insert into user (name, age, tel) values ('王五', 22, '222222');";
    int n = mysql_query(my, sql_insert.c_str());
    if (!n)
        std::cout << sql_insert << " success!" << std::endl;
    else
    {
        std::cerr << sql_insert << " failed: " << n << std::endl;
        return 3;
    }

    // 修改数据
    std::string sql_update = "update user set name='李四' where id=1;";
    int n = mysql_query(my, sql_update.c_str());
    if (!n)
        std::cout << sql_update << " success!" << std::endl;
    else
    {
        std::cerr << sql_update << " failed: " << n << std::endl;
        return 4;
    }

    // 查询数据
    std::string sql_select = "select * from user;";
    int n = mysql_query(my, sql_select.c_str());
    if (n != 0)
    {
        std::cerr << "mysql_query error: " << mysql_error(my) << std::endl;
        return 5;
    }

    MYSQL_RES *res = mysql_store_result(my);
    if (!res)
    {
        std::cerr << "mysql_store_result error: " << mysql_error(my) << std::endl;
        return 6;
    }

    // 获取行列
    int rows = mysql_num_rows(res);
    int fields = mysql_num_fields(res);
    std::cout << "行：" << rows << std::endl;
    std::cout << "列：" << fields << std::endl;

    // 获取属性
    MYSQL_FIELD *fields_array = mysql_fetch_field(res);
    for (int i = 0; i < fields; i++)
    {
        std::cout << fields_array[i].name << "\t";
    }
    std::cout << "\n";

    // 获取具体元素
    for (int i = 0; i < rows; i++)
    {
        MYSQL_ROW row = mysql_fetch_row(res);
        for (int j = 0; j < fields; j++)
        {
            std::cout << row[j] << "\t";
        }
        std::cout << "\n";
    }

    /* 手动插入数据
    std::string sql;
    while(true)
    {
        std::cout << "MySQL>>> ";
        if(!std::getline(std::cin, sql) || sql == "quit" || sql == "exit")
        {
            std::cout << "Bye Bye~" << std::endl;
            break;
        }
        // 插入数据
        int n = mysql_query(my, sql.c_str());
        if(!n)
            std::cout << sql << "success!" << std::endl;
        else
            std::cerr << sql << "failed: " << n << std::endl;
    }
    */
    mysql_free_result(res); // 不要忘记free
    mysql_close(my);
    return 0;
}

// 版本测试
// int main()
// {
//     printf("mysql client version: %s\n", mysql_get_client_info());
//     return 0;
// }