#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
#include "queue.h"




//int main()
//{
//    //lsl::stack<int, vector<int>> mystack;
//    //lsl::stack<int, list<int>> mystack;
//    lsl::stack<int> mystack;
//
//    for (int i = 0; i < 5; ++i) 
//        mystack.push(i);
//
//    std::cout << "Popping out elements...";
//    while (!mystack.empty())
//    {
//        std::cout << ' ' << mystack.top();
//        mystack.pop();
//    }
//    std::cout << '\n';
//
//    return 0;
//}

//
//
//int main()
//{
//    // 不支持
//    //lsl::queue<int, vector<int>> myqueue;
//    lsl::queue<int> myqueue;
//    myqueue.push(1);
//    myqueue.push(2);
//    myqueue.push(3);
//    myqueue.push(4);
//
//    std::cout << "myqueue contains: ";
//    while (!myqueue.empty())
//    {
//        std::cout << ' ' << myqueue.front();
//        myqueue.pop();
//    }
//    std::cout << '\n';
//
//    return 0;
//}


#include <vector>
#include <queue>
#include <functional> // greater算法的头文件
//void TestPriorityQueue()
//{
//	// 默认情况下，创建的是大堆，其底层按照小于号比较
//	vector<int> v{ 3,2,7,6,0,4,1,9,8,5 };
//	priority_queue<int> q1;
//	for (auto& e : v)
//		q1.push(e);
//	cout << q1.top() << endl;
//	// 如果要创建小堆，将第三个模板参数换成greater比较方式
//	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
//	cout << q2.top() << endl;
//}


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
	}
	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};

//void TestPriorityQueue()
//{
//	// 大堆，需要用户在自定义类型中提供<的重载
//	priority_queue<Date> q1;
//	q1.push(Date(2025, 10, 29));
//	q1.push(Date(2025, 10, 28));
//	q1.push(Date(2025, 10, 30));
//	cout << q1.top() << endl;
//	// 如果要创建小堆，需要用户提供>的重载
//	priority_queue<Date, vector<Date>, greater<Date>> q2;
//	q2.push(Date(2025, 10, 29));
//	q2.push(Date(2025, 10, 28));
//	q2.push(Date(2025, 10, 30));
//	cout << q2.top() << endl;
//
//}

//struct LessPDate
//{
//	bool operator()(Date* d1, Date* d2)
//	{
//		return *d1 < *d2;
//	}
//};
//struct GreaterPDate
//{
//	bool operator()(Date* d1, Date* d2)
//	{
//		return *d1 > *d2;
//	}
//};
//
//
//void TestPriorityQueue1() {
//
//	// 如果要创建大堆，并且是在堆上创建的，就需要使用仿函数
//	//priority_queue<Date*, vector<Date*>, LessPDate> q1;
//	
//	// 创建小堆
//	priority_queue<Date*, vector<Date*>, GreaterPDate> q1;
//	q1.push(new Date(2025, 10, 29));
//	q1.push(new Date(2025, 10, 28));
//	q1.push(new Date(2025, 10, 30));
//	while (!q1.empty())
//	{
//		std::cout << ' ' << *q1.top();
//		q1.pop();
//	}
//	std::cout << '\n';
//}
//
//int main() {
//	TestPriorityQueue1();
//
//	return 0;
//}

#include "priority_queue.h"

int main()
{
	lsl::priority_queue<int, vector<int>,lsl::Greater<int>> q1;
	q1.push(1);
	q1.push(8);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	while (!q1.empty())
	{
		std::cout << q1.top() << " ";
		q1.pop();
	}
	std::cout << '\n';

	return 0;
}
