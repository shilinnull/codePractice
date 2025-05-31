#include <iostream>
#include "ContactsServer.h"
#include "ContactException.h"

void menu() {
    std::cout << "-----------------------------------------------------" << std::endl
              << "--------------- 请选择对通讯录的操作 ----------------" << std::endl
              << "------------------ 1、新增联系人 --------------------" << std::endl     
              << "------------------ 2、删除联系人 --------------------" << std::endl
              << "------------------ 3、查看联系人列表 ----------------" << std::endl 
              << "------------------ 4、查看联系人详细信息 ------------" << std::endl
              << "------------------ 0、退出 --------------------------" << std::endl
              << "-----------------------------------------------------" << std::endl;
}

int main() {
    enum OPERATE {ADD=1, DEL, FIND_ALL, FIND_ONE};
    ContactsServer contactsServer;
    while (true) {
        menu();
        std::cout << "---> 请选择：";
        int choose;
        std::cin >> choose;
        std::cin.ignore(256, '\n');
        try {
            switch (choose) {
                case OPERATE::ADD:
                    contactsServer.addContact();
                    break;
                case OPERATE::DEL:
                    contactsServer.delContact();
                    break;
                case OPERATE::FIND_ALL:
                    contactsServer.findContacts();
                    break;
                case OPERATE::FIND_ONE:
                    contactsServer.findContact();
                    break;
                case 0:
                    std::cout << "---> 程序已退出" << std::endl;
                    return 0;
                default:
                    std::cout << "---> 无此选项，请重新选择！" << std::endl;
                    break;
            }
        } catch (const ContactException& e) {
            std::cerr << "---> 操作通讯录时发现异常！！！" << std::endl
                 << "---> 异常信息：" << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "---> 操作通讯录时发现异常！！！" << std::endl
                << "---> 异常信息：" << e.what() << std::endl;
        }
    }
}

