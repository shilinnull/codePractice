#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

//
//int main()
//{
//	string s1("hello world");
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//
//	string::iterator it1 = s1.begin();
//	while (it1 != s1.end())
//	{
//		cout << *it1 << " ";
//		it1++;
//	}
//	cout << endl;
//
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//
//	list<int>::iterator itt = lt.begin();
//	while (itt != lt.end())
//	{
//		cout << *itt << " ";
//		++itt;
//	}
//	cout << endl;
//
//	for (auto e : s1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	string s0;
//	string s1("hello world");
//	string s2(s1);
//	string s3(s1, 5, 3);
//	string s4(s1, 5, 10);
//	string s5(s1, 5);
//
//	cout << s0 << endl;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//
//	string s6(10, '#');
//	cout << s6 << endl;
//	
//	s0 = s6;
//	cout << s0 << endl;
//	
//	return 0;
//}

//void Test_string1()
//{
//	string s1("hello world");
//	string::reverse_iterator rit = s1.rbegin();
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl; 
//
//	const string s2("hello world");
//	string::const_iterator cit = s2.begin();
//	while (cit != s2.end())
//	{
//		cout << *cit << " ";
//		++cit;
//	}
//	cout << endl;
//}
//void Test_string2()
//{
//	string s1("hello world");
//	cout << s1.max_size() << endl;
//}
//void Test_string3()
//{
//	string s1("hello");
//	cout << s1.capacity() << endl;
//
//	s1.resize(20);
//	// s1.resize(30,'x');
//	// s1.resize(0);
//	cout << s1.capacity() << endl;
//	cout << s1.empty() << endl;
//	s1.shrink_to_fit();
//	cout << s1.capacity() << endl;
//
//
//	cout << s1.capacity() << endl;
//	cout << s1.size() << endl;
//
//	string s2("world");
//	s1.swap(s2);
//	cout << s2 << endl;
//
//}




void Teststring1()
{
	string s1("hello world");
	//cout << s1.size() << endl;
	//cout << s1.length() << endl;
	//cout << s1.max_size() << endl;
	cout << s1.capacity() << endl;
}

void Teststring2()
{
	string s;
	// 测试reserve是否会改变string中有效元素个数
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << s.capacity() << endl;
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void Teststring3()
{
	// 注意：string类对象支持直接用cin和cout进行输入和输出
	string s("hello, world!!!");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	// 将s中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// 将s中有效字符个数增加到10个，多出位置用'a'进行填充
	// “aaaaaaaaaa”
	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
	// "aaaaaaaaaa\0\0\0\0\0"
	// 注意此时s中有效字符个数已经增加到15个
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	// 将s中有效字符个数缩小到5个
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}

void Teststring4()
{
	string s1("hello");
	string s2;
	string s3("");

	cout << s1.empty() << endl;
	cout << s2.empty() << endl;
	cout << s3.empty() << endl;

}

void Teststring5()
{
	string s1("hello");
	s1.reserve(30);
	s1.resize(30, 'c');
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;
	
	// 将capacity缩小到size大小一样大
	s1.shrink_to_fit();
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;
}


////////////////////////////////////////////////////////////////
// string的遍历
// begin()+end()   for+[]  范围for
// 注意：string遍历时使用最多的还是for+下标 或者 范围for(C++11后才支持)
// begin()+end()大多数使用在需要使用STL提供的算法操作string时，比如：采用reverse逆置string

void Teststring7()
{
	string s1("hello world");
	const string s2("Hello world");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	cout << s1 << endl;

	// s2[0] = 'h';   代码编译失败，因为const类型对象不能修改
}

void Teststring6()
{
	string s("hello world");
	// 1. for+operator[]
	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i] << ' ';
	cout << endl;

	// 2.迭代器
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;


	// string::reverse_iterator rit = s.rbegin();
	// C++11之后，直接使用auto定义迭代器，让编译器推到迭代器的类型
	auto rit = s.rbegin();
	while (rit != s.rend()) {
		cout << *rit << ' ';
		++rit;
	}
	cout << endl;


	// 3.范围for
	for (auto ch : s)
		cout << ch << ' ';
	cout << endl;

}

//////////////////////////////////////////////////////////////
// 测试string：
// 1. 插入(拼接)方式：push_back  append  operator+= 
// 2. 正向和反向查找：find() + rfind()
// 3. 截取子串：substr()
// 4. 删除：erase
void Teststring8()
{
	string str;
	str.push_back(' ');   // 在str后插入空格
	str.append("hello");  // 在str后追加一个字符"hello"
	str += 'w';           // 在str后追加一个字符'w'   
	str += "orld";          // 在str后追加一个字符串"orld"
	cout << str << endl;
	cout << str.c_str() << endl;   // 以C语言的方式打印字符串
	cout << str.data() << endl;
	
	string s1("hello");
	string s2 = s1;
	if (s1 == s2)
		cout << "True" << endl;
	else
		cout << "False" << endl;

	if (s1.c_str() == s2.c_str())
		cout << "True" << endl;
	else
		cout << "False" << endl;

	// 获取file的后缀
	string file("string.cpp");
	// 从后往前找 '.'
	size_t pos = file.rfind('.');
	// 截取从pos位置开始到最后
	string suffix(file.substr(pos,file.size() - pos));
	cout << suffix << endl;

	// 取出url中的协议
	string url("https://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;

	size_t n = url.find(':');
	if (n == string::npos)
	{
		cout << "invalid url" << endl;
		return;
	}
	string protocol = url.substr(0, n);
	cout << protocol << endl;
	cout << url.substr(0, n) << endl;


	// 取出url中的域名
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return;
	}
	start += 3; // 跳过 ://
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;
	cout << url.substr(start, finish - start) << endl;

	// 删除url的协议前缀
	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;


	//string str("Please, replace the vowels in this sentence by asterisks.");
	//cout << str << endl;

	//size_t found = str.find_first_not_of("aeiou");
	//while (found != string::npos)
	//{
	//	str[found] = '*';
	//	found = str.find_first_not_of("aeiou", found + 1);
	//}
	//cout << str << endl;

}



#include<string.h>
int main()
{
	 //TestPushBack();
	 Teststring8();

	return 0;
}





