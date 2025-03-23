#pragma once
#include<iostream>
#include<string>
#include<map>


using namespace std;


//
//
//inline int Add(int a, int b)
//{
//	cout << "int Add(int a, int b)" << endl;
//
//	return a + b;
//}
//
//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//
//public:
//	void Init(int year, int month, int day);
//	void print();
//	
//};


typedef int DataType;

class Stack
{

private:
	// 成员变量
	DataType* _array;
	size_t _capacity;
	size_t _size;

public:	
	// 成员函数
	void Init(size_t capacity = 4);
	void Push(const DataType& data);
	DataType Top();
	void Destroy();
};
