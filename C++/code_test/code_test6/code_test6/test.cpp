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
//	int* const p1 = &i;		// ����const
//	
//	const int ci = 111;		// ����const
//	const int* p2 = &ci;	// �ײ�const
//	const int& r = ci;		// �ײ�const
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
//	const int a = 1;		// a�ǳ������ʽ
//	const int b = a + 1;	// b�ǳ������ʽ
//	int c = 1;				// c���ǳ������ʽ
//	const int d = c;		// d���ǳ������ʽ
//	const int e = size();	// e���ǳ������ʽ
//	
//	// �������ʽ�����������С��vs��֧�ֱ䳤���飬�������������С�����Ǳ���ʱȷ�ϵ�
//	int arr[a];
//	constexpr int aa = 1;
//	constexpr int bb = aa + 1;
//
//	//constexpr int cc = c;				// ����
//	//constexpr int cc = size();		// ����
//	//constexpr int* p1 = &d;			// ����Ȩ�޷Ŵ��ˣ�constexpr���ε���p1����
//
//	const int* p2 = &d;
//	constexpr const int* p3 = &d;		// constexpr���ε���p1����const����*p3
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
//	// ����ʱ��N�ᱻֱ���滻Ϊ10��constexpr����Ĭ�Ͼ���inline
//	constexpr int N1 = size();
//	int arr1[N1];
//	// func��10ʱ��func��������ֵ�ǳ������ʽ������N2�ǳ������ʽ
//	constexpr int N2 = func(10);
//	int arr2[N2];
//	
//	int i = 10;
//	constexpr int N3 = func(i); // ����func���صĲ��ǳ������ʽ
//	int N4 = func(i); // ������constexpr�������صĲ�һ�ǳ������ʽ
//
//	constexpr int fact5 = factorial(5); // ����ʱ����
//	
//	// constexpr���εĺ���������һЩ������䣬������Щ�������ʱ���Բ�ִ���κβ����Ϳ���
//	// �����ͱ���������䡢using������
//	constexpr int N5 = fxx(10); // ����
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
//	// constexpr Date d0(x, 9, 8); // ���� ����ʹ�ó������г�ʼ��
//	constexpr Date d1(2000, 1, 1);
//	constexpr int y = d1.GetYear();
//
//	Date d2(2000, 1, 1);
//	int z = d2.GetYear();
//	string ret1 = Func("111111"); // ��ͨ����
//	constexpr int ret2 = Func(10);
//	return 0;
//}

// C++14�����constexpr����ʾ��
//constexpr int factorial(int n) {
//	int res = 1; // ����ֲ�����
//	for (int i = 2; i <= n; ++i) { // ����ѭ��
//		res *= i;
//	}
//	return res; // ��һ return
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
//	constexpr size_t len = stringLength("Hello"); // �����ڼ��㣺5
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
//		return *t; // ����TΪָ������ʱʵ����
//	}
//	else {
//		return t; // ��ָ������ʱʵ����
//	}
//}
//
//int main()
//{
//	int x = 42;
//	auto v1 = get_value(x);		// ����x����
//	auto v2 = get_value(&x);	// �����÷���42
//	return 0;
//}

//int main()
//{
//	// constexpr lambdaʾ��
//	constexpr int n = 10;
//	int y = 0;
//	constexpr auto square = [n](int x) constexpr { return x * x * n; };
//	constexpr int result = square(5); // �����ڼ��㣺250
//	return 0;
//}

//constexpr int dynamic_memory_example() {
//	int* p = new int{ 42 }; // �����ڷ���
//	int value = *p;
//	delete p; // ������ʽ�ͷ�
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
//	std::vector<int> v{ 1, 2, 3 }; // �����ڹ���
//	v.push_back(4); // �����ڲ���
//	return v;
//}
//
//constexpr auto sort_example() {
//	std::array<int, 5> arr{ 5, 3, 4, 1, 2 };
//	std::sort(arr.begin(), arr.end()); // ����������
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
//	// �������֧�ֵ�constexpr
//	constexpr auto sorted = sort_example(); // {1,2,3,4,5}
//	constexpr auto it2 = find(a1.begin(), a1.end(), 4);
//	static_assert(*it2 == 4, "�����ڲ���");
//
//	//constexpr auto vec = create_vector();	// �����ڼ������1, 2, 3
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
//		return -1; // �������쳣����
//	}
//}
//int main()
//{
//	constexpr int val1 = safe_divide(10, 2); // 5
//	//constexpr int val2 = safe_divide(10, 0); // ����
//}


//constexpr union Data {
//	int i;
//	float f;
//	constexpr Data(int val) : i(val) {} // ��ʼ��������Ա
//	constexpr Data(float val) : f(val) {} // ��ʼ�������Ա
//};
//
//int main()
//{
//	constexpr Data d1(42); // ��Ծ��Ա��i
//	constexpr Data d2(3.14f); // ��Ծ��Ա��f
//	//constexpr float temp = d1.f; // ���󣺷��ʷǻ�Ծ��Ա������ʧ�ܣ�
//	//constexpr int temp = d1.i;
//	return 0;
//}

//class A {
//	mutable int _i;			// ʹ��mutable����
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
//		++_i; // �����޸�
//		// ++_j; // �����޸�
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
//	return b.value(); // �����ڶ�̬����
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
//	const int ci = 42;		// ����const
//	int* const p1 = &i;		// ����const
//	const int* p2 = &ci;	// �ײ�const
//	const int& ri1 = ci;	// �ײ�const
//	const int& ri2 = i;		// �ײ�const
//
//	auto j = ri;			// j����Ϊint
//	j++;
//	auto k = i;				// k����Ϊint
//	k++;
//	auto r1 = ci;			// r1����Ϊint�����Ե�����const
//	r1++;
//	auto r2 = p1;			// r2����Ϊint*�����Ե�����const
//	r2++;
//	auto r3 = p2;			// r3����Ϊconst int*�������ײ�const
//	// (*r3)++;				// ����
//	auto r4 = ri1;			// r4����Ϊint����Ϊri1��ci�ı�����ci�����const��һ������const�����Ե���
//	r4++;
//	auto r5 = ri2;			// r5����Ϊint
//	r5++;
//	const auto r7 = ci;		// r7����Ϊconst int
//	auto& r8 = ri1;			// r8����Ϊconst int&
//	auto& r9 = ri2;			// r9����Ϊconst int&
//	auto& r10 = ci;			// r10����Ϊconst int&
//	auto& r11 = ri;			// r11����Ϊint&
//	//r7++;					// ����
//	//r8++;					// ����
//	//r9++;					// ����
//	//r10++;				// ����
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
//	// ��������
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
//// 1. ���ӷ�������
//auto getComplexType() -> std::map<std::string, std::vector<int>> {
//	// ...
//}
//
//// 2. �����������͵ķ�������
//template <typename T, typename U>
//auto add(T t, U u) -> decltype(t + u) {
//	return t + u;
//}
//
//// 3. lambda���ʽ
//auto lambda = [](int x) -> double { return x * 1.5; };


//int main()
//{
//	int i = 0;
//	const int ci = 0;
//	const int& rci = ci;
//	decltype(i) m = 1; // m��������int
//	decltype(ci) x = 1; // x��������const int
//	m++;
//	x++; // ����
//	decltype(rci) y = x; // y��������const int&
//	y++; // ����
//	decltype(rci) z; // ����
//	int* p1 = &i;
//	decltype(p1) p2 = nullptr; // p2��������int*
//	// ���⴦��
//	decltype(*p1) r1 = i; // r1��������int&�������ñ��ʽ�Ƶ���������������
//	decltype(i) r2; // r2��������int
//	decltype((i)) r3 = i; // r3��������int&, (i)��һ�����ʽ��������һ�ֿ��Ը�ֵ������ʽ�����Ի��Ƴ���������
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
//	// typename T::iterator _it; // ���ﲻȷ����iterator����const_iterator��Ҳ����ʹ��auto
//	
//	// ʹ��decltype�Ƶ��Ϳ��ԺܺõĽ�����⣬�����begin������������
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
////��֧������д����ΪC++��ǰ���﷨����������������ֻ����ǰ����
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
////����λ����auto�����������->�Ƶ��������͵�λ�÷���ֵ��ʽ
////Ҫע��decltype(*it1)�Ƶ���������������
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
//	// �����޷���������ĺ�������Ϊ����ģ��ֻ��ͨ��ʵ���Ƶ�ģ�����ͣ��޷��Ƶ�R
//	auto ret1 = Func(v.begin(), v.end());
//	auto ret2 = Func(lt.begin(), lt.end());
//
//	// ��ʾʵ�����ܽ�����⣬���ǵ��þͺ��鷳
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
//	const int ci = 42;		// ����const
//	int* const p1 = &i;		// ����const
//	const int* p2 = &ci;	// �ײ�const
//	auto j = ri;			// j����Ϊint
//	decltype(auto) j1 = ri; // j1����Ϊint&
//	++j1;
//	auto r1 = ci;			// r1����Ϊint�����Ե�����const
//	decltype(auto) rr1 = ci;// rr1����Ϊconst int
//	r1++;
//	//rr1++;
//	auto r2 = p1;			// r2����Ϊint*�����Ե�����const
//	decltype(auto) rr2 = p1;// rr1����Ϊint* const
//	r2++;
//	//rr2++;
//	auto r3 = p2;			// r3����Ϊconst int*�������ײ�const
//	decltype(auto) rr3 = p2;// rr3����Ϊconst int*
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
//// using ����typedef���÷�
//using CountMap = map<string, int>;
//using DictMap = map<string, string>;
//using STDateType = int;
//using Callback = void (*)(int);
//
//// using֧�ִ�ģ������������ض���
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


//// ʹ��enum�ǲ�������������ģ�enumֵ�Ǳ�¶��ȫ�ֵģ�Red���ڳ�ͻ
//enum class Color { Red, Green, Blue };
//enum class TrafficLight { Red, Yellow, Green };
//
//// ָ���ײ�����
//enum class SmallEnum : uint8_t { Value1, Value2 }; // 8λ�洢
//enum class BigEnum : uint32_t { Value1, Value2 }; // 32λ�洢
//
//int main()
//{
//	Color c1 = Color::Red; // ��ȷ
//	//Color c2 = Red; // ����, enum�ǿ��Ե�
//	//int i = Color::Red; // ���󣺲�����ʽת����enum�ǿ��Ե�
//	int j = static_cast<int>(Color::Red); // ��ȷ����ʽת��
//	// C++20֧��
//	using enum Color; // ����Colorö��ֵ����ǰ������
//	Color c = Red; // ���ڿ���ֱ��ʹ��
//	return 0;
//}


//// 1�����ͼ��
//template<typename T>
//void process(T value) {
//	static_assert(std::is_integral<T>::value, "T must be an integral type");
//	// ����ʵ��...
//}
//// 2������ʱ������֤
//constexpr int buffer_size = 1024;
//static_assert(buffer_size > 0, "Buffer size must be positive");
//static_assert(buffer_size % 4 == 0, "Buffer size must be divisible by 4"); '
//// 3��ƽ̨��ܹ����
//static_assert(sizeof(void*) == 8, "This code requires 64-bit platform");
//// 4�����ʹ�С��֤
//static_assert(sizeof(int) == 4, "int must be 4 bytes");

//#include <tuple>
//int main() {
//	// ����һ������3��Ԫ�ص�tuple: int, double, string
//	std::tuple<int, double, std::string> t1(10, 3.14, "hello");
//
//	// ʹ��make_tuple�Զ��Ƶ�����
//	auto t2 = std::make_tuple(20, 2.718, "world");
//	
//	// C++17�����ʹ����ģ������Ƶ�
//	std::tuple t3(30, 1.618, "cpp"); // �Զ��Ƶ�Ϊtuple<int, double, const char* 
//	return 0;
//}

//#include <tuple>
//int main() {
//	// ����һ������3��Ԫ�ص�tuple: int, double, string
//	std::tuple<int, double, std::string> t1(10, 3.14, "hello");
//
//	// ͨ����������
//	std::cout << std::get<0>(t1) << std::endl; 
//	std::cout << std::get<1>(t1) << std::endl; 
//	std::cout << std::get<2>(t1) << std::endl << std::endl;
//	
//	// �޸�
//	std::get<0>(t1) = 100; // �޸ĵ�һ��Ԫ��
//
//	// C++14�����ͨ�����ͷ���(���ͱ���Ψһ)
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
//	// ʹ��std::tie���
//	std::tie(x, y, z) = t1;
//	// C++17�ṹ����
//	auto& [a, b, c] = t1;
//	return 0;
//}

//template <unsigned int N>
//struct Factorial {
//	static const unsigned int value = N * Factorial<N - 1>::value;
//};
//
//// ��ֹ�����ػ�
//template <>
//struct Factorial<0> {
//	static const unsigned int value = 1;
//};
//
//int main()
//{
//	constexpr unsigned int fact5 = Factorial<5>::value; // ����ʱ�����120
//	return 0;
//}

//namespace lsl
//{
//// ��ģ��
//template<typename T>
//struct is_pointer {
//	static constexpr bool value = false;
//};
//
//// ���ָ�����͵�ƫ�ػ�
//template<typename T>
//struct is_pointer<T*> {
//	static constexpr bool value = true;
//};
//
//// ��ģ�壬Ĭ��������Ͳ�ͬ
//template<typename T, typename U>
//struct is_same {
//	static constexpr bool value = false;
//};
//
//// �ػ��汾��������������ͬʱ
//template<typename T>
//struct is_same<T, T> {
//	static constexpr bool value = true;
//};
//
//// �Ƴ� const
//// ��ģ�壬Ĭ������²��ı�����
//template <typename T>
//struct remove_const {
//	using type = T;
//};
//
//// ��� const T ���ػ��汾���Ƴ� const
//template <typename T>
//struct remove_const<const T> {
//	using type = T;
//};
//
//// �Ƴ� ָ��
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
//		// ָ�����͵Ĵ���
//		std::cout << "Processing pointer: " << *value << std::endl;
//	}
//	else if constexpr (std::is_integral_v<T>) {
//		// �������͵Ĵ���
//		std::cout << "Processing integer: " << value * 2 << std::endl;
//	}
//	else if constexpr (std::is_floating_point_v<T>) {
//		// �������͵Ĵ���
//		std::cout << "Processing float: " << value / 2.0 << std::endl;
//	}
//	else {
//		// Ĭ�ϴ���
//		std::cout << "Processing unknown type" << std::endl;
//	}
//}

//
//int main()
//{
//	// ʹ��
//	int i = 42;
//	process(i);					// Processing integer: 84
//	process(&i);				// Processing pointer: 42
//	process(3.14);				// Processing float: 1.57
//	process("hello");			// Processing pointer: h
//	process(string("world"));	// Processing unknown type
//	return 0;
//}

// �汾1���������ڿɵ��������ͣ��� int��
/*
template<typename T>
auto foo(T x) -> decltype(++x, void()) {
	std::cout << "foo(T): " << x << " (can be incremented)\n";
}
*/

// C++17 ʹ��void_t�Ż������д��
//template<typename T>
//auto foo(T x) -> std::void_t<decltype(++x)> {
//	std::cout << "foo(T): " << x << " (can be incremented)\n";
//}
//
//// �汾2�����˰汾
//void foo(...) {
//	std::cout << "foo(...): fallback (cannot increment)\n";
//}
//
//int main() 
//{
//	foo(42);					// ���ð汾1��int ֧�� ++x��
//	foo(std::string("1111"));	// ���ð汾2��string ��֧�� ++x��
//	return 0;
//}


//#include <type_traits>
//// ���������������ô�����
//template<typename T>
//typename std::enable_if_t<std::is_integral_v<T>, T>
//
//add_one(T t) {
//	return t + 1;
//}
//
//// ���ڸ����������ô�����
//template<typename T>
//typename std::enable_if_t<std::is_floating_point_v<T>, T>
//add_one(T t) {
//	return t + 2.0;
//}
//
//// ģ������ļ��
//template<typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
//void process_integer(T value) {
//	// ֻ������������
//}
//
//int main() 
//{
//	std::cout << add_one(5) << "\n";		// ���������汾�����6
//	std::cout << add_one(3.14) << "\n";		// ���ø���汾�����4.14
//	//add_one("hello");					// �������û��ƥ�������
//	process_integer(1);
//	//process_integer(1.1);				// �������û��ƥ�������
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
//	float f = pi<float>; // �����Ȧ�
//	double x = pi<double>; // ˫���Ȧ�
//	
//	// ʹ�ò�ͬ���ȵĦ�
//	std::cout.precision(6);
//	std::cout << "float ��: " << f << std::endl;
//
//	std::cout.precision(10);
//	std::cout << "double ��: " << x << std::endl;
//	return 0;
//}

//// ����һ��Ҫ��T�����εĸ���
//template< class T >
//concept Integral = std::is_integral_v<T>;
//
//// 1��ģ�������ֱ��ʹ��
//template<Integral T>
//void f1(T x)
//{
//	std::cout << "�� concepts Լ��" << std::endl;
//}
//
//int main()
//{
//	f1(1);
//	return 0;
//}

//template<class T>
//constexpr T pi = T(3.1415926535897932385L); // ����ģ��
//
//template<class T>
//T circular_area(T r) // ����ģ��
//{
//	return pi<T> *r * r; // pi<T> �Ǳ���ģ��ʵ����
//}
//
//template<std::size_t N>
//constexpr std::size_t factorial = N * factorial<N - 1>;
//
//// �ػ�
//template<>
//constexpr std::size_t factorial<0> = 1;
//
//template<class T>
//constexpr bool is_const_v = is_const<T>::value;
//
//int main() 
//{
//	// ʹ�ò�ͬ���ȵĦ�
//	std::cout.precision(6);
//	std::cout << "float ��: " << pi<float> << std::endl;
//
//	std::cout.precision(10);
//	std::cout << "double ��: " << pi<double> << std::endl;
//
//	std::cout.precision(6);
//	float radius1 = 2.5;
//	std::cout << "�뾶Ϊ " << radius1 << " ��Բ���: " << circular_area(radius1) << std::endl;
//	std::cout.precision(10);
//
//	double radius2 = 2.5;
//	std::cout << "�뾶Ϊ " << radius2 << " ��Բ���: " << circular_area(radius2) << std::endl;
//	std::cout << factorial<5> << std::endl;
//	std::cout << factorial<10> << std::endl;
//	return 0;
//}

//int main() 
//{
//	// ��һ������Lambdaʾ�� - �������������нϴ��һ��
//	auto getMax = [](const auto& a, const auto& b) {
//		return a > b ? a : b;
//	};
//	
//	std::cout << "�������: " << getMax(10, 20) << std::endl;
//	std::cout << "����ַ���: " << getMax(std::string("apple"), std::string("banana")) << std::endl;
//
//	// �������д��auto&&ʱ���������۵����ֽ�����������
//	// ʵ������ֵ������ֵ���ã�ʵ������ֵ������ֵ����
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
//	// Ҳ����д���������ɱ�ģ�������д��
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
//	// ʹ�ñ��ʽ��ʼ������ı���
//	auto p = std::make_unique<int>(10);
//	auto lambda1 = [value = 5, ptr = std::move(p), &numbers]() {
//		std::cout << "�����ֵ: " << value << std::endl;
//		std::cout << "���������ָ��ֵ: " << *ptr << std::endl;
//		std::cout << "�����vector��С: " << numbers.size() << std::endl;
//	};
//	lambda1();
//	
//	// ��һ������ - �ڲ���ʱ����ֵ
//	int x = 10;
//	auto lambda2 = [y = x * 2]() {
//		std::cout << "y = x * 2 = " << y << std::endl;
//	};
//	lambda2();
//	return 0;
//}

int main() 
{
	// ���� lambda��operator() ��һ��ӵ��������ģ�壩�βε�ģ��
	auto glambda = []<class T>(T a, auto&& b) { return a < b; };

	// ���� lambda��operator() ��һ��ӵ��һ���βΰ���ģ��
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