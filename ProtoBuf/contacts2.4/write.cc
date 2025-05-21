#include <iostream>
#include <fstream>

#include "contacts.pb.h"

void AddPeopleInfo(namespace_Contacts::PeopleInfo *people_info_ptr)
{
    std::cout << "-------------新增联系⼈-------------" << std::endl;

    std::cout << "请输入联系人姓名: ";
    std::string name;
    getline(std::cin, name);
    people_info_ptr->set_name(name);

    std::cout << "请输入联系人年龄: ";
    int age;
    std::cin >> age;
    people_info_ptr->set_age(age);
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
        namespace_Contacts::PeopleInfo_Phone *phone = people_info_ptr->add_phone();
        phone->set_number(num);

        // 电话
        std::cout << "选择电话类型（1. 移动电话   2. 固定电话）：";
        int type;
        std::cin >> type;
        std::cin.ignore(256, '\n');
        switch(type)
        {
            case 1: phone->set_type(namespace_Contacts::PeopleInfo_Phone_PhoneType::PeopleInfo_Phone_PhoneType_MP);
                break;
            case 2: phone->set_type(namespace_Contacts::PeopleInfo_Phone_PhoneType::PeopleInfo_Phone_PhoneType_TEL);
                break;
            default:
                std::cout << "非法选择，使用默认值！" << std::endl;
                break;
        }
    }

    // 住址
    namespace_Contacts::Address address;
    std::cout << "请输入家庭地址；";
    std::string home_address;
    std::getline(std::cin, home_address);
    address.set_home_address(home_address);

    std::cout << "请输入单位地址：";
    std::string unit_address;
    std::getline(std::cin, unit_address);
    address.set_unit_address(unit_address);

    google::protobuf::Any* data = people_info_ptr->mutable_address();
    data->PackFrom(address); //将任意消息类型转为 Any 类型

    // 添加联系方式
    std::cout << "选择添加⼀个其他联系方式（1. qq号 2. 微信号）: " ;
    int other_contact;
    std::cin >> other_contact;
    std::cin.ignore(256, '\n');
    switch(other_contact)
    {
        case 1: {
            std::cout << "请输入qq号：";
            std::string qq;
            std::getline(std::cin, qq);
            people_info_ptr->set_qq(qq);
            break;
        }
        case 2: {
            std::cout << "请输入微信号：";
            std::string weixin;
            std::getline(std::cin, weixin);
            people_info_ptr->set_wechat(weixin);
            break;
        }
        default: {
            std::cout << "非法选择，该项设置失败！" << std::endl;
            break;
        }
    }

    // 设置备注
    for (int i = 0; ; i++)
    {
        std::cout << "请输入备注" << i << "标题 (只输入回车完成备注新增): ";
        std::string remark_key;
        std::getline(std::cin, remark_key);
        if(remark_key.empty())
            break;

        std::cout << "请输入备注的" << i << "内容: ";
        std::string remark_val;
        std::getline(std::cin, remark_val);
        people_info_ptr->mutable_remark()->insert({remark_key, remark_val});
    }

    std::cout << "-----------添加联系人成功-----------" << std::endl;
}

int main()
{
    // 验证没有意外链接到与编译的头文件不兼容的库版本
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    namespace_Contacts::Contacts contacts;

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
    std::fstream output("contacts.bin", std::ios::out | std::ios::trunc | std::ios::binary);
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
