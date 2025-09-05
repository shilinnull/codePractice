#include <iostream>

using namespace std;


#include <iostream>  
#include <memory>  

//class MyClass {
//public:
//	void doSomething() {
//		std::cout << "Doing something..." << std::endl;
//	}
//};
//
//int main() {
//	// ����һ��shared_ptr��ָ��һ��MyClass����  
//	std::shared_ptr<MyClass> shared = std::make_shared<MyClass>();
//
//	// ����һ��weak_ptr�����Ƕ�shared_ptr����������������  
//	std::weak_ptr<MyClass> weak = shared;
//
//	// shared = nullptr;
//
//	// ���Ե���weak_ptrָ��Ķ���ķ���  
//	if (auto locked = weak.lock()) {
//		// ���lock()����һ����Ч��shared_ptr����ô������Ȼ����  
//		// ����ͨ�����shared_ptr�����ö���ķ���  
//		locked->doSomething();
//	}
//	else {
//		// ���lock()����һ���յ�shared_ptr����ô�����Ѿ���ɾ��  
//		std::cout << "Object has been deleted!" << std::endl;
//	}
//
//	return 0;
//}


//int main()
//{
//	struct A {
//		int  i;
//		char j;
//	};
//	A a;
//	cout << sizeof(a) << endl;
//
//	int arr[8];
//	int* parr = arr;
//	cout << sizeof(arr) << endl;
//	cout << sizeof(arr[0]) << endl;
//	cout << sizeof("helloworld") << endl;
//
//	char sz[] = "helloworld";
//	char* psz = sz;
//	cout << sizeof(sz) << endl;
//
//
//	return 0;
//}


#include <memory>

//class A {
//
//};
//
//void f1(std::unique_ptr<A>&& a1) {
//
//}
//
//void f2(std::unique_ptr<A>&& a2) {
//    //��������д�������޸ģ�
//    f1(std::move(a2));
//}
//
//int main()
//{
//    std::unique_ptr<A> spA(new A());
//    //��������д�������޸ģ�
//    f2(std::move(spA));
//
//    return 0;
//}

//#include <iostream>
//#include <future>
//#include <thread>
//
//int compute() {
//    // ģ���ʱ����
//    std::cout << "into compute\n";
//    std::this_thread::sleep_for(std::chrono::seconds(2));
//    return 42;
//}
//
//int main() {
//    // �����첽����
//    //std::future<int> fut = std::async(std::launch::async, compute); // �첽
//    std::future<int> fut = std::async(std::launch::deferred, compute); // ͬ��
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    // �����߳�����������...
//    std::cout << "==========\n";
//
//    // ��ȡ����������û��ɣ��������ȴ���
//    int result = fut.get();
//    std::cout << "Result: " << result << std::endl;
//
//    return 0;
//}

//#include <iostream>
//#include <future>
//#include <thread>
//#include <memory>
//
//int compute() {
//    // ģ���ʱ����
//    std::cout << "into compute\n";
//    std::this_thread::sleep_for(std::chrono::seconds(2));
//    return 42;
//}
//
//int main() {
//    // 1. ��װ����
//    auto task = std::make_shared<std::packaged_task<int()>>(compute);
//    
//    // 2. ��ȡ������������������
//    std::future<int> res = task->get_future();
//
//    std::thread thr([task]() {
//        (*task)();
//        });
//    // 3. ��ȡ���
//    std::cout << res.get() << std::endl;
//
//    thr.join();
//    return 0;
//}


#include <iostream>
#include <future>
#include <thread>
#include <memory>

int compute() {
    // ģ���ʱ����
    std::cout << "into compute\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;
}

int main() {
    // 1. ʵ����һ��promise����
    std::promise<int> pro;

    // 2. ��ȡ������future����
    std::future<int> res = pro.get_future();

    // 3. ������λ�ø�promise�������ݣ��Ϳ���ͨ��������future��ȡ��������õ�������
    std::thread thr([&pro]() {
        int sum = compute();
        pro.set_value(sum);
        });

    // 4. ��ȡ���
    std::cout << res.get() << std::endl;
    thr.join();
    return 0;
}


