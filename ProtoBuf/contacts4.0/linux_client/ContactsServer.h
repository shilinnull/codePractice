#include <iostream>
#include "./request/add_contact_request.pb.h"
#include "./response/add_contact_response.pb.h"
#include "./request/find_one_contact_request.pb.h"
#include "./response/find_one_contact_response.pb.h"
#include "./response/find_all_contacts_response.pb.h"
#include "./request/del_contact_request.pb.h"
#include "./response/del_contact_response.pb.h"

class ContactsServer
{
public:
    void addContact();
    void delContact();
    void findContacts();
    void findContact();
private:
    void buildAddContactRequest(add_contact_req::AddContactRequest* req);
    void printFindOneContactResponse(find_one_contact_resp::FindOneContactResponse& resp);
    void printFindAllContactsResponse(find_all_contacts_resp::FindAllContactsResponse& resp);
};
