#pragma once
#include "Singleton.h"

class ThreadPool;
class DebugServer
{
public:
	DebugServer();
	~DebugServer();

	void init();
	void start();

	void loop();

private:
	bool is_start_;
	bool is_stop_;
	ThreadPool *thread_pool_;
};

typedef Singleton<DebugServer> DS;
