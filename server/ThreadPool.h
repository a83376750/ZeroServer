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

	void start(int numThreads);//�����߳���������numThreads���߳�  
	void stop();//�̳߳ؽ���  
	void run(const Task& t);//����f���̳߳�������  
	void SetMaxQueueSize(int maxSize) { maxQueueSize_ = maxSize; }//����������пɴ�����������  

protected:
	void PrintPushThreadInfo(const Task &t);
	void PrintRunThreadInfo(const Task &t);

private:
	bool IsFull();//��������Ƿ�����  
	void RunInThread();//�̳߳���ÿ��threadִ�е�function  
	Task take();//�����������ȡ��һ������  

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
