#include"string.h"

void Test1() {
	lsl::string s1("hello world");
	lsl::string s2;

	cout << s1.c_str() << endl;
	cout << s1[1] << endl;

	lsl::string::iterator it = s1.begin();
	while (it != s1.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (auto ch : s1) {
		cout << ch << " ";
	}
	cout << endl;
}


void Test2() {
	lsl::string s1("xxxxxxx");
	lsl::string::const_iterator it = s1.begin();
	while (it != s1.end()) {
		cout << *it << " ";
		++it;
	}
}
void Test3() {
	lsl::string s1("xxxxxxx");
	s1.push_back('1');
	s1.push_back('2');
	cout << s1.c_str() << endl;
	s1 += 'a';
	s1 += 'b';
	s1 += 'c';
	s1 += 'd';
	s1 += 'e';
	s1 += "yyyyyyyyyyyy";
	cout << s1.c_str() << endl;
	s1.insert(3, 'a');
	s1.insert(0, 'i');
	s1.insert(s1.size(), 'i');
	// s1.insert(1000, 'i');
	cout << s1.c_str() << endl;
	s1.resize(2);
	s1.resize(30, 'a');
	cout << s1.c_str() << endl;
	lsl::string s2(s1);
	cout << s2.c_str() << endl;

	lsl::string s3;
	s3 = s1;
	cout << s3.c_str() << endl;
}
void Test4() {
	lsl::string s1("hello");
	lsl::string s2(s1);
	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
	s2.insert(3, "world");
	cout << s2.c_str() << endl;

}

void Test5() {
	lsl::string s1("hello");
	lsl::string s2("world");
	cout << s1 << endl;
	cout << s2 << endl;
	
	swap(s1, s2);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s1.find('l') << endl;
	cout << s1.find("el",2) << endl;
}

int main() {

	Test5();

	return 0;
}
