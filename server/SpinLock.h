#pragma once
#include <atomic>

#include "Header.h"

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