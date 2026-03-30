#pragma once
#include <atomic>
#include <functional>
#include <future>
#include <list>
#include <mutex>
#include <thread>
#include <vector>

class XTask {
 public:
  virtual int Run() = 0;
  std::function<bool()> is_exit = nullptr;
  auto GetReturn() {
    // 阻塞等待 set_value
    return p_.get_future().get();
  }
  void SetValue(int v) { p_.set_value(v); }

 private:
  // 用来接收返回值
  std::promise<int> p_;
};

class XThreadPool {
 public:
  void Init(int num);

  void Start();

  void Stop();

  void AddTask(std::shared_ptr<XTask> task);

  std::shared_ptr<XTask> GetTask();

  // 线程池是否退出
  bool is_exit() { return is_exit_; }

  int task_run_count() { return task_run_count_; }

 private:
  // 线程池线程的入口函数
  void Run();
  int thread_num_ = 0;  // 线程数量
  std::mutex mux_;
  std::vector<std::shared_ptr<std::thread> > threads_;
  std::list<std::shared_ptr<XTask> > tasks_;
  std::condition_variable cv_;
  bool is_exit_ = false;  // 线程池退出
  // 正在运行的任务数量,线程安全
  std::atomic<int> task_run_count_ = {0};
};
