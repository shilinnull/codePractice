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
//	// �̺߳���Ϊ����ָ��
//	thread t1(ThreadFunc, 10);
//	// �̺߳���Ϊlambda���ʽ
//	thread t2([] {cout << "Thread2" << endl; });
//	// �̺߳���Ϊ��������
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
//	//thread t2(t1); // ����
//	thread t2(std::move(t1));
//	t2.join();// ����t2join
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
//	// ���̺߳����ж�a�޸ģ�����Ӱ���ⲿʵ�Σ���Ϊ���̺߳���������Ȼ�����÷�ʽ������ʵ�����õ����߳�ջ�еĿ���
//	thread t1(ThreadFunc1, a);
//	t1.join();
//	cout << a << endl;
//
//	// �����Ҫͨ���βθı��ⲿʵ��ʱ���������std::ref()����
//	thread t2(ThreadFunc1, std::ref(a));
//	t2.join();
//	cout << a << endl;
//
//	// ��ַ�Ŀ���
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
//	//����n���߳�ִ��Print
//	vector<thread> vthd(n);
//	size_t j = 0;
//	for (auto& thd : vthd)
//	{
//		// �ƶ���ֵ
//		thd = thread(Print, 10,  "�߳�" + to_string(j++));
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
//	// ����Ĳ��������Ǵ������죬Ȼ���ٴ���Print1������Ҫ��ref()
//	thread t1(Print1, 100, "Thread 1", ref(mtx), ref(x));
//	thread t2(Print1, 200, "thread 2", ref(mtx), ref(x));
//
//
//	cout << "�߳�1��" << t1.get_id() << endl;
//	cout << "�߳�2��" << t2.get_id() << endl;
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
//a�����Ը�time_mutex���ʹ��
//b��֧���ֶ��������ټ���


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
//	// ��������
//	condition_variable c;
//	int x = 1;
//
//	// ��־Ĭ��Ϊfalse
//	bool flag = false;
//	thread t1([&] {
//			for (size_t i = 0; i < 10; i++)
//			{
//				// ʹ��unique_lock������
//				unique_lock<mutex> lock(mtx);
//			
//				// ���flag == true�ͽ��еȴ�
//				//if (flag)
//				while (flag) // ʹ��while������
//					c.wait(lock); // ��wait��ʱ����Զ�����
//
//				// �ض���һ��ִ��
//				cout << "thread 1:" << this_thread::get_id() << ":" << x << endl;
//				++x;
//
//				// ִ��һ�κ�flag��Ϊtrue���´��߳�����ִ�е�ʱ��ͻ���еȴ�
//				flag = true;
//				// �����߳�2
//				c.notify_one();
//			}
//		});
//
//	thread t2([&]{
//			for (size_t i = 0; i < 10; i++)
//			{
//				// ʹ��unique_lock������
//				unique_lock<mutex> lock(mtx);
//
//				// ���flag == false�͵ȴ� true�Ϳ�ʼִ������Ĵ���
//				//if (!flag)
//				while (!flag) // ʹ��while������
//					c.wait(lock); // ��wait��ʱ����Զ�����
//
//				cout << "thread 2:" << this_thread::get_id() << ":" << x << endl;
//				++x;
//				
//				// ִ����ɺ�ĳ�false������߳�2����ִ�е�ʱ��ͻ���еȴ�
//				flag = false;
//				// �����߳�1
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
//	// size_t x = 0;	  // ����ԭ�ӵ�
//	atomic<size_t> x = 0; // ʹ��atomic��ԭ�ӵ�
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
//	// printf("%d\n", x);		// �޷���ӡ
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