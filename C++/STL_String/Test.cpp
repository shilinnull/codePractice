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
	// ����reserve�Ƿ��ı�string����ЧԪ�ظ���
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// ����reserve����С��string�ĵײ�ռ��Сʱ���Ƿ�Ὣ�ռ���С
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
	// ע�⣺string�����֧��ֱ����cin��cout������������
	string s("hello, world!!!");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	// ��s�е��ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// ��s����Ч�ַ��������ӵ�10�������λ����'a'�������
	// ��aaaaaaaaaa��
	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// ��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'�������
	// "aaaaaaaaaa\0\0\0\0\0"
	// ע���ʱs����Ч�ַ������Ѿ����ӵ�15��
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	// ��s����Ч�ַ�������С��5��
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
	
	// ��capacity��С��size��Сһ����
	s1.shrink_to_fit();
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;
}


////////////////////////////////////////////////////////////////
// string�ı���
// begin()+end()   for+[]  ��Χfor
// ע�⣺string����ʱʹ�����Ļ���for+�±� ���� ��Χfor(C++11���֧��)
// begin()+end()�����ʹ������Ҫʹ��STL�ṩ���㷨����stringʱ�����磺����reverse����string

void Teststring7()
{
	string s1("hello world");
	const string s2("Hello world");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	cout << s1 << endl;

	// s2[0] = 'h';   �������ʧ�ܣ���Ϊconst���Ͷ������޸�
}

void Teststring6()
{
	string s("hello world");
	// 1. for+operator[]
	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i] << ' ';
	cout << endl;

	// 2.������
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;


	// string::reverse_iterator rit = s.rbegin();
	// C++11֮��ֱ��ʹ��auto������������ñ������Ƶ�������������
	auto rit = s.rbegin();
	while (rit != s.rend()) {
		cout << *rit << ' ';
		++rit;
	}
	cout << endl;


	// 3.��Χfor
	for (auto ch : s)
		cout << ch << ' ';
	cout << endl;

}

//////////////////////////////////////////////////////////////
// ����string��
// 1. ����(ƴ��)��ʽ��push_back  append  operator+= 
// 2. ����ͷ�����ң�find() + rfind()
// 3. ��ȡ�Ӵ���substr()
// 4. ɾ����erase
void Teststring8()
{
	string str;
	str.push_back(' ');   // ��str�����ո�
	str.append("hello");  // ��str��׷��һ���ַ�"hello"
	str += 'b';           // ��str��׷��һ���ַ�'b'   
	str += "it";          // ��str��׷��һ���ַ���"it"
	cout << str << endl;
	cout << str.c_str() << endl;   // ��C���Եķ�ʽ��ӡ�ַ���

	// ��ȡfile�ĺ�׺
	string file("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;

	// npos��string�����һ����̬��Ա����
	// static const size_t npos = -1;

	// ȡ��url�е�����
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;

	// ɾ��url��Э��ǰ׺
	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;
}



int main()
{
	//TestPushBack();
	Teststring8();

	return 0;
}





