#pragma once
#include <thread>
#include <atomic>

#include "BaseUnit.h"

#define THREAD_WAIT_TIME 10

class WatchSr
{
public:
	WatchSr() : flag_(ATOMIC_FLAG_INIT) {}
	virtual void start()
	{
		flag_.store(true);
		worker_t_ = new std::thread(this, &loop);
		worker_t_->detach();
	}
	virtual void loop()
	{
		while (flag_.load())
		{
			unit_
		}
	}
	virtual void stop();

private:
	BaseUnit *unit_;
	std::thread *worker_t_;
	std::atomic<bool> flag_;
};
