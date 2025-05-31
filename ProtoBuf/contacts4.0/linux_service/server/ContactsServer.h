#pragma once

#include <iostream>
#include "httplib.h"
#include "../controller/request/add_contact_request.pb.h"
#include "../controller/response/add_contact_response.pb.h"
#include "../controller/request/find_one_contact_request.pb.h"
#include "../controller/response/find_one_contact_response.pb.h"
#include "../controller/response/find_all_contacts_response.pb.h"
#include "../controller/request/del_contact_request.pb.h"
#include "../controller/response/del_contact_response.pb.h"
#include "../dao/contacts.pb.h"
#include "../dao/ContactsMapper.h"


using namespace httplib;

class ContactsServer {
public:
    ContactsMapper contactsMapper;

public:
    void add(add_contact_req::AddContactRequest& request,
             add_contact_resp::AddContactResponse* response) const;

    void del(del_contact_req::DelContactRequest& request,
             del_contact_resp::DelContactResponse* response) const;

    void findOne(find_one_contact_req::FindOneContactRequest request, 
                 find_one_contact_resp::FindOneContactResponse* response) const;

    void findAll(find_all_contacts_resp::FindAllContactsResponse* rsp) const;

private:
    void printAddContactRequest(add_contact_req::AddContactRequest& request) const;
    void buildPeopleInfo(contacts::PeopleInfo* people, add_contact_req::AddContactRequest& request) const;
    void buildFindOneContactResponse(const contacts::PeopleInfo& people, 
                                     find_one_contact_resp::FindOneContactResponse* response) const;
    void buildFindAllContactsResponse(contacts::Contacts& contacts, 
                                      find_all_contacts_resp::FindAllContactsResponse* rsp) const;
};

