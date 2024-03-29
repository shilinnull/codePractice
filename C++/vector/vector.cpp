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
	v1.push_back(5);
	v1.push_back(4);
	print_vector(v1);

	lsl::vector<int> v2(v1);
	print_vector(v2);
}
void Test4() {
	lsl::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(4);
	print_vector(v1);

	lsl::vector<int> v2(v1.begin() + 1, v1.end() - 1);
	print_vector(v2);
	std::string s("hello");
	lsl::vector<int> v3(s.begin(), s.end());
	print_vector(v3);

}

void Test5() {
	lsl::vector<int> v1(10u, 5);
	print_vector(v1);

	lsl::vector<int> v2(10, 'a');
	print_vector(v2);

	auto x = { 1,4,7,53,6,63,64,5 };
	for (auto e : x)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;


	std::initializer_list<int> y = { 1,2,3,4,5,5,667,2 };
	for (auto e : y)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// 隐式类型转换 + 优化
	lsl::vector<int> v4 = { 1,2,3,4,5,6,7,8,9,10 };
	print_vector(v4);

	// 直接构造
	lsl::vector<int> v3({ 1,2,3,4,5,6,7,8,9,10 });
	print_vector(v3);

}
void Test6() {
	lsl::vector<std::string> v1;
	v1.push_back("1111");
	v1.push_back("2222");
	v1.push_back("3333");
	v1.push_back("4444");
	v1.push_back("5555");
	print_vector(v1);
}

void Test7() {
	lsl::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(5);
	v1.push_back(5);
	print_vector(v1);

	lsl::vector<int>::iterator it = v1.begin() + 2;
	v1.insert(it, 40);
	print_vector(v1);

	it = v1.begin() + 3;
	std::cout << *it << std::endl;

	lsl::vector<int>::iterator it1 = v1.begin();
	while (it1 != v1.end())
	{
		if (*it1 % 2)
		{
			it1 = v1.erase(it1);
		}
		else
		{
			++it1;
		}
	}
	print_vector(v1);
}


int main() {

	//Test1();
	//Test2();
	//Test3();
	Test7();
	return 0;
}