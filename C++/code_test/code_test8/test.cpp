#include <iostream>
#include <memory>

using namespace std;

//class A {
//public:
//	A() { cout << "A()" << endl; }
//	~A() { cout << "~A()" << endl; }
//	weak_ptr<A> next;
//};
//
//
//int main() {
//	shared_ptr<A> a(new A());
//	shared_ptr<A> b(new A());
//	a->next = b;
//	cout << a.use_count() << endl;
//	cout << b.use_count() << endl;
//	b->next = a;
//
//	cout << a.use_count() << endl;
//	cout << b.use_count() << endl;
//
//	return 0;
//}

//#include <atomic>
//#include <functional>
//
//namespace lsl {
//template<class T>
//class shared_ptr {
//public:
//	explicit shared_ptr(T* ptr = nullptr)
//		: ptr_(ptr), count_(new atomic<int>(1)) {
//		cout << "shared_ptr(T* ptr)" << endl;
//	}
//	
//	shared_ptr(const shared_ptr& sp)
//		: ptr_(sp.ptr_), count_(sp.count_)
//	{
//		cout << "shared_ptr(const shared_ptr& sp)" << endl;
//		++(*count_);
//	}
//
//	template<class Deleter>
//	explicit shared_ptr(T* ptr, Deleter del)
//		: ptr_(ptr), count_(new atomic<int>(1)), deleter_(del) {
//		cout << "shared_ptr(T* ptr = nullptr, Deleter del)" << endl;
//	}
//
//
//	//sp1 = sp2;
//	shared_ptr<T>& operator=(const shared_ptr<T>& sp) {
//		cout << "shared_ptr<T>& operator=(const shared_ptr<T>& sp)" << endl;
//		if (this != &sp) {
//			release();	// 把当前的资源释放掉
//			ptr_ = sp.ptr_;
//			count_ = sp.count_;
//			deleter_ = sp.deleter_;
//			++(*count_);
//		}
//		return *this;
//	}
//	T* get() const { return ptr_; }
//	int use_count() const { return *count_; }
//
//	T& operator*() { return *ptr_; }
//	T* operator->() { return ptr_; }
//
//	void release() {
//		if (--(*count_) == 0) {
//            cout << "release resource" << endl;
//			//delete ptr_;
//			deleter_(ptr_);
//			delete count_;
//			ptr_ = nullptr;
//			count_ = nullptr;
//		}
//	}
//
//	~shared_ptr() {
//		cout << "~shared_ptr()" << endl;
//		release();
//	}
//private:
//	T* ptr_;
//	atomic<int>* count_;
//	function<void(T*)> deleter_ = [](T* ptr) { delete ptr; };
//};
//}
//
//int main() {
//	lsl::shared_ptr<int> sp1(new int(10));
//	cout << sp1.get() << endl; // 输出指针地址
//	cout << *sp1 << endl;	// 输出指针指向的值
//	cout << sp1.use_count() << endl; // 输出引用计数
//
//	lsl::shared_ptr<int> sp2 = sp1;	// 调用拷贝构造函数
//	cout << sp2.get() << endl; // 输出指针地址
//	cout << *sp2 << endl;      // 输出指针指向的值
//	cout << sp2.use_count() << endl; // 输出引用计数
//	
//	// 测试自定义删除器
//    auto custom_deleter = [](int* ptr) {
//        cout << "Custom deleter called for value: " << *ptr << endl;
//        delete ptr;
//    };
//
//	lsl::shared_ptr<int> sp3(new int(100), custom_deleter); // 使用自定义删除器
//	cout << sp3.use_count() << endl;
//
//	return 0;
//}

#include <thread>
#include <vector>

//int main() { 
//    vector<std::thread> v;
//    for (int i = 0; i < 1000; ++i) {
//        v.emplace_back(thread([i]() {
//            this_thread::sleep_for(chrono::seconds(1));
//            cout << "thread - " << i << endl; })
//        );
//    }
//
//    for (int i = 0; i < 1000; ++i) {
//		v[i].join();
//    }
//	return 0; 
//}

#include <mutex>

//class XMutex {
//public:
//	XMutex(mutex& mtx) : mtx_(mtx) { mtx.lock(); }
//	~XMutex() { mtx_.unlock(); }
//private:
//	std::mutex& mtx_;
//};

//timed_mutex tmux;
//void ThreadMainTime(int i)
//{
//	for (;;)
//	{
//		if (!tmux.try_lock_for(chrono::milliseconds(1000)))
//		{
//			cout << i << "[try_lock_for] timeout" << endl;
//			continue;
//		}
//		cout << i << "[in]" << endl;
//		this_thread::sleep_for(chrono::milliseconds(2000));
//		tmux.unlock();
//		this_thread::sleep_for(chrono::milliseconds(1));
//	}
//}
//int main(int argc, char* argv[])
//{
//	for (int i = 0; i < 3; i++) {
//		thread th(ThreadMainTime, i);
//		th.detach();
//	}
//
//	getchar();
//	return 0;
//}

//recursive_mutex rmux;
//void Task1() {
//  rmux.lock();
//  // 组合业务 用到同一个锁
//  cout << "task1 [in]" << endl;
//  rmux.unlock();
//}
//void Task2() {
//  rmux.lock();
//  // 组合业务 用到同一个锁
//  cout << "task2 [in]" << endl;
//  
//  rmux.unlock();
//}
//void ThreadMainRec(int i) {
//  for (;;) {
//    rmux.lock();
//    // 组合业务 用到同一个锁
//    Task1();
//    Task2();
//    cout << i << "[in]" << endl;
//    this_thread::sleep_for(chrono::milliseconds(2000));
//    rmux.unlock();
//    this_thread::sleep_for(chrono::milliseconds(1));
//  }
//}
//
//int main(int argc, char* argv[]) {
//  for (int i = 0; i < 3; i++) {
//    thread th(ThreadMainRec, i);
//    th.detach();
//  }
//
//  getchar();
//}

#include <shared_mutex>

//// c++17
//shared_mutex smux;
//// c++ 14
//shared_timed_mutex stmux;
//void ThreadWrite(int i) {
//  for (;;) {
//    stmux.lock_shared(); // 获取共享锁
//    // 读数据
//    stmux.unlock_shared();
//    stmux.lock();        // 获取互斥锁   
//    cout << i << " Write" << endl;
//    this_thread::sleep_for(chrono::milliseconds(100));
//    stmux.unlock();
//    this_thread::sleep_for(chrono::milliseconds(3000));
//  }
//}
//
//void ThreadRead(int i) {
//  for (;;) {
//    stmux.lock_shared();
//    cout << i << " Read" << endl;
//    this_thread::sleep_for(chrono::milliseconds(500));
//    stmux.unlock_shared();
//    this_thread::sleep_for(chrono::milliseconds(50));
//  }
//}
//int main(int argc, char *argv[]) {
//  for (int i = 0; i < 3; i++) {
//    thread th(ThreadWrite, i + 1);
//    th.detach();
//  }
//  this_thread::sleep_for(chrono::milliseconds(100));
//  for (int i = 0; i < 3; i++) {
//    thread th(ThreadRead, i + 1);
//    th.detach();
//  }
//  getchar();
//}

#include <future>

//void TestFuture(promise<string> ps) { 
//  ps.set_value("TestFuture value");
//}
//int main() {
//  promise<string> p;
//  auto fu = p.get_future();  // std::future<string>
//  auto re = std::thread(TestFuture, move(p));
//  cout << "fu = " << fu.get() << endl;
//  cout << "end std::async" << endl;
//  re.join();
//  return 0;
//}

#include <future>
#include <iostream>
#include <string>
#include <thread>

//using namespace std;
//string TestPackagedTask(int index) {
//  cout << "begin TestPackagedTask " << index << endl;
//  return "TestPackagedTask return";
//}
//
//int main() {
//  std::packaged_task<string(int)> task(TestPackagedTask);
//  auto result = task.get_future();
//  task(100);
//  cout << "result.get() = " << result.get() << endl;
//
//  return 0;
//}

//string testasy(string str) {
//  cout << "test asy " << str << endl;
//  this_thread::sleep_for(chrono::seconds(3));
//  return str + " in async";
//}
//int main() {
//  // future<string> re =
//  auto re = std::async(testasy, "test");
//  // auto re = std::async(launch::deferred, testasy, "test");
//  cout << "end async" << endl;
//  this_thread::sleep_for(chrono::seconds(1));
//  std::cout << "the future result : " << re.get() << std::endl;
//}