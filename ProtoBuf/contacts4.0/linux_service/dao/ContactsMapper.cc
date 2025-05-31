#include "ContactsMapper.h"
#include "../common/ContactException.h"
#include <fstream>

#define TEXT_NAME "contacts.bin"

using std::ios;
using std::cout;
using std::endl;

// 本应该存入数据库中，在这里为了简化流程，将通讯录存入本地文件
void ContactsMapper::selectContacts(contacts::Contacts* contacts) const{
    std::fstream input(TEXT_NAME, ios::in | ios::binary);
    if (!input) {
        cout << "---> (ContactsMapper::selectContacts) " << TEXT_NAME << ": File not found.  Creating a new file." << endl;
    }
    else if (!contacts->ParseFromIstream(&input)) {
        input.close();
        throw ContactException("(ContactsMapper::selectContacts) Failed to parse contacts.");
    }
    input.close();
}


void ContactsMapper::insertContacts(contacts::Contacts& contacts) const {
    std::fstream output(TEXT_NAME, ios::out | ios::trunc | ios::binary);
    if (!contacts.SerializeToOstream(&output)) {
        output.close();
        throw ContactException("(ContactsMapper::insertContacts) Failed to write contacts.");
    }
    output.close();
}