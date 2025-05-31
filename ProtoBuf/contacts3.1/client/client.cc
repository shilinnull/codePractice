#include <iostream>
#include <fstream>

#include "contacts.pb.h"
#include "google/protobuf/unknown_field_set.h"

// 打印通讯录
void PrintfContacts(const c_contacts::Contacts &contacts)
{
    // 遍历通讯录
    for (int i = 0; i < contacts.contacts_size(); ++i)
    {
        std::cout << "------------联系人" << i + 1 << "------------" << std::endl;
        // 获取到contacts内的people
        const c_contacts::PeopleInfo &people = contacts.contacts(i);
        std::cout << "姓名：" << people.name() << std::endl;
        std::cout << "年龄：" << people.age() << std::endl;

        // 获取到contacts内的phone
        for (int j = 0; j < people.phone_size(); ++j)
        {
            const c_contacts::PeopleInfo_Phone &phone = people.phone(j);
            std::cout << "电话" << j + 1 << "：" << phone.number() << std::endl;
        }

        // 打印未知字段
        /*
        enum Type {
            TYPE_VARINT,
            TYPE_FIXED32,
            TYPE_FIXED64,
            TYPE_LENGTH_DELIMITED,
            TYPE_GROUP
        };
        类型为 0，即为 TYPE_VARINT。
        */
        const google::protobuf::Reflection *reflection = c_contacts::PeopleInfo::GetReflection();
        const google::protobuf::UnknownFieldSet &unknowSet = reflection->GetUnknownFields(people);
        for (int j = 0; j < unknowSet.field_count(); j++)
        {
            const google::protobuf::UnknownField &unknow_field = unknowSet.field(j);
            std::cout << "未知字段" << j + 1 << ":"
                      << " 字段编号: " << unknow_field.number()
                      << " 类型: " << unknow_field.type();
            switch (unknow_field.type())
            {
                case google::protobuf::UnknownField::Type::TYPE_VARINT:
                    std::cout << " 值: " << unknow_field.varint() << std::endl;
                    break;
                case google::protobuf::UnknownField::Type::TYPE_LENGTH_DELIMITED:
                    std::cout << " 值: " << unknow_field.length_delimited() << std::endl;
                    break;
            }
        }
    }
}

int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // 以二进制方式读取 contacts
    c_contacts::Contacts contacts;
    std::fstream input("../contacts.bin", std::ios::in | std::ios::binary);
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