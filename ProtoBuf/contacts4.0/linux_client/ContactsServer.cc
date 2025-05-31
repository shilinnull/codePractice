#include "ContactsServer.h"
#include "ContactException.h"
#include "httplib.h"

#define CONTACTS_IP "113.44.240.190"
#define CONTACTS_PORT 8123


void ContactsServer::addContact() {
    httplib::Client cli(CONTACTS_IP, CONTACTS_PORT);
    // 构建 request 请求
    add_contact_req::AddContactRequest req;
    buildAddContactRequest(&req);

    // 序列化 request
    std::string req_str;
    if (!req.SerializeToString(&req_str)) {
        throw ContactException("AddContactRequest序列化失败!");
    }

    // 发起 post 请求
    auto res = cli.Post("/contacts/add", req_str, "application/protobuf");
    if (!res) {
        std::string err_desc;
        err_desc.append("/contacts/add 链接错误！错误信息：")
                .append(httplib::to_string(res.error()));
        throw ContactException(err_desc);
    }

    // 反序列化 response
    add_contact_resp::AddContactResponse resp;
    bool parse = resp.ParseFromString(res->body);
    // 处理异常
    if (res->status != 200 && !parse) {
        std::string err_desc;
        err_desc.append("post '/contacts/add/' 失败：")
                .append(std::to_string(res->status))
                .append("(").append(res->reason)
                .append(")");
        throw ContactException(err_desc);
    }
    else if (res->status != 200) {
        // 处理服务异常
        std::string err_desc;
        err_desc.append("post '/contacts/add/' 失败 ")
            .append(std::to_string(res->status))
            .append("(").append(res->reason)
            .append(")  错误原因：")
            .append(resp.base_resp().error_desc());
        throw ContactException(err_desc);
    }
    else if (!resp.base_resp().success()) {
        // 处理结果异常
        std::string err_desc;
        err_desc.append("post '/contacts/add/' 结果异常：")
            .append("异常原因：")
            .append(resp.base_resp().error_desc());
        throw ContactException(err_desc);
    }

    // 正常返回，打印结果
    std::cout << "---> 新增联系人成功，联系人ID：" << resp.uid() << std::endl;
}

void ContactsServer::delContact() {
    httplib::Client cli(CONTACTS_IP, CONTACTS_PORT);
    // 构建 request 请求
    del_contact_req::DelContactRequest req;
    std::cout << "请输入要删除的联系人id: ";
    std::string uid;
    getline(std::cin, uid);
    req.set_uid(uid);

    // 序列化 request
    std::string req_str;
    if (!req.SerializeToString(&req_str)) {
        throw ContactException("DelContactRequest序列化失败!");
    }

    // 发起 post 请求
    auto res = cli.Post("/contacts/del", req_str, "application/protobuf");
    if (!res) {
        std::string err_desc;
        err_desc.append("/contacts/del 链接错误！错误信息：")
            .append(httplib::to_string(res.error()));
        throw ContactException(err_desc);
    }

    // 反序列化 response
    del_contact_resp::DelContactResponse resp;
    bool parse = resp.ParseFromString(res->body);
    // 处理异常
    if (res->status != 200 && !parse) {
        std::string err_desc;
        err_desc.append("post '/contacts/del' 失败：")
            .append(std::to_string(res->status))
            .append("(").append(res->reason)
            .append(")");
        throw ContactException(err_desc);
    }
    else if (res->status != 200) {
        std::string err_desc;
        err_desc.append("post '/contacts/del' 失败 ")
            .append(std::to_string(res->status))
            .append("(").append(res->reason)
            .append(")  错误原因：")
            .append(resp.base_resp().error_desc());
        throw ContactException(err_desc);
    }
    else if (!resp.base_resp().success()) {
        // 结果异常
        std::string err_desc;
        err_desc.append("post '/contacts/del' 结果异常：")
            .append("异常原因：")
            .append(resp.base_resp().error_desc());
        throw ContactException(err_desc);
    }

    // 正常返回，打印结果
    std::cout << "---> 成功删除联系人，被删除的联系人ID为：" << resp.uid() << std::endl;
}

void ContactsServer::findContacts() {
    httplib::Client cli(CONTACTS_IP, CONTACTS_PORT);
    // 发起 get 请求
    auto res = cli.Get("/contacts/find-all");
    if (!res) {
        std::string err_desc;
        err_desc.append("/contacts/find-all 链接错误！错误信息：")
            .append(httplib::to_string(res.error()));
        throw ContactException(err_desc);
    }

    // 反序列化 response
    find_all_contacts_resp::FindAllContactsResponse resp;
    bool parse = resp.ParseFromString(res->body);
    // 处理异常
    if (res->status != 200 && !parse) {
        std::string err_desc;
        err_desc.append("get '/contacts/find-all' 失败：")
            .append(std::to_string(res->status))
            .append("(").append(res->reason)
            .append(")");
        throw ContactException(err_desc);
    }
    else if (res->status != 200) {
        // 服务端异常
        std::string err_desc;
        err_desc.append("post '/contacts/find-all' 失败 ")
            .append(std::to_string(res->status))
            .append("(").append(res->reason)
            .append(")  错误原因：")
            .append(resp.base_resp().error_desc());
        throw ContactException(err_desc);
    }
    else if (!resp.base_resp().success()) {
        // 结果异常
        std::string err_desc;
        err_desc.append("post '/contacts/find-all' 结果异常：")
            .append("异常原因：")
            .append(resp.base_resp().error_desc());
        throw ContactException(err_desc);
    }
    // 正常返回，打印结果
    printFindAllContactsResponse(resp);
}

void ContactsServer::findContact() {
    httplib::Client cli(CONTACTS_IP, CONTACTS_PORT);
    // 构建 request 请求
    find_one_contact_req::FindOneContactRequest req;
    std::cout << "请输入要查询的联系人id: ";
    std::string uid;
    getline(std::cin, uid);
    req.set_uid(uid);

    // 序列化 request
    std::string req_str;
    if (!req.SerializeToString(&req_str)) {
        throw ContactException("FindOneContactRequest序列化失败!");
    }

    // 发起 post 请求
    auto res = cli.Post("/contacts/find-one", req_str, "application/protobuf");
    if (!res) {
        std::string err_desc;
        err_desc.append("/contacts/find-one 链接错误！错误信息：")
            .append(httplib::to_string(res.error()));
        throw ContactException(err_desc);
    }

    // 反序列化 response
    find_one_contact_resp::FindOneContactResponse resp;
    bool parse = resp.ParseFromString(res->body);

    // 处理异常
    if (res->status != 200 && !parse) {
        std::string err_desc;
        err_desc.append("post '/contacts/find-one' 失败：")
            .append(std::to_string(res->status))
            .append("(").append(res->reason)
            .append(")");
        throw ContactException(err_desc);
    }
    else if (res->status != 200) {
        std::string err_desc;
        err_desc.append("post '/contacts/find-one' 失败 ")
            .append(std::to_string(res->status))
            .append("(").append(res->reason)
            .append(")  错误原因：")
            .append(resp.base_resp().error_desc());
        throw ContactException(err_desc);
    }
    else if (!resp.base_resp().success()) {
        // 结果异常
        std::string err_desc;
        err_desc.append("post '/contacts/find-one' 结果异常：")
            .append("异常原因：")
            .append(resp.base_resp().error_desc());
        throw ContactException(err_desc);
    }

    // 正常返回，打印结果
    std::cout << "---> 查询到联系人ID为：" << resp.uid() << " 的信息：" << std::endl;
    printFindOneContactResponse(resp);
}


void ContactsServer::printFindAllContactsResponse(find_all_contacts_resp::FindAllContactsResponse& resp) {
    if (0 == resp.contacts_size()) {
        std::cout << "还未添加任何联系人" << std::endl;
        return;
    }
    for (auto contact : resp.contacts()) {
        std::cout << "联系人姓名: " << contact.name() << " 联系人ID：" << contact.uid() << std::endl;
    }
}

void ContactsServer::buildAddContactRequest(add_contact_req::AddContactRequest* req) {
    std::cout << "请输入联系人姓名: ";
    std::string name;
    getline(std::cin, name);
    req->set_name(name);

    std::cout << "请输入联系人年龄: ";
    int age;
    std::cin >> age;
    req->set_age(age);
    std::cin.ignore(256, '\n'); 

    for(int i = 1; ; i++) {
        std::cout << "请输入联系人电话" << i << "(只输入回车完成电话新增): ";
        std::string number;
        getline(std::cin, number);
        if (number.empty()) {
            break;
        }
        add_contact_req::AddContactRequest_Phone* phone = req->add_phone();
        phone->set_number(number);

        std::cout << "选择此电话类型 (1、移动电话   2、固定电话) : " ;
        int type;
        std::cin >> type;
        std::cin.ignore(256, '\n');
        switch (type) {
            case 1:
                  phone->set_type(add_contact_req::AddContactRequest_Phone_PhoneType::AddContactRequest_Phone_PhoneType_MP);
                  break;
            case 2:
                  phone->set_type(add_contact_req::AddContactRequest_Phone_PhoneType::AddContactRequest_Phone_PhoneType_TEL);
                  break;
            default:
                  std::cout << "----非法选择，使用默认值！" << std::endl;
                  break;
        }
    }

    for(int i = 1; ; i++) {
        std::cout << "请输入备注" << i << "标题 (只输入回车完成备注新增): ";
        std::string remark_key;
        getline(std::cin, remark_key);
        if (remark_key.empty()) {
            break;
        }

        std::cout << "请输入备注" << i << "内容: ";
        std::string remark_value;
        getline(std::cin, remark_value);
        req->mutable_remark()->insert({remark_key, remark_value}); 
    }
}

void ContactsServer::printFindOneContactResponse(find_one_contact_resp::FindOneContactResponse& resp) {
    std::cout << "姓名：" << resp.name() << std::endl;
    std::cout << "年龄：" << resp.age() << std::endl;
    for (auto& phone : resp.phone()) {
        int j = 1;
        std::cout << "电话" << j++ << ": " << phone.number();
        std::cout << "  (" << phone.PhoneType_Name(phone.type()) << ")" << std::endl;
    }
    if (resp.remark_size()) {
        std::cout << "备注信息: " << std::endl;
    }
    for (auto it = resp.remark().cbegin(); it != resp.remark().cend(); ++it) {
        std::cout << "    " << it->first << ": " << it->second << std::endl;
    }
}
