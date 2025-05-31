#include "ContactsServer.h"
#include "../common/ContactException.h"
#include "../common/Utils.h"

using std::cout;
using std::endl;

void ContactsServer::add(add_contact_req::AddContactRequest& request, 
                         add_contact_resp::AddContactResponse* response) const {
    // 打印日志
    printAddContactRequest(request);      
    // 先读取已存在的 contacts
    contacts::Contacts contacts;
    contactsMapper.selectContacts(&contacts);

    // 转换为存入文件的消息对象  
    google::protobuf::Map<std::string, contacts::PeopleInfo>* map_contacts = contacts.mutable_contacts();
    contacts::PeopleInfo people;
    buildPeopleInfo(&people, request);   
    map_contacts->insert({people.uid(), people});   

    // 向磁盘文件写入新的 contacts
    contactsMapper.insertContacts(contacts);
    response->set_uid(people.uid());
    response->mutable_base_resp()->set_success(true);
    // 打印日志
    cout << "---> (ContactsServer::add) Success to write contacts." << endl;
}

void ContactsServer::del(del_contact_req::DelContactRequest& request,
                         del_contact_resp::DelContactResponse* response) const {
    // 打印日志
    cout << "---> (ContactsServer::del) DelContactRequest: uid: " << request.uid() << endl;  
    // 先读取已存在的 contacts
    contacts::Contacts contacts;
    contactsMapper.selectContacts(&contacts);
    // 不含uid直接返回
    if (contacts.contacts().find(request.uid()) == contacts.contacts().end()) {  
        cout << "---> (ContactsServer::del) not find uid: " << request.uid() << endl; 
        response->set_uid(request.uid());
        response->mutable_base_resp()->set_success(false);
        response->mutable_base_resp()->set_error_desc("not find uid");
        return;
    }
    // 删除用户
    contacts.mutable_contacts()->erase(request.uid());
    // 向磁盘文件写入新的 contacts
    contactsMapper.insertContacts(contacts);
    // 构造resp
    response->set_uid(request.uid());
    response->mutable_base_resp()->set_success(true);
    // 打印日志
    cout << "---> (ContactsServer::del) Success to del contact, uid: " << request.uid() << endl;
}

void ContactsServer::findOne(find_one_contact_req::FindOneContactRequest request, 
                             find_one_contact_resp::FindOneContactResponse* response) const {
    // 打印日志
    cout << "---> (ContactsServer::findOne) FindOneContactRequest: uid: " << request.uid() << endl;  
    // 获取通讯录
    contacts::Contacts contacts;
    contactsMapper.selectContacts(&contacts);
    // 转换resp消息对象
    const google::protobuf::Map<std::string, contacts::PeopleInfo>& map_contacts = contacts.contacts();
    auto it = map_contacts.find(request.uid());
    // 查找的联系人不存在
    if (it == map_contacts.end()) {
        cout << "---> (ContactsServer::findOne) not find uid: " << request.uid() << endl;
        response->mutable_base_resp()->set_success(false);
        response->mutable_base_resp()->set_error_desc("uid not exist");
        return;
    }
    // 构建resp
    buildFindOneContactResponse(it->second, response);
    // 打印日志
    cout << "---> (ContactsServer::findOne) find uid: " << request.uid() << endl;
}

void ContactsServer::findAll(find_all_contacts_resp::FindAllContactsResponse* rsp) const {
    // 打印日志
    cout << "---> (ContactsServer::findAll) " << endl;  

    // 获取通讯录
    contacts::Contacts contacts;
    contactsMapper.selectContacts(&contacts);

    // 转换resp消息对象
    buildFindAllContactsResponse(contacts, rsp);
}

void ContactsServer::buildFindAllContactsResponse(contacts::Contacts& contacts, 
                                  find_all_contacts_resp::FindAllContactsResponse* rsp) const {
    if (nullptr == rsp) {
        return;
    }
    rsp->mutable_base_resp()->set_success(true);
    for (auto it = contacts.contacts().cbegin(); it != contacts.contacts().cend(); ++it) {
        find_all_contacts_resp::PeopleInfo* people = rsp->add_contacts();
        people->set_uid(it->first);
        people->set_name(it->second.name());
    }
}

void ContactsServer::buildFindOneContactResponse(const contacts::PeopleInfo& people, 
                                 find_one_contact_resp::FindOneContactResponse* response) const {
    if (nullptr == response) {
        return;
    }
    response->mutable_base_resp()->set_success(true);
    response->set_uid(people.uid());
    response->set_name(people.name());
    response->set_age(people.age());
    for (auto& phone : people.phone()) {
        find_one_contact_resp::FindOneContactResponse_Phone* resp_phone = response->add_phone();
        resp_phone->set_number(phone.number());
        switch (phone.type()) {
            case contacts::PeopleInfo_Phone_PhoneType::PeopleInfo_Phone_PhoneType_MP:
                  resp_phone->set_type(find_one_contact_resp::FindOneContactResponse_Phone_PhoneType::FindOneContactResponse_Phone_PhoneType_MP);
                  break;
            case contacts::PeopleInfo_Phone_PhoneType::PeopleInfo_Phone_PhoneType_TEL:
                  resp_phone->set_type(find_one_contact_resp::FindOneContactResponse_Phone_PhoneType::FindOneContactResponse_Phone_PhoneType_TEL);
                  break;
            default:
                  break;
        }
    }
    Utils::map_copy(response->mutable_remark(), people.remark());
}

void ContactsServer::printAddContactRequest(add_contact_req::AddContactRequest& request) const {
    cout << "---> (ContactsServer::add) AddContactRequest:" << endl;
    cout << "姓名：" << request.name() << endl;
    cout << "年龄：" << request.age() << endl;
    for (auto& phone : request.phone()) {
      int j = 1;
      cout << "电话" << j++ << ": " << phone.number();
      cout << "  (" << phone.PhoneType_Name(phone.type()) << ")" << endl;
    }
    if (request.remark_size()) {
      cout << "备注信息: " << endl;
    }
    for (auto it = request.remark().cbegin(); it != request.remark().cend(); ++it) {      
      cout << "    " << it->first << ": " << it->second << endl;      
    }      
}

void ContactsServer::buildPeopleInfo(contacts::PeopleInfo* people, add_contact_req::AddContactRequest& request) const {
    std::string uid = Utils::generate_hex(10);
    people->set_uid(uid);
    people->set_name(request.name());
    people->set_age(request.age());
    for (auto& phone : request.phone()) {
        contacts::PeopleInfo_Phone* peo_phone = people->add_phone();
        peo_phone->set_number(phone.number());
        switch (phone.type()) {
            case add_contact_req::AddContactRequest_Phone_PhoneType::AddContactRequest_Phone_PhoneType_MP:
                  peo_phone->set_type(contacts::PeopleInfo_Phone_PhoneType::PeopleInfo_Phone_PhoneType_MP);
                  break;
            case add_contact_req::AddContactRequest_Phone_PhoneType::AddContactRequest_Phone_PhoneType_TEL:
                  peo_phone->set_type(contacts::PeopleInfo_Phone_PhoneType::PeopleInfo_Phone_PhoneType_TEL);
                  break;
            default:
                  break;
        }
    }
    Utils::map_copy(people->mutable_remark(), request.remark());
}