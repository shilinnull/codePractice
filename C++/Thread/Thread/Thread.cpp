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

	//����n���߳�ִ��Print
	vector<thread> vthd(n);
	size_t j = 0;
	for (auto& thd : vthd)
	{
		// �ƶ���ֵ
		thd = thread(Print, 10,  "�߳�" + to_string(j++));
	}

	for (auto& thd : vthd)
	{
		thd.join();
	}

	return 0;
}
