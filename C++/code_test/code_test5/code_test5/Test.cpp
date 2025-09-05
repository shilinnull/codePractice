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
//	// 创建一个shared_ptr，指向一个MyClass对象  
//	std::shared_ptr<MyClass> shared = std::make_shared<MyClass>();
//
//	// 创建一个weak_ptr，它是对shared_ptr所管理对象的弱引用  
//	std::weak_ptr<MyClass> weak = shared;
//
//	// shared = nullptr;
//
//	// 尝试调用weak_ptr指向的对象的方法  
//	if (auto locked = weak.lock()) {
//		// 如果lock()返回一个有效的shared_ptr，那么对象仍然存在  
//		// 可以通过这个shared_ptr来调用对象的方法  
//		locked->doSomething();
//	}
//	else {
//		// 如果lock()返回一个空的shared_ptr，那么对象已经被删除  
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
//    //这里编译有错误，如何修改？
//    f1(std::move(a2));
//}
//
//int main()
//{
//    std::unique_ptr<A> spA(new A());
//    //这里编译有错误，如何修改？
//    f2(std::move(spA));
//
//    return 0;
//}

//#include <iostream>
//#include <future>
//#include <thread>
//
//int compute() {
//    // 模拟耗时计算
//    std::cout << "into compute\n";
//    std::this_thread::sleep_for(std::chrono::seconds(2));
//    return 42;
//}
//
//int main() {
//    // 启动异步任务
//    //std::future<int> fut = std::async(std::launch::async, compute); // 异步
//    std::future<int> fut = std::async(std::launch::deferred, compute); // 同步
//    std::this_thread::sleep_for(std::chrono::seconds(1));
//    // 在主线程做其他工作...
//    std::cout << "==========\n";
//
//    // 获取结果（如果还没完成，会阻塞等待）
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
//    // 模拟耗时计算
//    std::cout << "into compute\n";
//    std::this_thread::sleep_for(std::chrono::seconds(2));
//    return 42;
//}
//
//int main() {
//    // 1. 封装任务
//    auto task = std::make_shared<std::packaged_task<int()>>(compute);
//    
//    // 2. 获取任务包关联的任务对象
//    std::future<int> res = task->get_future();
//
//    std::thread thr([task]() {
//        (*task)();
//        });
//    // 3. 获取结果
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
    // 模拟耗时计算
    std::cout << "into compute\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;
}

int main() {
    // 1. 实例化一个promise对象
    std::promise<int> pro;

    // 2. 获取关联的future对象
    std::future<int> res = pro.get_future();

    // 3. 在任意位置给promise设置数据，就可以通过关联的future获取到这个设置的数据了
    std::thread thr([&pro]() {
        int sum = compute();
        pro.set_value(sum);
        });

    // 4. 获取结果
    std::cout << res.get() << std::endl;
    thr.join();
    return 0;
}


