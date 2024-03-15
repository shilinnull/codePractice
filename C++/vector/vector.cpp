#include"vector.h"

void Test1() {
	lsl::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	lsl::print_vector(v);

	lsl::vector<double> v2;
	v2.push_back(1.1);
	v2.push_back(2.2);
	v2.push_back(3.1);
	lsl::print_vector(v2);

	v2.insert(v2.begin(), 11.11);
	lsl::print_vector(v2);

	v2.insert(v2.begin(), 11.11);
	lsl::print_vector(v2);

	v2.insert(v2.begin(), 11.11);
	lsl::print_vector(v2);

	v2.insert(v2.begin(), 11.11);
	lsl::print_vector(v2);

	v2.insert(v2.begin(), 11.11);
	lsl::print_vector(v2);

	v2.erase(v2.begin());
	lsl::print_vector(v2);

	v2.erase(v2.begin() + 4);
	lsl::print_vector(v2);
}

void Test2() {
	int i = 0;
	int j = int();
	int k(1);
	lsl::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(4);
	v1.push_back(4);
	print_vector(v1);

	v1.resize(10);
	print_vector(v1);

	v1.resize(3);
	print_vector(v1);

}

void Test3() {
	lsl::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(4);
	v1.push_back(4);
	print_vector(v1);

	lsl::vector<int> v2(v1);
	print_vector(v2);
}
int main() {

	//Test1();
	//Test2();
	Test3();
	return 0;
}