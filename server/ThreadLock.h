#pragma once

#include <atomic>
#include <condition_variable>

#include "Header.h"

struct NullMutex
{
	NullMutex() {}
	~NullMutex() {}
	virtual void lock() {}
	virtual void unlock() {}
};

class RWLock
{
public:
	RWLock() = default;
	~RWLock() = default;

public:
	void LockRead()
	{
		std::unique_lock<std::mutex> ulk(mutex_);
		cond_r_.wait(ulk, [=]()->bool {return write_flag_ == 0; });
		++read_cnt_;
	}

	void LockWrite()
	{
		std::unique_lock<std::mutex> ulk(mutex_);
		++write_cnt_;
		cond_w_.wait(ulk, [=]()->bool {return read_cnt_ == 0 && !write_flag_; });
		write_flag_ = true;
	}
	void ReleaseRead()
	{
		std::unique_lock<std::mutex> ulk(mutex_);
		if (--read_cnt_ == 0 && write_cnt_ > 0)
		{
			cond_w_.notify_one();
		}
	}
	void ReleaseWrite()
	{
		std::unique_lock<std::mutex> ulk(mutex_);
		if (--write_cnt_ == 0)
		{
			cond_r_.notify_all();
		}
		else
		{
			cond_w_.notify_one();
		}
		write_flag_ = false;
	}

private:
	volatile size_t read_cnt_{ 0 };
	volatile size_t write_cnt_{ 0 };
	volatile bool write_flag_{ false };
	std::mutex mutex_;
	std::condition_variable cond_w_;
	std::condition_variable cond_r_;
};

class SpinLock
{
public:
	SpinLock() = default;
	SpinLock(const SpinLock&) = delete;
	SpinLock& operator= (const SpinLock&) = delete;
	void lock() { while (flag.test_and_set(std::memory_order_acquire)); }
	void unlock() { flag.clear(std::memory_order_release); }

public:
	std::atomic_flag flag = ATOMIC_FLAG_INIT;
};

#define SPIN_GUARD_LOCK(V,S) std::lock_guard<SpinLock> V(S);