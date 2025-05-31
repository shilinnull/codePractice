#include <iostream>
#include <fstream>

#include "contacts.pb.h"

// 打印通讯录
void PrintfContacts(const namespace_Contacts::Contacts &contacts)
{
    // 遍历通讯录
    for (int i = 0; i < contacts.contacts_size(); ++i)
    {
        std::cout << "------------联系人" << i + 1 << "------------" << std::endl;
        // 获取到contacts内的people
        const namespace_Contacts::PeopleInfo &people = contacts.contacts(i);
        std::cout << "姓名：" << people.name() << std::endl;
        std::cout << "年龄：" << people.age() << std::endl;

        // 获取到contacts内的phone
        for (int j = 0; j < people.phone_size(); ++j)
        {
            const namespace_Contacts::PeopleInfo_Phone &phone = people.phone(j);
            std::cout << "电话" << j + 1 << ":" << phone.number();
            std::cout << "（" << phone.PhoneType_Name(phone.type()) << "）" << std::endl; // 打印出类型
        }
    }
}

int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // 以二进制方式读取 contacts
    namespace_Contacts::Contacts contacts;
    std::fstream input("contacts.bin", std::ios::in | std::ios::binary);
    if (!contacts.ParseFromIstream(&input))
    {
        std::cerr << "Failed to parse contacts." << std::endl;
        input.close();
        return -1;
    }

    PrintfContacts(contacts);

    input.close();
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}