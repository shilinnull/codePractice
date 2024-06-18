#include <iostream>
#include <thread>

using namespace std;
//int main()
//{
//	std::thread t1;
//	cout << t1.get_id() << endl;
//	return 0;
//}


//void ThreadFunc(int a)
//{
//	cout << "Thread1" << a << endl;
//}
//class TF
//{
//public:
//	void operator()()
//	{
//		cout << "Thread3" << endl;
//	}
//};
//int main()
//{
//	// 线程函数为函数指针
//	thread t1(ThreadFunc, 10);
//	// 线程函数为lambda表达式
//	thread t2([] {cout << "Thread2" << endl; });
//	// 线程函数为函数对象
//	TF tf;
//	thread t3(tf);
//	t1.join();
//	t2.join();
//	t3.join();
//	cout << "Main thread!" << endl;
//	return 0;
//}

//void ThreadFunc(int a)
//{
//	cout << "Thread" << a << endl;
//}
//
//int main()
//{
//	thread t1(ThreadFunc,1);
//	//thread t2(t1); // 报错
//	thread t2(std::move(t1));
//	t2.join();// 交给t2join
//
//	return 0;
//}

//void ThreadFunc1(int& x)
//{
//	x += 10;
//}
//void ThreadFunc2(int* x)
//{
//	*x += 10;
//}
//int main()
//{
//	int a = 10;
//	// 在线程函数中对a修改，不会影响外部实参，因为：线程函数参数虽然是引用方式，但其实际引用的是线程栈中的拷贝
//	thread t1(ThreadFunc1, a);
//	t1.join();
//	cout << a << endl;
//
//	// 如果想要通过形参改变外部实参时，必须借助std::ref()函数
//	thread t2(ThreadFunc1, std::ref(a));
//	t2.join();
//	cout << a << endl;
//
//	// 地址的拷贝
//	thread t3(ThreadFunc2, &a);
//	t3.join();
//	cout << a << endl;
//	return 0;
//}

#include <vector>
#include <string>

void Print(size_t n, const string& s)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << this_thread::get_id() << s << ":" << i << endl;
	}
}

int main()
{
	size_t n;
	cin >> n;

	//创建n个线程执行Print
	vector<thread> vthd(n);
	size_t j = 0;
	for (auto& thd : vthd)
	{
		// 移动赋值
		thd = thread(Print, 10,  "线程" + to_string(j++));
	}

	for (auto& thd : vthd)
	{
		thd.join();
	}

	return 0;
}
