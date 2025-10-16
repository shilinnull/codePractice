#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;

//#include<iostream>
//#include<map>
//#include<string>
//using namespace std;
//int main()
//{
//	// 1. 解包数组
//	int arr[2] = { 1, 2 };
//	auto [x, y] = arr; // x = 1, y = 2
//	cout << x << endl;
//	cout << y << endl;
//
//	// 需要注意的是结构化绑定是将arr中的值拷贝给x和y
//	// 也就是说x和y的改变，不影响数组中的值
//	x++;
//	cout << arr[0] << endl;
//	
//	// 这里加引用，就可以做到xx和yy是数组中对应值的别名
//	auto& [xx, yy] = arr;
//	xx++;
//	cout << arr[0] << endl;
//	
//	// 2. 解包元组(std::tuple)
//	std::tuple<int, double, std::string> t(1, 2.3, "hello");
//	auto [a1, b1, c1] = t;
//	auto& [a2, b2, c2] = t;
//	auto&& [a3, b3, c3] = move(t);
//	//auto& [a4, b4] = std::make_tuple(1, 2); // 编译报错
//	auto&& [a5, b5] = std::make_tuple(1, 2);
//	
//	// 3.解包结构体/类
//	struct Point {
//		void func()
//		{
//			auto [x1, y1] = *this; // x1=1.1, y1=2.2
//			cout << x1 << endl;
//			cout << y1 << endl;
//		}
//		//private:
//		double x;
//		double y;
//	};
//	
//	// 如果成员变量是私有的，则无法做结构化绑定
//	Point p{ 1.1, 2.2 };
//	auto [x1, y1] = p; // x1=1.1, y1=2.2
//	cout << x1 << endl;
//	cout << y1 << endl;
//	
//	// 结构化绑定不支持嵌套绑定
//	//auto [[mm1, mm2], nn1] = std::make_tuple(p, 1); // 报错
//	auto [m1, n1] = std::make_tuple(p, 1);
//
//	// 实践使用场景：范围for叠加结构化绑定使用遍历map
//	std::map<std::string, int> m = { {"xxxx", 1}, {"yyyy", 2} };
//	for (const auto& [key, value] : m)
//	{
//		std::cout << key << ": " << value << "\n";
//	}
//	return 0;
//}


