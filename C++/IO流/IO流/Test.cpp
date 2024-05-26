#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//
//int main()
//{
//	int a, b, c, str;
//	
//	// 单个元素循环输入 
//	while(cin>>a) 
//	{ 
//		// ... 
//	} 
//	// 多个元素循环输入 
//	while(c>>a>>b>>c) 
//	{ 
//		// ... 
//	} 
//	// 整行接收 
//	while(cin>>str) 
//	{
//		// ... 
//	}
//
//	istream& operator>> (int& val); 
//	explicit operator bool() const;
//
//	return 0;
//}



class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	operator bool()
	{
		// 这里是随意写的，假设输入_year为0，则结束
		if (_year == 0)
			return false;
		else
			return true;
	}
private:
	int _year;
	int _month;
	int _day;
};

istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

//ofs << winfo._date;
ostream& operator << (ostream& out, const Date& d)
{
	//out << d._year << "年" << d._month << "月" << d._day<<"日";
	//out << d._year << "/" << d._month << "/" << d._day;
	out << d._year << " " << d._month << " " << d._day;

	return out;
}

// C++ IO流，使用面向对象+运算符重载的方式
// 能更好的兼容自定义类型，流插入和流提取
//int main()
//{
//	// 自动识别类型的本质--函数重载
//	// 内置类型可以直接使用--因为库里面ostream类型已经实现了
//	int i = 1;
//	double j = 2.2;
//	cout << i << endl;
//	cout << j << endl;
//
//	// 自定义类型则需要我们自己重载<< 和 >>
//	Date d(2022, 4, 10);
//	cout << d;
//	while (d)
//	{
//		cin >> d;
//		cout << d;
//	}
//
//	return 0;
//}

// 二进制读写
#include<fstream>

struct ServerInfo
{
	// char _address[32];

	string _address;
	double _x;

	Date _date;
};

class BinIO
{
public:
	BinIO(const char* filename = "info.bin")
		:_filename(filename)
	{}

	void Write(const ServerInfo& winfo)
	{
		// 写是ofstream
		ofstream ofs(_filename, ofstream::out | ofstream::binary);
		ofs.write((char*)&winfo, sizeof(winfo));
		ofs.close();
	}

	void Read(const ServerInfo& rinfo)
	{
		// 读是ifstream
		ifstream ifs(_filename, ifstream::in | ifstream::binary);
		ifs.read((char*)&rinfo, sizeof(rinfo));
		ifs.close();
	}

private:
	string _filename;
};


// 一个进程读写
//int main()
//{
//	// 二进制写文件
//	ServerInfo winfo = { "192.168.1.1", 12.13, { 2022, 4, 10 } };
//	BinIO bin;
//	bin.Write(winfo);
//
//	// 读文件
//	ServerInfo rinfo;
//	BinIO bin;
//	bin.Read(rinfo);
//
//	cout << rinfo._address << endl;
//	cout << rinfo._x << endl;
//	cout << rinfo._date << endl;
//
//	return 0;
//}

// 写操作
//int main()
//{
//	// 二进制写文件
//	ServerInfo winfo = { "192.168.1.1", 12.13, { 2022, 4, 10 } };
//	BinIO bin;
//	bin.Write(winfo);
//
//	return 0;
//}


// 读操作
//int main()
//{
//	// 读文件
//	ServerInfo rinfo;
//	BinIO bin;
//	bin.Read(rinfo);
//
//	cout << rinfo._address << endl;
//	cout << rinfo._x << endl;
//	cout << rinfo._date << endl;
//
//	return 0;
//}



// 文本读写
class TextIO
{
public:
	TextIO(const char* filename = "info.text")
		:_filename(filename)
	{}

	void Write(const ServerInfo& winfo)
	{
		ofstream ofs(_filename);
		ofs << winfo._address << endl;
		ofs << winfo._x << endl;
		ofs << winfo._date << endl;
	}

	void Read(ServerInfo& rinfo)
	{
		ifstream ifs(_filename);
		ifs >> rinfo._address;
		ifs >> rinfo._x;
		ifs >> rinfo._date;
	}

private:
	string _filename;
};

// 写
//int main()
//{
//	ServerInfo winfo = { "192.168.1.1", 12.13, { 2022, 4, 10 } };
//
//	TextIO text;
//	text.Write(winfo);
//
//	return 0;
//}

// 读
//int main()
//{
//	ServerInfo info;
//	TextIO text;
//	text.Read(info);
//
//	cout << info._address << endl;
//	cout << info._x << endl;
//	cout << info._date << endl;
//
//	return 0;
//}


#include<sstream>
//int main()
//{
//	// C语言的方式拼接
//	char sql1[128];
//	char name[10];
//	scanf("%s", name);
//
//	sprintf(sql1, "select * from t_scroe where name = '%s'", name);
//	printf("%s\n", sql1);
//
//	// C++的方式拼接
//	string sql2;
//	sql2 += "select * from t_scroe where name = '";
//	sql2 += name;
//	sql2 += "'";
//	cout << sql2 << endl;
//
//	// 使用ostringstream方法一：分开写
//	Date d(2024, 1, 19);
//	ostringstream oss;
//	oss << d;
//	string sql3;
//	sql3 += "select * from t_data where date = '";
//	sql3 += oss.str();
//	sql3 += "'";
//	cout << sql3 << endl;
//
//	// 使用ostringstream方法二：直接写
//	ostringstream sqloss;
//	sqloss << "select * from t_data where date = '"<< d << "'";
//	cout << sqloss.str() << endl;
//
//	return 0;
//}


//int main()
//{
//	int n = 123456789;
//	char s1[32];
//	_itoa(n, s1, 10);
//	char s2[32];
//	sprintf(s2, "%d", n);
//	char s3[32];
//	sprintf(s3, "%f", n);
//	return 0;
//}



//int main()
//{
//	int a = 12345678;
//	string sa;
//	// 将一个整形变量转化为字符串，存储到string类对象中
//	stringstream s;
//	s << a;
//	s >> sa;
//	// clear()
//	// 注意多次转换时，必须使用clear将上次转换状态清空掉
//	// stringstreams在转换结尾时(即最后一个转换后),会将其内部状态设置为badbit
//	// 因此下一次转换是必须调用clear()将状态重置为goodbit才可以转换
//	// 但是clear()不会将stringstreams底层字符串清空掉
//	// s.str("");
//	// 将stringstream底层管理string对象设置成"",
//	// 否则多次转换时，会将结果全部累积在底层string对象中
//	s.str("");
//	s.clear(); // 清空s, 不清空会转化失败
//	double d = 12.34;
//	s << d;
//	s >> sa;
//	string sValue;
//	sValue = s.str(); // str()方法：返回stringsteam中管理的string类型
//	cout << sValue << endl;
//	return 0;
//}



struct ChatInfo
{
	string _name; // 名字
	int _id;      // id
	Date _date;   // 时间
	string _msg;  // 聊天信息
};

int main()
{
	ChatInfo winfo = { "张三", 135246, { 2022, 4, 10 }, "晚上一起看电影吧" };
	stringstream oss;
	oss << winfo._name << endl;
	oss << winfo._id << endl;
	oss << winfo._date << endl;
	oss << winfo._msg << endl;
	cout << oss.str() << endl;

	// 网络输出
	ChatInfo rinfo;
	string str = oss.str();
	stringstream iss(str);
	iss >> rinfo._name;
	iss >> rinfo._id;
	iss >> rinfo._date;
	iss >> rinfo._msg;

	cout << "-------------------------------------------------------" << endl;
	cout << "姓名：" << rinfo._name << "(" << rinfo._id << ") ";
	cout << rinfo._date << endl;
	cout << rinfo._name << ":>" << rinfo._msg << endl;
	cout << "-------------------------------------------------------" << endl;

	return 0;
}