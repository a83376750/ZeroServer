#include "ThreadPool.h"
#include "TimeValue.h"

#include <exception>
#include <thread>
#include <assert.h>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>

ThreadPool::ThreadPool(const std::string &name, int default_size) :
	name_(name),
	maxQueueSize_(default_size),
	running_(false)
{

}

ThreadPool::~ThreadPool()
{
	if (running_)
	{
		stop();
	}
}

void ThreadPool::start(int numThreads)
{
	assert(threads_.empty() || numThreads <= 0);
	running_ = true;
	threads_.reserve(numThreads);

	for (int i = 0; i < numThreads; ++i)
	{
		threads_.emplace_back(std::thread(&ThreadPool::RunInThread, this));
	}
}

void ThreadPool::stop()
{
	{
		std::unique_lock<std::mutex>  lock(mutex_);
		running_ = false;
		notEmpty_.notify_all();
	}

	for (size_t i = 0; i < threads_.size(); ++i)
	{
		threads_[i].join();
	}
}

void ThreadPool::run(const Task &t)
{
	PrintPushThreadInfo(t);
	if (threads_.empty())
	{
		t();
	}
	else
	{
		std::unique_lock<std::mutex> lock(mutex_);
		while (IsFull())
		{
			notFull_.wait(lock);
		}

		assert(!IsFull());
		queue_.push_back(t);
		notEmpty_.notify_one();
	}
}

ThreadPool::Task ThreadPool::take()
{
	std::unique_lock<std::mutex> lock(mutex_);

	while (queue_.empty() && running_)
	{
		notEmpty_.wait(lock);
	}

	Task task;
	if (!queue_.empty())
	{
		task = queue_.front();
		queue_.pop_front();

		if (maxQueueSize_ > 0)
		{
			notFull_.notify_one();
		}
	}

	PrintRunThreadInfo(task);
	return task;
}

void ThreadPool::PrintPushThreadInfo(const Task &t)
{
	//auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::cout << "[" << TimeValue::GetCurTimeStr().c_str() << "]" << "push fun:" << t.target_type().name() 
		<< " thread_id:" << std::this_thread::get_id() << std::endl;
}

void ThreadPool::PrintRunThreadInfo(const Task &t)
{
	std::cout << "[" << TimeValue::GetCurTimeStr().c_str() << "]" << "run fun:" << t.target_type().name() 
		<< " thread_id:" << std::this_thread::get_id() << std::endl;
}

bool ThreadPool::IsFull()
{
	return maxQueueSize_ > 0 && queue_.size() >= maxQueueSize_;
}

void ThreadPool::RunInThread()
{
	try
	{
		while (running_)
		{
			Task task = take();
			if (task)
			{
				task();
			}
		}
	}
	catch (const std::exception& ex)
	{
		fprintf(stderr, "exception caught in ThreadPool %s\n", name_.c_str());
		fprintf(stderr, "reason: %s\n", ex.what());
		abort();
	}
	catch (...)
	{
		fprintf(stderr, "exception caught in ThreadPool %s\n", name_.c_str());
	}
}