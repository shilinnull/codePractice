#define _CRT_SECURE_NO_WARNING 1


//#include <iostream>
//#include <thread>
//#include <chrono> 
//
//
//using namespace std;
//
//int main()
//{
//	std::cout << "countdown:\n";
//	for (int i = 10; i > 0; --i) {
//		std::cout << i << std::endl;
//		std::this_thread::sleep_for(std::chrono::seconds(1)); // 休眠一秒
//	}
//	std::cout << "Lift off!\n";
//	return 0;
//}


//// 示例1：
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;
//int main()
//{
//	int x = 0;
//	mutex mtx;
//	// 将上面的代码改成使用lambda捕获外层的对象，也就可以不用传参数，间接解决了上面的问题
//	auto Print = [&x, &mtx](size_t n) {
//		mtx.lock();
//		for (size_t i = 0; i < n; i++)
//		{
//			++x;
//		}
//		mtx.unlock();
//	};
//	
//	thread t1(Print, 1000000);
//	thread t2(Print, 2000000);
//	t1.join();
//	t2.join();
//	cout << x << endl;
//	return 0;
//}
//
//void Print(int n, int& rx, mutex& rmtx)
//{
//	rmtx.lock();
//	for (int i = 0; i < n; i++)
//	{
//		// t1 t2 来进行访问
//		++rx;
//	}
//	rmtx.unlock();
//}
//
//int main()
//{
//	int x = 0;
//	mutex mtx;
//	thread t1(Print, 1000000, ref(x), ref(mtx));
//	thread t2(Print, 2000000, ref(x), ref(mtx));
//	t1.join();
//	t2.join();
//	cout << x << endl;
//	return 0;
//}


#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

//int main()
//{
//	int x = 0;
//	mutex mtx;
//	auto Print = [&x, &mtx](size_t n) {
//
//		{ // 临界区
//			lock_guard<mutex> lock(mtx); // 使用lock_guard进行管理
//			//mtx.lock();
//			for (size_t i = 0; i < n; i++)
//			{
//				++x;
//			}
//			//mtx.unlock();
//		}
//	
//	};
//	thread t1(Print, 1000000);
//	thread t2(Print, 2000000);
//	t1.join();
//	t2.join();
//	cout << x << endl;
//	return 0;
//}



// std::lock example
#include <iostream> // std::cout
//#include <thread> // std::thread
//#include <mutex> // std::mutex, std::lock
//#include <chrono> // std::chrono
//std::mutex foo, bar;
//void task_a() {
//	std::this_thread::sleep_for(std::chrono::seconds(1)); // 休眠一秒
//	//foo.lock(); bar.lock(); // replaced by:
//	std::lock(foo, bar);
//	std::cout << "task a\n";
//	foo.unlock();
//	bar.unlock();
//}
//void task_b() {
//	std::this_thread::sleep_for(std::chrono::seconds(1));
//	//bar.lock(); foo.lock(); // replaced by:
//	std::lock(foo, bar);
//	std::cout << "task b\n";
//	bar.unlock();
//	foo.unlock();
//}
//int main()
//{
//	std::thread th1(task_a);
//	std::thread th2(task_b);
//
//	th1.join();
//	th2.join();
//	return 0;
//}


//#include <iostream>       // std::cout
//#include <thread>         // std::thread
//#include <mutex>          // std::mutex, std::try_lock
//
//std::mutex foo, bar;
//
//void task_a() {
//    foo.lock();
//    std::cout << "task a\n";
//    bar.lock();
//    // ...
//    foo.unlock();
//    bar.unlock();
//}
//
//void task_b() {
//    int x = try_lock(bar, foo);
//    if (x == -1) {
//        std::cout << "task b\n";
//        // ...
//        bar.unlock();
//        foo.unlock();
//    }
//    else {
//        std::cout << "[task b failed: mutex " << (x ? "foo" : "bar") << " locked]\n";
//    }
//}
//
//int main()
//{
//    std::thread th1(task_a);
//    std::thread th2(task_b);
//
//    th1.join();
//    th2.join();
//
//    return 0;
//}



//#include <iostream>       // std::cout
//#include <thread>         // std::thread, std::this_thread::sleep_for
//#include <chrono>         // std::chrono::milliseconds
//#include <mutex>          // std::call_once, std::once_flag
//
//int winner;
//void set_winner(int x) { winner = x; }
//std::once_flag winner_flag;
//
//void wait_1000ms(int id) {
//    // count to 1000, waiting 1ms between increments:
//    for (int i = 0; i < 1000; ++i)
//        std::this_thread::sleep_for(std::chrono::milliseconds(1));
//    // claim to be the winner (only the first such call is executed):
//    std::call_once(winner_flag, set_winner, id);
//}
//
//int main()
//{
//    std::thread threads[10];
//    // spawn 10 threads:
//    for (int i = 0; i < 10; ++i)
//        threads[i] = std::thread(wait_1000ms, i + 1);
//
//    std::cout << "waiting for the first among 10 threads to count 1000 ms...\n";
//
//    for (auto& th : threads) th.join();
//    std::cout << "winner thread: " << winner << '\n';
//
//    return 0;
//}

//#include <atomic>
//#include <iostream>
//#include <thread>
//#include <vector>
//using namespace std;
//atomic<int> acnt;
////atomic_int acnt;
//
//int cnt;
//
//void Add1(atomic<int>& cnt)
//{
//	int old = cnt.load();
//	// 如果cnt的值跟old相等，则将cnt的值设置为old+1，并且返回true，这组操作是原子的。
//	// 那么如果在load和compare_exchange_weak操作之间cnt对象被其他线程改了
//	// 则old和cnt不相等，则将old的值改为cnt的值，并且返回false。
//	while (!atomic_compare_exchange_weak(&cnt, &old, old + 1));
//	//while (!cnt.compare_exchange_weak(old, old + 1));
//}
//void f()
//{
//	for (int n = 0; n < 100000; ++n)
//	{
//		++acnt;
//		// Add1的用CAS模拟atomic的operator++的原子操作
//		// Add1(acnt);
//		++cnt;
//	}
//}
//
//int main()
//{
//	std::vector<thread> pool;
//	for (int n = 0; n < 4; ++n)
//		pool.emplace_back(f);
//	for (auto& e : pool)
//		e.join();
//	cout << "原子计数器为 " << acnt << '\n'
//		<< "非原子计数器为 " << cnt << '\n';
//	return 0;
//}


//struct Date
//{
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//};
//
//template<class T>
//void check()
//{
//	cout << typeid(T).name() << endl;
//	cout << std::is_trivially_copyable<T>::value << endl;
//	cout << std::is_copy_constructible<T>::value << endl;
//	cout << std::is_move_constructible<T>::value << endl;
//	cout << std::is_copy_assignable<T>::value << endl;
//	cout << std::is_move_assignable<T>::value << endl;
//	cout << std::is_same<T, typename std::remove_cv<T>::type>::value << endl << endl;
//}
//
//int main()
//{
//	check<int>();
//	check<double>();
//	check<int*>();
//	check<Date>();
//	check<Date*>();
//	check<string>();
//	check<string*>();
//
//	return 0;
//}


//#include <iostream> // std::cout
//#include <atomic> // std::atomic
//#include <thread> // std::thread
//#include <vector> // std::vector
//// a simple global linked list:
//struct Node { int value; Node* next; };
//std::atomic<Node*> list_head(nullptr);
//void append(int val, int n)
//{
//	//std::this_thread::sleep_for(std::chrono::seconds(1));
//	for (int i = 0; i < n; i++)
//	{
//		// append an element to the list
//		Node* oldHead = list_head;
//		Node* newNode = new Node{ val + i,oldHead };
//		// what follows is equivalent to: list_head = newNode, but in a thread - safe way :
//		while (!list_head.compare_exchange_weak(oldHead, newNode))
//			newNode->next = oldHead;
//	}
//}
//int main()
//{
//	// spawn 10 threads to fill the linked list:
//	std::vector<std::thread> threads;
//	threads.emplace_back(append, 0, 10);
//	threads.emplace_back(append, 20, 10);
//	threads.emplace_back(append, 30, 10);
//	threads.emplace_back(append, 40, 10);
//	for (auto& th : threads)
//		th.join();
//	// print contents:
//	for (Node* it = list_head; it != nullptr; it = it->next)
//		std::cout << ' ' << it->value;
//	std::cout << '\n';
//	// cleanup:
//	Node* it;
//	while (it = list_head)
//	{
//		list_head = it->next;
//		delete it;
//	}
//	return 0;
//}

//#include <iostream> // std::cout
//#include <atomic> // std::atomic
//#include <thread> // std::thread
//#include <mutex> // std::thread
//#include <vector> // std::vector
//template<typename T>
//struct node
//{
//	T data;
//	node* next;
//	node(const T& data) : data(data), next(nullptr) {}
//};
//
//namespace lock_free
//{
//	template<typename T>
//	class stack
//	{
//	public:
//		std::atomic<node<T>*> head = nullptr;
//	public:
//		void push(const T& data)
//		{
//			node<T>* new_node = new node<T>(data);
//			// 将 head 的当前值放到 new_node->next 中
//			new_node->next = head.load(std::memory_order_relaxed);
//			// 现在令 new_node 为新的 head ，但如果 head 不再是
//			// 存储于 new_node->next 的值（某些其他线程必须在刚才插入结点）
//			// 那么将新的 head 放到 new_node->next 中并再尝试
//			while (!head.compare_exchange_weak(new_node->next, new_node,
//				std::memory_order_release,
//				std::memory_order_relaxed))
//				; // 循环体为空
//		}
//	};
//}
//
//namespace lock
//{
//	template<typename T>
//	class stack
//	{
//	public:
//		node<T>* head = nullptr;
//		void push(const T& data)
//		{
//			node<T>* new_node = new node<T>(data);
//			new_node->next = head;
//			head = new_node;
//		}
//	};
//}
//
//
//int main()
//{
//	lock_free::stack<int> st1;
//	lock::stack<int> st2;
//	std::mutex mtx;
//	int n = 1000000;
//	auto lock_free_stack = [&st1, n] {
//		for (size_t i = 0; i < n; i++)
//		{
//			st1.push(i);
//		}
//	};
//	auto lock_stack = [&st2, &mtx, n] {
//		for (size_t i = 0; i < n; i++)
//		{
//			std::lock_guard<std::mutex> lock(mtx);
//			st2.push(i);
//		}
//	};
//
//	// 4个线程分别使用无锁方式和有锁方式插入n个数据到栈中对比性能
//	size_t begin1 = clock();
//	std::vector<std::thread> threads1;
//	for (size_t i = 0; i < 4; i++)
//	{
//		threads1.emplace_back(lock_free_stack);
//	}
//	for (auto& th : threads1)
//		th.join();
//	size_t end1 = clock();
//	std::cout << end1 - begin1 << std::endl;
//	size_t begin2 = clock();
//	std::vector<std::thread> threads2;
//	for (size_t i = 0; i < 4; i++)
//	{
//		threads2.emplace_back(lock_stack);
//	}
//	for (auto& th : threads2)
//		th.join();
//	size_t end2 = clock();
//	std::cout << end2 - begin2 << std::endl;
//	return 0;
//}

//#include <atomic>
//#include <thread>
//#include <iostream>
//#include <vector>
//
//class SpinLock
//{
//private:
//	// ATOMIC_FLAG_INIT默认初始化为false
//	std::atomic_flag flag = ATOMIC_FLAG_INIT;
//public:
//	void lock()
//	{
//		// test_and_set将内部值设置为true，并且返回之前的值
//		// 第一个进来的线程将值原子的设置为true，返回false
//		// 后面进来的线程将原子的值设置为true，返回true，所以卡在这里空转，
//		// 直到第一个进去的线程unlock，clear，将值设置为false
//		while (flag.test_and_set(std::memory_order_acquire));
//	}
//	void unlock()
//	{
//		// clear将值原子的设置为false
//		flag.clear(std::memory_order_release);
//	}
//};
//// 测试自旋锁
//void worker(SpinLock& lock, int& sharedValue) {
//	lock.lock();
//	// 模拟一些工作
//	for (int i = 0; i < 1000000; ++i) {
//		++sharedValue;
//	}
//	lock.unlock();
//}
//
//int main() {
//	SpinLock lock;
//	int sharedValue = 0;
//	std::vector<std::thread> threads;
//	// 创建多个线程
//	for (int i = 0; i < 4; ++i) {
//		threads.emplace_back(worker, std::ref(lock), std::ref(sharedValue));
//	}
//	// 等待所有线程完成
//	for (auto& thread : threads) {
//		thread.join();
//	}
//	std::cout << "Final shared value: " << sharedValue << std::endl;
//	return 0;
//}

// condition_variable::notify_all
//#include <iostream> // std::cout
//#include <thread> // std::thread
//#include <mutex> // std::mutex, std::unique_lock
//#include <condition_variable> // std::condition_variable
//
//std::mutex mtx;
//std::condition_variable cv;
//bool ready = false;
//
//void print_id(int id) {
//	std::unique_lock<std::mutex> lck(mtx);
//	while (!ready)
//		cv.wait(lck);
//	// ...
//	std::cout << "thread " << id << '\n';
//}
//
//void go() {
//	std::unique_lock<std::mutex> lck(mtx);
//	ready = true;
//	// 通知所有阻塞在条件变量上的线程
//	cv.notify_all();
//}
//
//int main()
//{
//	std::thread threads[10];
//	// spawn 10 threads:
//	for (int i = 0; i < 10; ++i)
//		threads[i] = std::thread(print_id, i);
//	std::cout << "10 threads ready to race...\n";
//	std::this_thread::sleep_for(std::chrono::milliseconds(100));
//	go(); // go!
//	for (auto& th : threads)
//		th.join();
//	return 0;
//}


//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//int main()
//{
//    std::mutex mtx;
//    // 条件变量
//    condition_variable c;
//    int x = 1;
//
//    // 标志默认为false
//    bool flag = false;
//    thread t1([&] {
//        for (size_t i = 0; i < 10; i++)
//        {
//            // 使用unique_lock管理锁
//            unique_lock<mutex> lock(mtx);
//
//            // 如果flag == true就进行等待
//            //if (flag)
//            while (flag) // 使用while更保险
//                c.wait(lock); // 在wait的时候会自动解锁
//
//            // 必定第一次执行
//            cout << "thread 1:" << this_thread::get_id() << ":" << x << endl;
//            ++x;
//
//            // 执行一次后flag变为true，下次线程再来执行的时候就会进行等待
//            flag = true;
//            // 唤醒线程2
//            c.notify_one();
//        }
//        });
//
//    thread t2([&] {
//        for (size_t i = 0; i < 10; i++)
//        {
//            // 使用unique_lock管理锁
//            unique_lock<mutex> lock(mtx);
//
//            // 如果flag == false就等待 true就开始执行下面的代码
//            //if (!flag)
//            while (!flag) // 使用while更保险
//                c.wait(lock); // 在wait的时候会自动解锁
//
//            cout << "thread 2:" << this_thread::get_id() << ":" << x << endl;
//            ++x;
//
//            // 执行完成后改成false，如果线程2再来执行的时候就会进行等待
//            flag = false;
//            // 唤醒线程1
//            c.notify_one();
//        }
//        }
//    );
//
//    t1.join();
//    t2.join();
//
//    return 0;
//}

#include <iostream>
#include <future>
#include <thread>

int compute() {
    // 模拟耗时计算
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;
}

int main() {
    // 启动异步任务
    std::future<int> fut = std::async(std::launch::async, compute);

    // 在主线程做其他工作...
    std::cout << "Doing other work...\n";

    // 获取结果（如果还没完成，会阻塞等待）
    int result = fut.get();
    std::cout << "Result: " << result << std::endl;

    return 0;
}



