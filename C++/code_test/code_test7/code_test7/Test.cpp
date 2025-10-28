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
//	// 1. �������
//	int arr[2] = { 1, 2 };
//	auto [x, y] = arr; // x = 1, y = 2
//	cout << x << endl;
//	cout << y << endl;
//
//	// ��Ҫע����ǽṹ�����ǽ�arr�е�ֵ������x��y
//	// Ҳ����˵x��y�ĸı䣬��Ӱ�������е�ֵ
//	x++;
//	cout << arr[0] << endl;
//	
//	// ��������ã��Ϳ�������xx��yy�������ж�Ӧֵ�ı���
//	auto& [xx, yy] = arr;
//	xx++;
//	cout << arr[0] << endl;
//	
//	// 2. ���Ԫ��(std::tuple)
//	std::tuple<int, double, std::string> t(1, 2.3, "hello");
//	auto [a1, b1, c1] = t;
//	auto& [a2, b2, c2] = t;
//	auto&& [a3, b3, c3] = move(t);
//	//auto& [a4, b4] = std::make_tuple(1, 2); // ���뱨��
//	auto&& [a5, b5] = std::make_tuple(1, 2);
//	
//	// 3.����ṹ��/��
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
//	// �����Ա������˽�еģ����޷����ṹ����
//	Point p{ 1.1, 2.2 };
//	auto [x1, y1] = p; // x1=1.1, y1=2.2
//	cout << x1 << endl;
//	cout << y1 << endl;
//	
//	// �ṹ���󶨲�֧��Ƕ�װ�
//	//auto [[mm1, mm2], nn1] = std::make_tuple(p, 1); // ����
//	auto [m1, n1] = std::make_tuple(p, 1);
//
//	// ʵ��ʹ�ó�������Χfor���ӽṹ����ʹ�ñ���map
//	std::map<std::string, int> m = { {"xxxx", 1}, {"yyyy", 2} };
//	for (const auto& [key, value] : m)
//	{
//		std::cout << key << ": " << value << "\n";
//	}
//	return 0;
//}


// #include "Cache.h"

// int main() {
//     cout << &bufferSize << endl;
//     cout << &cacheSize << endl;
//     func();
//     return 0;
// }

#include <iostream>
#include <map>
#include <string>

void ifwitchInit(){
    std::map<std::string, int> m{{"Alice", 15}, {"Bob", 30}};
    if(auto it = m.find("Alice"); it != m.end()) {
        std::cout << "Found Alice, age: " << it->second << std::endl;
    } else {
        std::cout << "Alice not found" << std::endl;
    }
}
int CheckVal(int v) {
    return v % 2;
}

void SwitchwithInit(int value) {
    switch (auto status = CheckVal(value); status)  {
    case 0:
        std::cout << "Status is Zero" << endl;
        break;
    case 1:
        std::cout << "Status is one" << std::endl;
        break;
    default:
        std::cout << "Unknown status: " << status << std::endl;
    }
}

int main() {
    ifwitchInit();
    SwitchwithInit(42);
    return 0;
}