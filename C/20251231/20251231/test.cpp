#include <iostream>
using namespace std;


// 模拟shared_ptr
template<class T>
class MySharedPtr {
public:
	MySharedPtr(T* ptr)
		:_ptr(ptr),
		_count(new int(1)){ }

	MySharedPtr(const MySharedPtr<T>& s)
		:_ptr{ s._ptr },
		_count(s._count) {
		(*_count)++;
	}
	~MySharedPtr() {
		Release();
	}
	void Release() {
		if (--(*_count) == 0)
		{
			std::cout << "释放了" << std::endl;
			delete _ptr;
			delete _count;
		}
	}
	MySharedPtr<T>& operator=(MySharedPtr<T>& s) {
		if (_ptr != s._ptr) {
			Release();
			_ptr = s._ptr;
			_count = s._count;
			(*_count)++;
		}
		return *this;
	}

	T& operator* () {
		return *_ptr;
	}

	T* operator->() {
		return _ptr;
	}

	T* get() const {
		return _ptr;
	}

private:
	T* _ptr;
	int* _count;
};

//int main() {
//	MySharedPtr<int> p(new int(10));
//	MySharedPtr<int> p1 = p;
//	MySharedPtr<int> p2(p);
//	cout << *p << endl;
//	cout << *p1 << endl;
//	cout << *p2 << endl;
//
//	return 0;
//}

// 两个线程交替打印1 - 100


#include <Thread>
#include <mutex>

int main() {
	
	std::mutex mtx;
	condition_variable cv;
	bool flag = false;
	int i = 1, n = 100;

	thread t1([&] {
		while (i < n) {
			unique_lock<std::mutex> lock(mtx);
			while (flag) cv.wait(lock);
			cout << "thread1: " << i++ << endl;
			flag = true;
			cv.notify_one();
		}
		});

	thread t2([&] {
		while (i < n) {
			unique_lock<std::mutex> lock(mtx);
			while (!flag) cv.wait(lock);
			cout << "thread2: " << i++ << endl;
			flag = false;
			cv.notify_one();
		}
		});

	t1.join();
	t2.join();

	return 0;
}


