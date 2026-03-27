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

#include <atomic>
#include <functional>

namespace lsl {
template<class T>
class shared_ptr {
public:
	explicit shared_ptr(T* ptr = nullptr)
		: ptr_(ptr), count_(new atomic<int>(1)) {
		cout << "shared_ptr(T* ptr)" << endl;
	}
	
	shared_ptr(const shared_ptr& sp)
		: ptr_(sp.ptr_), count_(sp.count_)
	{
		cout << "shared_ptr(const shared_ptr& sp)" << endl;
		++(*count_);
	}

	template<class Deleter>
	explicit shared_ptr(T* ptr, Deleter del)
		: ptr_(ptr), count_(new atomic<int>(1)), deleter_(del) {
		cout << "shared_ptr(T* ptr = nullptr, Deleter del)" << endl;
	}


	//sp1 = sp2;
	shared_ptr<T>& operator=(const shared_ptr<T>& sp) {
		cout << "shared_ptr<T>& operator=(const shared_ptr<T>& sp)" << endl;
		if (this != &sp) {
			release();	// 把当前的资源释放掉
			ptr_ = sp.ptr_;
			count_ = sp.count_;
			deleter_ = sp.deleter_;
			++(*count_);
		}
		return *this;
	}
	T* get() const { return ptr_; }
	int use_count() const { return *count_; }

	T& operator*() { return *ptr_; }
	T* operator->() { return ptr_; }

	void release() {
		if (--(*count_) == 0) {
            cout << "release resource" << endl;
			//delete ptr_;
			deleter_(ptr_);
			delete count_;
			ptr_ = nullptr;
			count_ = nullptr;
		}
	}

	~shared_ptr() {
		cout << "~shared_ptr()" << endl;
		release();
	}
private:
	T* ptr_;
	atomic<int>* count_;
	function<void(T*)> deleter_ = [](T* ptr) { delete ptr; };
};
}

int main() {
	lsl::shared_ptr<int> sp1(new int(10));
	cout << sp1.get() << endl; // 输出指针地址
	cout << *sp1 << endl;	// 输出指针指向的值
	cout << sp1.use_count() << endl; // 输出引用计数

	lsl::shared_ptr<int> sp2 = sp1;	// 调用拷贝构造函数
	cout << sp2.get() << endl; // 输出指针地址
	cout << *sp2 << endl;      // 输出指针指向的值
	cout << sp2.use_count() << endl; // 输出引用计数
	
	// 测试自定义删除器
    auto custom_deleter = [](int* ptr) {
        cout << "Custom deleter called for value: " << *ptr << endl;
        delete ptr;
    };

	lsl::shared_ptr<int> sp3(new int(100), custom_deleter); // 使用自定义删除器
	cout << sp3.use_count() << endl;

	return 0;
}

