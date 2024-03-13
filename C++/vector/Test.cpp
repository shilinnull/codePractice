#include"vector.h"

void Test_vector1() {
	vector<int> v(10, 6);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	
	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

void Test_vector2() {
	vector<int> v;
	v.reserve(100);
	size_t sz = v.capacity();
	cout << "begin£º" << endl;

	for (size_t i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (sz != v.capacity()) {
			sz = v.capacity();
			cout << "capacity£º" << sz << endl;
		}
	}
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.reserve(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << "--------------" << endl;

	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	
	v.shrink_to_fit();
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	vector<int> a;
	a.resize(10, 1);
	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;

}

void Test_vector3() {
	vector<int> v;
	for (size_t i = 0; i < 10; i++){
		v.push_back(i);
	}

	auto pos = find(v.begin(), v.end(), 3);
	if (pos != v.end()) {
		v.insert(pos, 30);
	}
	v.insert(v.begin() + 2, 666);

	for (auto e : v){
		cout << e << " ";
	}
	cout << endl;

	string s("hello");
	v.insert(v.begin(), s.begin(), s.end());
	
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;
}
void Test_vector4() {
	vector<string> v;
	v.push_back("he");
	v.push_back("llo");

	vector<vector<int>> vv;
}

int main() {
	
	//Test_vector1();
	//Test_vector2();
	//Test_vector3();
	Test_vector4();
	return 0;
}
