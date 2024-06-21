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
//
//void Print(size_t n, const string& s)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		cout << this_thread::get_id() << s << ":" << i << endl;
//	}
//}
//
//int main()
//{
//	size_t n;
//	cin >> n;
//
//	//创建n个线程执行Print
//	vector<thread> vthd(n);
//	size_t j = 0;
//	for (auto& thd : vthd)
//	{
//		// 移动赋值
//		thd = thread(Print, 10,  "线程" + to_string(j++));
//	}
//
//	for (auto& thd : vthd)
//	{
//		thd.join();
//	}
//
//	return 0;
//}

#include <mutex>
//
//int main()
//{
//	int n1 = 0;
//	int n2 = 0;
//	cin >> n1 >> n2;
//	mutex mtx;
//
//	int x = 0;
//	thread t1([n1, &x,&mtx]()
//		{
//			for (size_t i = 0; i < n1; i++)
//			{
//				mtx.lock();
//				++x;
//				mtx.unlock();
//			}
//		});
//
//	thread t2([n2, &x, &mtx]()
//		{
//			for (size_t i = 0; i < n2; i++)
//			{
//				mtx.lock();
//				++x;
//				mtx.unlock();
//			}
//		});
//
//	t1.join();
//	t2.join();
//	cout << x << endl;
//
//	return 0;
//}



//void Print1(size_t n, const string& s, mutex& m, int& rx)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		m.lock();
//
//		cout << this_thread::get_id() << s << ":" << i << endl;
//		++rx;
//
//		m.unlock();
//
//		this_thread::sleep_for(chrono::milliseconds(300));
//	}
//}
//
//int main()
//{
//	mutex mtx;
//	int x = 0;
//	// 这里的参数首先是传给构造，然后再传给Print1，所以要加ref()
//	thread t1(Print1, 100, "Thread 1", ref(mtx), ref(x));
//	thread t2(Print1, 200, "thread 2", ref(mtx), ref(x));
//
//
//	cout << "线程1：" << t1.get_id() << endl;
//	cout << "线程2：" << t2.get_id() << endl;
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}



//lock_guard
//unique_lock 
//a、可以跟time_mutex配合使用
//b、支持手动解锁，再加锁


//#include <thread>
//#include <mutex>
//int number = 0;
//mutex g_lock;
//int ThreadProc1()
//{
//	for (int i = 0; i < 100; i++)
//	{
//		g_lock.lock();
//		++number;
//		cout << "thread 1 :" << number << endl;
//		g_lock.unlock();
//	}
//	return 0;
//}
//int ThreadProc2()
//{
//	for (int i = 0; i < 100; i++)
//	{
//		g_lock.lock();
//		--number;
//		cout << "thread 2 :" << number << endl;
//		g_lock.unlock();
//	}
//	return 0;
//}
//
//
//int main()
//{
//	thread t1(ThreadProc1);
//	thread t2(ThreadProc2);
//	t1.join();
//	t2.join();
//	cout << "number:" << number << endl;
//	return 0;
//}

#include <thread>
#include <mutex>
#include <condition_variable>



//int main()
//{
//	std::mutex mtx;
//	// 条件变量
//	condition_variable c;
//	int x = 1;
//
//	// 标志默认为false
//	bool flag = false;
//	thread t1([&] {
//			for (size_t i = 0; i < 10; i++)
//			{
//				// 使用unique_lock管理锁
//				unique_lock<mutex> lock(mtx);
//			
//				// 如果flag == true就进行等待
//				//if (flag)
//				while (flag) // 使用while更保险
//					c.wait(lock); // 在wait的时候会自动解锁
//
//				// 必定第一次执行
//				cout << "thread 1:" << this_thread::get_id() << ":" << x << endl;
//				++x;
//
//				// 执行一次后flag变为true，下次线程再来执行的时候就会进行等待
//				flag = true;
//				// 唤醒线程2
//				c.notify_one();
//			}
//		});
//
//	thread t2([&]{
//			for (size_t i = 0; i < 10; i++)
//			{
//				// 使用unique_lock管理锁
//				unique_lock<mutex> lock(mtx);
//
//				// 如果flag == false就等待 true就开始执行下面的代码
//				//if (!flag)
//				while (!flag) // 使用while更保险
//					c.wait(lock); // 在wait的时候会自动解锁
//
//				cout << "thread 2:" << this_thread::get_id() << ":" << x << endl;
//				++x;
//				
//				// 执行完成后改成false，如果线程2再来执行的时候就会进行等待
//				flag = false;
//				// 唤醒线程1
//				c.notify_one();
//			}
//		}
//	);
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}

#include <atomic>
//int main()
//{
//	size_t n1 = 10000000;
//	size_t n2 = 10000000;
//	mutex mtx;
//
//	// size_t x = 0;	  // 不是原子的
//	atomic<size_t> x = 0; // 使用atomic是原子的
//	thread t1([&]() {
//			for (size_t i = 0; i < n1; i++)
//			{
//				++x;
//			}
//		});
//
//	thread t2([&]() {
//			for (size_t i = 0; i < n2; i++)
//			{
//				++x;
//			}
//		});
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//	// printf("%d\n", x);		// 无法打印
//	printf("%d\n", x.load());
//
//	return 0;
//}

int main()
{
	size_t n1 = 10000;
	size_t n2 = 10000;
	mutex mtx;

	atomic<size_t> x = 0;
	thread t1([&]() {
			for (size_t i = 0; i < n1; i++)
			{
				size_t old, newval;
				do
				{
					old = x;
					newval = old + 2;
				} while (!atomic_compare_exchange_weak(&x, &old, newval));
			}
		});

	thread t2([&]() {
			for (size_t i = 0; i < n2; i++)
			{
				size_t old, newval;
				do
				{
					old = x;
					newval = old + 2;
				} while (!atomic_compare_exchange_weak(&x, &old, newval));
			}
		});

	t1.join();
	t2.join();

	cout << x << endl;

	return 0;
}