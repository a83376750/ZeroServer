#pragma once
#include <mutex>
#include <vector>
#include <deque>
#include <string>

#include "Singleton.h"

class ThreadPool
{
public:
	typedef std::function<void()> Task;
	enum
	{
		DEFAULT_SIZE = 10,
	};

	explicit ThreadPool(const std::string &name = std::string(), int default_size = DEFAULT_SIZE);
	virtual ~ThreadPool();

	ThreadPool& operator=(const ThreadPool &) = delete;
	ThreadPool(const ThreadPool &) = delete;

	void start(int numThreads);//设置线程数，创建numThreads个线程  
	void stop();//线程池结束  
	void run(const Task& t);//任务f在线程池中运行  
	void SetMaxQueueSize(int maxSize) { maxQueueSize_ = maxSize; }//设置任务队列可存放最大任务数  

protected:
	void PrintPushThreadInfo(const Task &t);
	void PrintRunThreadInfo(const Task &t);

private:
	bool IsFull();//任务队列是否已满  
	void RunInThread();//线程池中每个thread执行的function  
	Task take();//从任务队列中取出一个任务  

private:
	std::mutex mutex_;
	std::condition_variable notEmpty_;
	std::condition_variable notFull_;
	std::string name_;
	std::vector<std::thread> threads_;
	std::deque<Task> queue_;
	size_t maxQueueSize_;
	bool running_;
};
