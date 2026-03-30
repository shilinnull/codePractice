#include "xthreadpool.h"

#include <iostream>
using namespace std;

void XThreadPool::Init(int num) {
  unique_lock<mutex> lock(mux_);
  this->thread_num_ = num;
  cout << "Thread pool Init " << num << endl;
}

void XThreadPool::Start() {
  unique_lock<mutex> lock(mux_);
  if (thread_num_ <= 0) {
    cerr << "Please Init XThreadPool" << endl;
    return;
  }
  if (!threads_.empty()) {
    cerr << "Thread pool has start!" << endl;
    return;
  }
  // 启动线程
  for (int i = 0; i < thread_num_; i++) {
    auto th = make_shared<thread>(&XThreadPool::Run, this);
    threads_.push_back(th);
  }
}

void XThreadPool::Stop() {
  is_exit_ = true;
  cv_.notify_all();
  for (auto& th : threads_) {
    th->join();
  }
  unique_lock<mutex> lock(mux_);
  threads_.clear();
}

void XThreadPool::Run() {
  cout << "begin XThreadPool Run " << this_thread::get_id() << endl;
  while (!is_exit()) {
    auto task = GetTask();
    if (!task) continue;
    ++task_run_count_;
    try {
      auto re = task->Run();
      task->SetValue(re);
    } catch (...) {
      throw;
    }
    --task_run_count_;
  }

  cout << "end XThreadPool Run " << this_thread::get_id() << endl;
}

void XThreadPool::AddTask(std::shared_ptr<XTask> task) {
  unique_lock<mutex> lock(mux_);
  tasks_.push_back(task);
  task->is_exit = [this] { return is_exit(); };
  lock.unlock();
  cv_.notify_one();
}

std::shared_ptr<XTask> XThreadPool::GetTask() {
  unique_lock<mutex> lock(mux_);
  if (tasks_.empty()) {
    cv_.wait(lock);
  }
  if (is_exit()) return nullptr;
  if (tasks_.empty()) return nullptr;
  auto task = tasks_.front();
  tasks_.pop_front();
  return task;
}
