#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;

//int main()
//{
//	for (int i = 0; i < 50; i++)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int* const p1 = &i;		// 顶层const
//	
//	const int ci = 111;		// 顶层const
//	const int* p2 = &ci;	// 底层const
//	const int& r = ci;		// 底层const
//	return 0;
//}


//int size()
//{
//	int n = 10;
//	return n;
//}
//
//int main()
//{
//	const int a = 1;		// a是常量表达式
//	const int b = a + 1;	// b是常量表达式
//	int c = 1;				// c不是常量表达式
//	const int d = c;		// d不是常量表达式
//	const int e = size();	// e不是常量表达式
//	
//	// 常量表达式可以做数组大小，vs不支持变长数组，所以这里数组大小必须是编译时确认的
//	int arr[a];
//	constexpr int aa = 1;
//	constexpr int bb = aa + 1;
//
//	//constexpr int cc = c;				// 报错
//	//constexpr int cc = size();		// 报错
//	//constexpr int* p1 = &d;			// 报错，权限放大了，constexpr修饰的是p1本身
//
//	const int* p2 = &d;
//	constexpr const int* p3 = &d;		// constexpr修饰的是p1本身，const修饰*p3
//	return 0;
//}

//constexpr int size()
//{
//	return 10;
//}
//constexpr int func(int x)
//{
//	return 10 + x;
//}
//constexpr int factorial(int n)
//{
//	return n <= 1 ? 1 : n * factorial(n - 1);
//}
//constexpr int fxx(int x)
//{
//	int i = x;
//	i++;
//	cout << i << endl;
//	return 10 + x;
//}
//
//int main()
//{
//	// 编译时，N会被直接替换为10，constexpr函数默认就是inline
//	constexpr int N1 = size();
//	int arr1[N1];
//	// func传10时，func函数返回值是常量表达式，所以N2是常量表达式
//	constexpr int N2 = func(10);
//	int arr2[N2];
//	
//	int i = 10;
//	constexpr int N3 = func(i); // 报错func返回的不是常量表达式
//	int N4 = func(i); // 不报错constexpr函数返回的不一是常量表达式
//
//	constexpr int fact5 = factorial(5); // 编译时计算
//	
//	// constexpr修饰的函数可以有一些其他语句，但是这些语句运行时可以不执行任何操作就可以
//	// 如类型别名、空语句、using声明等
//	constexpr int N5 = fxx(10); // 报错
//
//	return 0;
//}

//class Date
//{
//public:
//	constexpr Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		//cout << "constexpr Date(int year, int month, int day)" << endl;
//	}
//	constexpr int GetYear() const
//	{
//		return _year;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//template<typename T>
//constexpr T Func(T t)
//{
//	return t;
//}
//
//int main()
//{
//	int x = 2025;
//	// constexpr Date d0(x, 9, 8); // 报错 必须使用常量进行初始化
//	constexpr Date d1(2000, 1, 1);
//	constexpr int y = d1.GetYear();
//
//	Date d2(2000, 1, 1);
//	int z = d2.GetYear();
//	string ret1 = Func("111111"); // 普通函数
//	constexpr int ret2 = Func(10);
//	return 0;
//}

// C++14允许的constexpr函数示例
//constexpr int factorial(int n) {
//	int res = 1; // 允许局部变量
//	for (int i = 2; i <= n; ++i) { // 允许循环
//		res *= i;
//	}
//	return res; // 单一 return
//}
//
//constexpr size_t stringLength(const char* str) {
//	size_t len = 0;
//	while (str[len] != '\0')
//		++len;
//	return len;
//}
//
//int main()
//{
//	constexpr size_t len = stringLength("Hello"); // 编译期计算：5
//	return 0;
//}


//#include<vector>
//#include<array>
//using namespace std;
//
//struct Point {
//	constexpr Point(double x, double y) : x(x), y(y) {}
//	double x, y;
//};
//
//constexpr Point midpoint(Point a, Point b) {
//	return Point((a.x + b.x) / 2, (a.y + b.y) / 2);
//}
//
//constexpr std::array<int, 5> createArray() {
//	std::array<int, 5> arr{};
//	for (int i = 0; i < arr.size(); ++i) {
//		arr[i] = i * i;
//	}
//	return arr;
//}
//
//constexpr int fibonacci(int n) {
//	return (n <= 1) ? n : (fibonacci(n - 1) + fibonacci(n - 2));
//}
//
//int main()
//{
//	Point p1 = midpoint({ 1.1,1.1 }, { 2.2,2.2 });
//	constexpr Point p2 = midpoint({ 1.1,1.1 }, { 2.2,2.2 });
//	constexpr std::array<int, 5> a1 = createArray();
//	constexpr int fibArray[] = {
//		fibonacci(0), fibonacci(1), fibonacci(2), fibonacci(3),
//		fibonacci(4), fibonacci(5), fibonacci(6), fibonacci(7)
//	};
//	return 0;
//}


//template <typename T>
//auto get_value(T t) {
//	if constexpr (std::is_pointer_v<T>) {
//		return *t; // 仅当T为指针类型时实例化
//	}
//	else {
//		return t; // 非指针类型时实例化
//	}
//}
//
//int main()
//{
//	int x = 42;
//	auto v1 = get_value(x);		// 返回x本身
//	auto v2 = get_value(&x);	// 解引用返回42
//	return 0;
//}

//int main()
//{
//	// constexpr lambda示例
//	constexpr int n = 10;
//	int y = 0;
//	constexpr auto square = [n](int x) constexpr { return x * x * n; };
//	constexpr int result = square(5); // 编译期计算：250
//	return 0;
//}

//constexpr int dynamic_memory_example() {
//	int* p = new int{ 42 }; // 编译期分配
//	int value = *p;
//	delete p; // 必须显式释放
//	return value;
//}
//int main()
//{
//	constexpr int v = dynamic_memory_example(); // 42
//	return 0;
//}

//#include<vector>
//#include<array>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//constexpr std::vector<int> create_vector() {
//	std::vector<int> v{ 1, 2, 3 }; // 编译期构造
//	v.push_back(4); // 编译期操作
//	return v;
//}
//
//constexpr auto sort_example() {
//	std::array<int, 5> arr{ 5, 3, 4, 1, 2 };
//	std::sort(arr.begin(), arr.end()); // 编译期排序
//	return arr;
//}
//
//int main()
//{
//	constexpr array<int, 10> a1 = { 3,2,1,4,5 };
//
//	vector<int> v2 = { 3,2,1,4,5 };
//	sort(v2.begin(), v2.end());
//	auto it1 = find(v2.begin(), v2.end(), 3);
//
//	// 相对有限支持的constexpr
//	constexpr auto sorted = sort_example(); // {1,2,3,4,5}
//	constexpr auto it2 = find(a1.begin(), a1.end(), 4);
//	static_assert(*it2 == 4, "编译期查找");
//
//	//constexpr auto vec = create_vector();	// 编译期间就生成1, 2, 3
//	//constexpr string s1("111111111111");
//	//constexpr vector<int> v1(10, 1);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//constexpr int safe_divide(int a, int b) {
//	try {
//		if (b == 0)
//			throw "Division by zero";
//		else
//			return a / b;
//	}
//	catch (...) {
//		return -1; // 编译期异常处理
//	}
//}
//int main()
//{
//	constexpr int val1 = safe_divide(10, 2); // 5
//	//constexpr int val2 = safe_divide(10, 0); // 报错
//}


//constexpr union Data {
//	int i;
//	float f;
//	constexpr Data(int val) : i(val) {} // 初始化整数成员
//	constexpr Data(float val) : f(val) {} // 初始化浮点成员
//};
//
//int main()
//{
//	constexpr Data d1(42); // 活跃成员是i
//	constexpr Data d2(3.14f); // 活跃成员是f
//	//constexpr float temp = d1.f; // 错误：访问非活跃成员（编译失败）
//	//constexpr int temp = d1.i;
//	return 0;
//}

//class A {
//	mutable int _i;			// 使用mutable修饰
//	int _j;
//public:
//	constexpr A(int i, int j)
//		:_i(i)
//		, _j(j)
//	{
//	}
//
//	constexpr int Func() const
//	{
//		++_i; // 可以修改
//		// ++_j; // 不能修改
//		return _i + _j;
//	}
//};
//int main()
//{
//	constexpr A aa(1, 1);
//	constexpr int ret = aa.Func();
//	return 0;
//}
//class Base {
//public:
//	virtual constexpr int value() const { return 1; }
//};
//
//class Derived : public Base {
//public:
//	constexpr int value() const override { return 2; }
//};
//
//constexpr int get_value(const Base& b) {
//	return b.value(); // 编译期多态调用
//}
//
//int main() 
//{
//	constexpr int ret1 = get_value(Base());
//	constexpr int ret2 = get_value(Derived());
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int& ri = i;
//	const int ci = 42;		// 顶层const
//	int* const p1 = &i;		// 顶层const
//	const int* p2 = &ci;	// 底层const
//	const int& ri1 = ci;	// 底层const
//	const int& ri2 = i;		// 底层const
//
//	auto j = ri;			// j类型为int
//	j++;
//	auto k = i;				// k类型为int
//	k++;
//	auto r1 = ci;			// r1类型为int，忽略掉顶层const
//	r1++;
//	auto r2 = p1;			// r2类型为int*，忽略掉顶层const
//	r2++;
//	auto r3 = p2;			// r3类型为const int*，保留底层const
//	// (*r3)++;				// 报错
//	auto r4 = ri1;			// r4类型为int，因为ri1是ci的别名，ci本身的const是一个顶层const被忽略掉了
//	r4++;
//	auto r5 = ri2;			// r5类型为int
//	r5++;
//	const auto r7 = ci;		// r7类型为const int
//	auto& r8 = ri1;			// r8类型为const int&
//	auto& r9 = ri2;			// r9类型为const int&
//	auto& r10 = ci;			// r10类型为const int&
//	auto& r11 = ri;			// r11类型为int&
//	//r7++;					// 报错
//	//r8++;					// 报错
//	//r9++;					// 报错
//	//r10++;				// 报错
//	r11++;
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//void func(int& x)
//{
//	cout << "void func(int& x)" << endl;
//}
//void func(int&& x)
//{
//	cout << "void func(int&& x)" << endl;
//}
//void func(const int& x)
//{
//	cout << "void func(const int& x)" << endl;
//}
//void func(const int&& x)
//{
//	cout << "void func(const int&& x)" << endl;
//}
//int main()
//{
//	int x = 10;
//	const int cx = 20;
//	auto& rx1 = x; // int&
//	auto& rx2 = cx; // const int&
//	func(rx1);
//	func(rx2);
//	const auto& rx3 = x; // const int&
//	const auto& rx4 = cx; // const int&
//	func(rx3);
//	func(rx4);
//
//	// 万能引用
//	auto&& rx5 = x; // int&
//	auto&& rx6 = cx; // const int&
//	func(rx5);
//	func(rx6);
//	auto&& rx7 = move(x); // int&&
//	//rx7++;
//	auto&& rx8 = move(cx); // const int&&
//	//rx8++;
//	func(forward<int>(rx7));
//	func(forward<const int>(rx8));
//	return 0;
//}

//#include <map>
//#include <vector>
//
//// 1. 复杂返回类型
//auto getComplexType() -> std::map<std::string, std::vector<int>> {
//	// ...
//}
//
//// 2. 依赖参数类型的返回类型
//template <typename T, typename U>
//auto add(T t, U u) -> decltype(t + u) {
//	return t + u;
//}
//
//// 3. lambda表达式
//auto lambda = [](int x) -> double { return x * 1.5; };


//int main()
//{
//	int i = 0;
//	const int ci = 0;
//	const int& rci = ci;
//	decltype(i) m = 1; // m的类型是int
//	decltype(ci) x = 1; // x的类型是const int
//	m++;
//	x++; // 报错
//	decltype(rci) y = x; // y的类型是const int&
//	y++; // 报错
//	decltype(rci) z; // 报错
//	int* p1 = &i;
//	decltype(p1) p2 = nullptr; // p2的类型是int*
//	// 特殊处理
//	decltype(*p1) r1 = i; // r1的类型是int&，解引用表达式推导出的内容是引用
//	decltype(i) r2; // r2的类型是int
//	decltype((i)) r3 = i; // r3的类型是int&, (i)是一个表达式，变量是一种可以赋值特殊表达式，所以会推出引用类型
//	return 0;
//}

//#include <vector>
//template <typename T>
//class A
//{
//public:
//	void func(T& container)
//	{
//		_it = container.begin();
//	}
//private:
//	// typename T::iterator _it; // 这里不确定是iterator还是const_iterator，也不能使用auto
//	
//	// 使用decltype推导就可以很好的解决问题，这里的begin不会真正调用
//	decltype(T().begin()) _it;
//};
//int main()
//{
//	const vector<int> v1;
//	A<const vector<int>> obj1;
//	obj1.func(v1);
//
//	vector<int> v2;
//	A<vector<int>> obj2;
//	obj2.func(v2);
//	return 0;
//}

#include <vector>
#include <list>
using namespace std;
//template<class R, class Iter>
//R Func(Iter it1, Iter it2)
//{
//	R x = *it1;
//	++it1;
//	while (it1 != it2)
//	{
//		x += *it1;
//		++it1;
//	}
//	return x;
//}
//
////不支持这样写，因为C++是前置语法，编译器遇到对象只会向前搜索
//template<class Iter>
//decltype(*it1) Func(Iter it1, Iter it2)
//{
//	auto& x = *it1;
//	++it1;
//	while (it1 != it2)
//	{
//		x += *it1;
//		++it1;
//	}
//	return x;
//}
//
////返回位置用auto，函数后面接->推导返回类型的位置返回值方式
////要注意decltype(*it1)推导出的是引用类型
//template<class Iter>
//auto Func(Iter it1, Iter it2) -> decltype(*it1)
//{
//	auto& x = *it1;
//	++it1;
//	while (it1 != it2)
//	{
//		x += *it1;
//		++it1;
//	}
//	return x;
//}
//
//int main()
//{
//	vector<int> v = { 1,2,3 };
//	list<string> lt = { "111","222","333" };
//	// 这里无法调用上面的函数，因为函数模板只能通过实参推导模板类型，无法推导R
//	auto ret1 = Func(v.begin(), v.end());
//	auto ret2 = Func(lt.begin(), lt.end());
//
//	// 显示实例化能解决问题，但是调用就很麻烦
//	auto ret3 = Func<decltype(*v.begin())>(v.begin(), v.end());
//	auto ret4 = Func<decltype(*lt.begin())>(lt.begin(), lt.end());
//	cout << ret3 << endl;
//	cout << ret4 << endl;
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int& ri = i;
//	const int ci = 42;		// 顶层const
//	int* const p1 = &i;		// 顶层const
//	const int* p2 = &ci;	// 底层const
//	auto j = ri;			// j类型为int
//	decltype(auto) j1 = ri; // j1类型为int&
//	++j1;
//	auto r1 = ci;			// r1类型为int，忽略掉顶层const
//	decltype(auto) rr1 = ci;// rr1类型为const int
//	r1++;
//	//rr1++;
//	auto r2 = p1;			// r2类型为int*，忽略掉顶层const
//	decltype(auto) rr2 = p1;// rr1类型为int* const
//	r2++;
//	//rr2++;
//	auto r3 = p2;			// r3类型为const int*，保留底层const
//	decltype(auto) rr3 = p2;// rr3类型为const int*
//	// (*rr3)++;
//	return 0;
//}


//#include <map>
//#include <string>
//using namespace std;
//
//// typedef map<string, int> CountMap;
//// typedef map<string, string> DictMap;
//// typedef int DateType;
//// typedef void (*Callback)(int);
//
//// using 兼容typedef的用法
//using CountMap = map<string, int>;
//using DictMap = map<string, string>;
//using STDateType = int;
//using Callback = void (*)(int);
//
//// using支持带模板参数的类型重定义
//template<class Val>
//using Map = map<string, Val>;
//
//template<class Val>
//using MapIter = typename map<string, Val>::iterator;
//int main()
//{
//	Map<int> countMap;
//	Map<string> dictMap;
//	MapIter<int> cit = countMap.begin();
//	MapIter<string> dit = dictMap.begin();
//	return 0;
//}

//enum class EnumName : UnderlyingType {
//	enumerator1,
//	enumerator2,
//	// ...
//};


//// 使用enum是不可以这样定义的，enum值是暴露到全局的，Red存在冲突
//enum class Color { Red, Green, Blue };
//enum class TrafficLight { Red, Yellow, Green };
//
//// 指定底层类型
//enum class SmallEnum : uint8_t { Value1, Value2 }; // 8位存储
//enum class BigEnum : uint32_t { Value1, Value2 }; // 32位存储
//
//int main()
//{
//	Color c1 = Color::Red; // 正确
//	//Color c2 = Red; // 错误, enum是可以的
//	//int i = Color::Red; // 错误：不能隐式转换，enum是可以的
//	int j = static_cast<int>(Color::Red); // 正确：显式转换
//	// C++20支持
//	using enum Color; // 引入Color枚举值到当前作用域
//	Color c = Red; // 现在可以直接使用
//	return 0;
//}


//// 1、类型检查
//template<typename T>
//void process(T value) {
//	static_assert(std::is_integral<T>::value, "T must be an integral type");
//	// 函数实现...
//}
//// 2、编译时常量验证
//constexpr int buffer_size = 1024;
//static_assert(buffer_size > 0, "Buffer size must be positive");
//static_assert(buffer_size % 4 == 0, "Buffer size must be divisible by 4"); '
//// 3、平台或架构检查
//static_assert(sizeof(void*) == 8, "This code requires 64-bit platform");
//// 4、类型大小验证
//static_assert(sizeof(int) == 4, "int must be 4 bytes");

//#include <tuple>
//int main() {
//	// 创建一个包含3个元素的tuple: int, double, string
//	std::tuple<int, double, std::string> t1(10, 3.14, "hello");
//
//	// 使用make_tuple自动推导类型
//	auto t2 = std::make_tuple(20, 2.718, "world");
//	
//	// C++17起可以使用类模板参数推导
//	std::tuple t3(30, 1.618, "cpp"); // 自动推导为tuple<int, double, const char* 
//	return 0;
//}

//#include <tuple>
//int main() {
//	// 创建一个包含3个元素的tuple: int, double, string
//	std::tuple<int, double, std::string> t1(10, 3.14, "hello");
//
//	// 通过索引访问
//	std::cout << std::get<0>(t1) << std::endl; 
//	std::cout << std::get<1>(t1) << std::endl; 
//	std::cout << std::get<2>(t1) << std::endl << std::endl;
//	
//	// 修改
//	std::get<0>(t1) = 100; // 修改第一个元素
//
//	// C++14起可以通过类型访问(类型必须唯一)
//	std::cout << std::get<int>(t1) << std::endl;
//	std::cout << std::get<double>(t1) << std::endl;
//	return 0;
//}

//int main()
//{
//	int x; 
//	double y;
//	std::string z;
//
//	std::tuple<int, double, std::string> t1(10, 3.14, "hello");
//	// 使用std::tie解包
//	std::tie(x, y, z) = t1;
//	// C++17结构化绑定
//	auto& [a, b, c] = t1;
//	return 0;
//}

//template <unsigned int N>
//struct Factorial {
//	static const unsigned int value = N * Factorial<N - 1>::value;
//};
//
//// 终止条件特化
//template <>
//struct Factorial<0> {
//	static const unsigned int value = 1;
//};
//
//int main()
//{
//	constexpr unsigned int fact5 = Factorial<5>::value; // 编译时计算出120
//	return 0;
//}

//namespace lsl
//{
//// 主模板
//template<typename T>
//struct is_pointer {
//	static constexpr bool value = false;
//};
//
//// 针对指针类型的偏特化
//template<typename T>
//struct is_pointer<T*> {
//	static constexpr bool value = true;
//};
//
//// 主模板，默认情况类型不同
//template<typename T, typename U>
//struct is_same {
//	static constexpr bool value = false;
//};
//
//// 特化版本，当两个类型相同时
//template<typename T>
//struct is_same<T, T> {
//	static constexpr bool value = true;
//};
//
//// 移除 const
//// 主模板，默认情况下不改变类型
//template <typename T>
//struct remove_const {
//	using type = T;
//};
//
//// 针对 const T 的特化版本，移除 const
//template <typename T>
//struct remove_const<const T> {
//	using type = T;
//};
//
//// 移除 指针
//template <typename T>
//struct remove_pointer {
//	using type = T;
//};
//
//template <typename T>
//struct remove_pointer<T*> {
//	using type = T;
//};
//
//template <typename T>
//struct remove_pointer<T* const> {
//	using type = T;
//};
//
//void func()
//{
//	static_assert(is_pointer<int*>::value, "int* is a pointer");
//	static_assert(lsl::is_pointer<int>::value, "int is not a pointer");
//	static_assert(is_same<int, int>::value, "int and int should be the same");
//	static_assert(is_same<int, float>::value, "int and float should be different");
//	static_assert(is_same<remove_pointer<int*>::type, int>::value, "int and int should be the same");
//	static_assert(is_same<remove_const<const int>::type, int>::value, "int and int should be the same");
//}
//}
//
//int main()
//{
//	lsl::func();
//	return 0;
//}

//
//template<typename T>
//void process(T value) {
//	if constexpr (std::is_pointer_v<T>) {
//		// 指针类型的处理
//		std::cout << "Processing pointer: " << *value << std::endl;
//	}
//	else if constexpr (std::is_integral_v<T>) {
//		// 整数类型的处理
//		std::cout << "Processing integer: " << value * 2 << std::endl;
//	}
//	else if constexpr (std::is_floating_point_v<T>) {
//		// 浮点类型的处理
//		std::cout << "Processing float: " << value / 2.0 << std::endl;
//	}
//	else {
//		// 默认处理
//		std::cout << "Processing unknown type" << std::endl;
//	}
//}

//
//int main()
//{
//	// 使用
//	int i = 42;
//	process(i);					// Processing integer: 84
//	process(&i);				// Processing pointer: 42
//	process(3.14);				// Processing float: 1.57
//	process("hello");			// Processing pointer: h
//	process(string("world"));	// Processing unknown type
//	return 0;
//}

// 版本1：仅适用于可递增的类型（如 int）
/*
template<typename T>
auto foo(T x) -> decltype(++x, void()) {
	std::cout << "foo(T): " << x << " (can be incremented)\n";
}
*/

// C++17 使用void_t优化上面的写法
//template<typename T>
//auto foo(T x) -> std::void_t<decltype(++x)> {
//	std::cout << "foo(T): " << x << " (can be incremented)\n";
//}
//
//// 版本2：回退版本
//void foo(...) {
//	std::cout << "foo(...): fallback (cannot increment)\n";
//}
//
//int main() 
//{
//	foo(42);					// 调用版本1（int 支持 ++x）
//	foo(std::string("1111"));	// 调用版本2（string 不支持 ++x）
//	return 0;
//}


//#include <type_traits>
//// 对于整数类型启用此重载
//template<typename T>
//typename std::enable_if_t<std::is_integral_v<T>, T>
//
//add_one(T t) {
//	return t + 1;
//}
//
//// 对于浮点类型启用此重载
//template<typename T>
//typename std::enable_if_t<std::is_floating_point_v<T>, T>
//add_one(T t) {
//	return t + 2.0;
//}
//
//// 模板参数的检查
//template<typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
//void process_integer(T value) {
//	// 只接受整数类型
//}
//
//int main() 
//{
//	std::cout << add_one(5) << "\n";		// 调用整数版本，输出6
//	std::cout << add_one(3.14) << "\n";		// 调用浮点版本，输出4.14
//	//add_one("hello");					// 编译错误，没有匹配的重载
//	process_integer(1);
//	//process_integer(1.1);				// 编译错误，没有匹配的重载
//	return 0;
//}

//template<typename T>
//constexpr T pi = T(3.1415926535897932385);
//
//template<class T >
//constexpr bool is_integral_v = is_integral<T>::value;
//
//template <typename T>
//auto process(T value) {
//	if constexpr (std::is_integral_v<T>) {
//		return value * 2;
//	}
//	else if constexpr (std::is_floating_point_v<T>) {
//		return value / 2;
//	}
//	else {
//		return value;
//	}
//}
//
//int main() 
//{
//	process(1);
//	process(1.1);
//
//	float f = pi<float>; // 单精度π
//	double x = pi<double>; // 双精度π
//	
//	// 使用不同精度的π
//	std::cout.precision(6);
//	std::cout << "float π: " << f << std::endl;
//
//	std::cout.precision(10);
//	std::cout << "double π: " << x << std::endl;
//	return 0;
//}

//// 定义一个要求T是整形的概念
//template< class T >
//concept Integral = std::is_integral_v<T>;
//
//// 1、模板参数后直接使用
//template<Integral T>
//void f1(T x)
//{
//	std::cout << "有 concepts 约束" << std::endl;
//}
//
//int main()
//{
//	f1(1);
//	return 0;
//}

//template<class T>
//constexpr T pi = T(3.1415926535897932385L); // 变量模板
//
//template<class T>
//T circular_area(T r) // 函数模板
//{
//	return pi<T> *r * r; // pi<T> 是变量模板实例化
//}
//
//template<std::size_t N>
//constexpr std::size_t factorial = N * factorial<N - 1>;
//
//// 特化
//template<>
//constexpr std::size_t factorial<0> = 1;
//
//template<class T>
//constexpr bool is_const_v = is_const<T>::value;
//
//int main() 
//{
//	// 使用不同精度的π
//	std::cout.precision(6);
//	std::cout << "float π: " << pi<float> << std::endl;
//
//	std::cout.precision(10);
//	std::cout << "double π: " << pi<double> << std::endl;
//
//	std::cout.precision(6);
//	float radius1 = 2.5;
//	std::cout << "半径为 " << radius1 << " 的圆面积: " << circular_area(radius1) << std::endl;
//	std::cout.precision(10);
//
//	double radius2 = 2.5;
//	std::cout << "半径为 " << radius2 << " 的圆面积: " << circular_area(radius2) << std::endl;
//	std::cout << factorial<5> << std::endl;
//	std::cout << factorial<10> << std::endl;
//	return 0;
//}

//int main() 
//{
//	// 另一个泛型Lambda示例 - 返回两个参数中较大的一个
//	auto getMax = [](const auto& a, const auto& b) {
//		return a > b ? a : b;
//	};
//	
//	std::cout << "最大整数: " << getMax(10, 20) << std::endl;
//	std::cout << "最大字符串: " << getMax(std::string("apple"), std::string("banana")) << std::endl;
//
//	// 这里参数写成auto&&时类似引用折叠部分讲的万能引用
//	// 实参是左值就是左值引用，实参是右值就是右值引用
//	auto func = [](auto&& x, auto& y) {
//		x += 97;
//		y += 97;
//	};
//	
//	int i = 0, j = 1;
//	func(10, i);
//	func(j, i);
//	std::string s1("hello worldxxxxxxxxxxxx");
//	func(move(s1), i);
//	func(s1, i);
//	
//	// 也可以写成这样带可变模板参数的写法
//	std::vector<std::string> v;
//	auto f1 = [&v](auto&&... ts) {
//			v.emplace_back(std::forward<decltype(ts)>(ts)...);
//	};
//	f1(move(s1));
//	f1("1111111");
//	f1(10, 'y');
//	for (auto& e : v)
//		std::cout << e << " ";
//	return 0;
//}

//int main() 
//{
//	std::vector<int> numbers = { 1, 2, 3, 4, 5 };
//	// 使用表达式初始化捕获的变量
//	auto p = std::make_unique<int>(10);
//	auto lambda1 = [value = 5, ptr = std::move(p), &numbers]() {
//		std::cout << "捕获的值: " << value << std::endl;
//		std::cout << "捕获的智能指针值: " << *ptr << std::endl;
//		std::cout << "捕获的vector大小: " << numbers.size() << std::endl;
//	};
//	lambda1();
//	
//	// 另一个例子 - 在捕获时计算值
//	int x = 10;
//	auto lambda2 = [y = x * 2]() {
//		std::cout << "y = x * 2 = " << y << std::endl;
//	};
//	lambda2();
//	return 0;
//}

int main() 
{
	// 泛型 lambda，operator() 是一个拥有两个（模板）形参的模板
	auto glambda = []<class T>(T a, auto&& b) { return a < b; };

	// 泛型 lambda，operator() 是一个拥有一个形参包的模板
	std::vector<std::string> v;
	auto f2 = [&v]<typename... Args>(Args&&... ts) {
		v.emplace_back(std::forward<Args>(ts)...);
	};
	std::string s1("hello wrold");
	f2(s1);
	f2("1111111");
	f2(10, 'y');
	for (auto& e : v)
		std::cout << e << " ";
	return 0;
}