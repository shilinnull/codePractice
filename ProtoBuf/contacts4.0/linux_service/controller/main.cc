#include <iostream>
#include "httplib.h"
#include "../server/ContactsServer.h"
#include "../common/ContactException.h"
#include "request/add_contact_request.pb.h"
#include "response/add_contact_response.pb.h"
#include "request/find_one_contact_request.pb.h"
#include "response/find_one_contact_response.pb.h"
#include "response/find_all_contacts_response.pb.h"
#include "request/del_contact_request.pb.h"
#include "response/del_contact_response.pb.h"

using std::cout;
using std::endl;
using std::cerr;
using namespace httplib;

int main() {
  
    cout << "---> 服务启动..." << endl;
    Server srv;  // 创建服务端对象
    ContactsServer contactsServer;
    srv.Post("/contacts/add", [contactsServer](const Request& req, Response& res) {
        add_contact_req::AddContactRequest request;
        add_contact_resp::AddContactResponse response;
        try {
            // 反序列化 request
            if (!request.ParseFromString(req.body)) {
                throw ContactException("Parse AddContactRequest error!");
            }
            // 新增联系人
            contactsServer.add(request, &response);
            // 序列化 resp
            std::string response_str;
            if (!response.SerializeToString(&response_str)) {
                throw ContactException("Serialize AddContactResponse error");
            }
            res.body = response_str;
            res.set_header("Content-Type", "application/protobuf");
            res.status = 200;
        } catch (ContactException &e) {
            cerr << "---> /contacts/add 发现异常!!!" << endl
                << "---> 异常信息：" << e.what() << endl;
            res.status = 500;
            base_response::BaseResponse* baseResponse = response.mutable_base_resp();
            baseResponse->set_success(false);
            baseResponse->set_error_desc(e.what());
            std::string response_str;
            if (response.SerializeToString(&response_str)) {
              res.body = response_str;
              res.set_header("Content-Type", "application/protobuf");
            }
        }
    });	

    srv.Post("/contacts/del", [contactsServer](const Request& req, Response& res) {
        del_contact_req::DelContactRequest request;
        del_contact_resp::DelContactResponse response;
        try {
            // 反序列化 request
            if (!request.ParseFromString(req.body)) {
                throw ContactException("Parse DelContactRequest error!");
            }
            // 删除联系人
            contactsServer.del(request, &response);
            // 序列化 response
            std::string response_str;
            if (!response.SerializeToString(&response_str)) {
                throw ContactException("Serialize DelContactResponse error");
            }
            res.body = response_str;
            res.set_header("Content-Type", "application/protobuf");
            res.status = 200;
        } catch (ContactException &e) {
            cerr << "---> /contacts/del 发现异常!!!" << endl
                << "---> 异常信息：" << e.what() << endl;
            res.status = 500;
            base_response::BaseResponse* baseResponse = response.mutable_base_resp();
            baseResponse->set_success(false);
            baseResponse->set_error_desc(e.what());
            std::string response_str;
            if (response.SerializeToString(&response_str)) {
              res.body = response_str;
              res.set_header("Content-Type", "application/protobuf");
            }
        }
    });	

    srv.Post("/contacts/find-one", [contactsServer](const Request& req, Response& res) {
        find_one_contact_req::FindOneContactRequest request;
        find_one_contact_resp::FindOneContactResponse response;
        try {
            // 反序列化 request
            if (!request.ParseFromString(req.body)) {
                throw ContactException("Parse FindOneContactRequest error!");
            }
            // 查询联系人详细信息
            contactsServer.findOne(request, &response);
            // 序列化 response
            std::string response_str;
            if (!response.SerializeToString(&response_str)) {
                throw ContactException("Serialize FindOneContactResponse error");
            }
            res.body = response_str;
            res.set_header("Content-Type", "application/protobuf");
            res.status = 200;
        } catch (ContactException &e) {
            cerr << "---> /contacts/find-one 发现异常!!!" << endl
                << "---> 异常信息：" << e.what() << endl;
            res.status = 500;
            base_response::BaseResponse* baseResponse = response.mutable_base_resp();
            baseResponse->set_success(false);
            baseResponse->set_error_desc(e.what());
            std::string response_str;
            if (response.SerializeToString(&response_str)) {
              res.body = response_str;
              res.set_header("Content-Type", "application/protobuf");
            }
        }
    });	

    srv.Get("/contacts/find-all", [contactsServer](const Request& req, Response& res) {
        find_all_contacts_resp::FindAllContactsResponse response;
        try {
            // 查询所有联系人
            contactsServer.findAll(&response);
            // 序列化 response
            std::string response_str;
            if (!response.SerializeToString(&response_str)) {
                throw ContactException("Serialize FindAllContactsResponse error");
            }
            res.body = response_str;
            res.set_header("Content-Type", "application/protobuf");
            res.status = 200;
        } catch (ContactException &e) {
            cerr << "---> /contacts/find-all 发现异常!!!" << endl
                << "---> 异常信息：" << e.what() << endl;
            res.status = 500;
            base_response::BaseResponse* baseResponse = response.mutable_base_resp();
            baseResponse->set_success(false);
            baseResponse->set_error_desc(e.what());
            std::string response_str;
            if (response.SerializeToString(&response_str)) {
              res.body = response_str;
              res.set_header("Content-Type", "application/protobuf");
            }
        }
    });

    srv.listen("0.0.0.0", 8123); 
}
