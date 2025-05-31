#include <iostream>
#include "contacts.pb.h"
x
using namespace std;

int main(){
    
    string people_str;
    
    {
        contacts::PeopleInfo people;
        people.set_name("John Doe");
        people.set_age(30);

        // 序列化
        if (!people.SerializeToString(&people_str)) {
            cerr << "Failed to serialize." << endl;
            return -1;
        }
        cout << "Serialized string: " << people_str << endl;
    }

    {
        contacts::PeopleInfo people;
        // 反序列化
        if (!people.ParseFromString(people_str)) {
            cerr << "Failed to parse." << endl;
            return -1;
        }
        cout << "Parsed name: " << people.name() << endl;
        cout << "Parsed age: " << people.age() << endl;
    }

    return 0;
}