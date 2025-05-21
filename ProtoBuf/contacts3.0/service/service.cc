#include <iostream>
#include <fstream>

#include "contacts.pb.h"

void AddPeopleInfo(s_contacts::PeopleInfo *people_info_ptr)
{
    std::cout << "-------------新增联系人-------------" << std::endl;

    std::cout << "请输入联系人姓名: ";
    std::string name;
    getline(std::cin, name);
    people_info_ptr->set_name(name);

    // std::cout << "请输入联系人年龄: ";
    // int age;
    // std::cin >> age;
    // people_info_ptr->set_age(age);
    // std::cin.ignore(256, '\n');

    std::cout << "请输入联系人生日: ";
    int birthday;
    std::cin >> birthday;
    people_info_ptr->set_birthday(birthday);
    std::cin.ignore(256, '\n');

    // 输入多个电话以及类型
    int index = 1;
    while (true)
    {
        std::cout << "请输入联系人电话" << index++ << "(只输入回车完成电话新增): ";
        std::string num;
        std::getline(std::cin, num);
        if (num.empty()) {
            break;
        }

        // 获取到PeopleInfo内的phone
        s_contacts::PeopleInfo_Phone *phone = people_info_ptr->add_phone();
        phone->set_number(num);
    }
    std::cout << "-----------添加联系人成功-----------" << std::endl;
}

int main()
{
    // 验证没有意外链接到与编译的头文件不兼容的库版本
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    s_contacts::Contacts contacts;

    // 读取已经存在的 contacts
    std::fstream input("contacts.bin", std::ios::in | std::ios::binary);
    if (!input)
    {
        std::cerr << "File not found, Creating a new file!" << std::endl;
    }
    else if (!contacts.ParseFromIstream(&input)) // 解析，反序列
    {
        std::cerr << "Failed to parse contacts." << std::endl;
        input.close();
        return -1;
    }

    // 添加联系人
    AddPeopleInfo(contacts.add_contacts());

    // 向磁盘写入
    std::fstream output("../contacts.bin", std::ios::out | std::ios::trunc | std::ios::binary);
    if (!contacts.SerializeToOstream(&output)) // 序列化
    {
        std::cerr << "Failed to write contacts." << std::endl;
        input.close();
        output.close();
        return -1;
    }

    input.close();
    output.close();

    // 删除 Protocol Buffer 库分配的所有全局对象
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
