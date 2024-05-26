#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//
//int main()
//{
//	int a, b, c, str;
//	
//	// ����Ԫ��ѭ������ 
//	while(cin>>a) 
//	{ 
//		// ... 
//	} 
//	// ���Ԫ��ѭ������ 
//	while(c>>a>>b>>c) 
//	{ 
//		// ... 
//	} 
//	// ���н��� 
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
		// ����������д�ģ���������_yearΪ0�������
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
	//out << d._year << "��" << d._month << "��" << d._day<<"��";
	//out << d._year << "/" << d._month << "/" << d._day;
	out << d._year << " " << d._month << " " << d._day;

	return out;
}

// C++ IO����ʹ���������+��������صķ�ʽ
// �ܸ��õļ����Զ������ͣ������������ȡ
//int main()
//{
//	// �Զ�ʶ�����͵ı���--��������
//	// �������Ϳ���ֱ��ʹ��--��Ϊ������ostream�����Ѿ�ʵ����
//	int i = 1;
//	double j = 2.2;
//	cout << i << endl;
//	cout << j << endl;
//
//	// �Զ�����������Ҫ�����Լ�����<< �� >>
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

// �����ƶ�д
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
		// д��ofstream
		ofstream ofs(_filename, ofstream::out | ofstream::binary);
		ofs.write((char*)&winfo, sizeof(winfo));
		ofs.close();
	}

	void Read(const ServerInfo& rinfo)
	{
		// ����ifstream
		ifstream ifs(_filename, ifstream::in | ifstream::binary);
		ifs.read((char*)&rinfo, sizeof(rinfo));
		ifs.close();
	}

private:
	string _filename;
};


// һ�����̶�д
//int main()
//{
//	// ������д�ļ�
//	ServerInfo winfo = { "192.168.1.1", 12.13, { 2022, 4, 10 } };
//	BinIO bin;
//	bin.Write(winfo);
//
//	// ���ļ�
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

// д����
//int main()
//{
//	// ������д�ļ�
//	ServerInfo winfo = { "192.168.1.1", 12.13, { 2022, 4, 10 } };
//	BinIO bin;
//	bin.Write(winfo);
//
//	return 0;
//}


// ������
//int main()
//{
//	// ���ļ�
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



// �ı���д
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

// д
//int main()
//{
//	ServerInfo winfo = { "192.168.1.1", 12.13, { 2022, 4, 10 } };
//
//	TextIO text;
//	text.Write(winfo);
//
//	return 0;
//}

// ��
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
//	// C���Եķ�ʽƴ��
//	char sql1[128];
//	char name[10];
//	scanf("%s", name);
//
//	sprintf(sql1, "select * from t_scroe where name = '%s'", name);
//	printf("%s\n", sql1);
//
//	// C++�ķ�ʽƴ��
//	string sql2;
//	sql2 += "select * from t_scroe where name = '";
//	sql2 += name;
//	sql2 += "'";
//	cout << sql2 << endl;
//
//	// ʹ��ostringstream����һ���ֿ�д
//	Date d(2024, 1, 19);
//	ostringstream oss;
//	oss << d;
//	string sql3;
//	sql3 += "select * from t_data where date = '";
//	sql3 += oss.str();
//	sql3 += "'";
//	cout << sql3 << endl;
//
//	// ʹ��ostringstream��������ֱ��д
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
//	// ��һ�����α���ת��Ϊ�ַ������洢��string�������
//	stringstream s;
//	s << a;
//	s >> sa;
//	// clear()
//	// ע����ת��ʱ������ʹ��clear���ϴ�ת��״̬��յ�
//	// stringstreams��ת����βʱ(�����һ��ת����),�Ὣ���ڲ�״̬����Ϊbadbit
//	// �����һ��ת���Ǳ������clear()��״̬����Ϊgoodbit�ſ���ת��
//	// ����clear()���Ὣstringstreams�ײ��ַ�����յ�
//	// s.str("");
//	// ��stringstream�ײ����string�������ó�"",
//	// ������ת��ʱ���Ὣ���ȫ���ۻ��ڵײ�string������
//	s.str("");
//	s.clear(); // ���s, ����ջ�ת��ʧ��
//	double d = 12.34;
//	s << d;
//	s >> sa;
//	string sValue;
//	sValue = s.str(); // str()����������stringsteam�й����string����
//	cout << sValue << endl;
//	return 0;
//}



struct ChatInfo
{
	string _name; // ����
	int _id;      // id
	Date _date;   // ʱ��
	string _msg;  // ������Ϣ
};

int main()
{
	ChatInfo winfo = { "����", 135246, { 2022, 4, 10 }, "����һ�𿴵�Ӱ��" };
	stringstream oss;
	oss << winfo._name << endl;
	oss << winfo._id << endl;
	oss << winfo._date << endl;
	oss << winfo._msg << endl;
	cout << oss.str() << endl;

	// �������
	ChatInfo rinfo;
	string str = oss.str();
	stringstream iss(str);
	iss >> rinfo._name;
	iss >> rinfo._id;
	iss >> rinfo._date;
	iss >> rinfo._msg;

	cout << "-------------------------------------------------------" << endl;
	cout << "������" << rinfo._name << "(" << rinfo._id << ") ";
	cout << rinfo._date << endl;
	cout << rinfo._name << ":>" << rinfo._msg << endl;
	cout << "-------------------------------------------------------" << endl;

	return 0;
}