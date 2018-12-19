#include <functional>

#include "DebugServer.h"
#include "ThreadPool.h"
#include "TimeValue.h"
#include "Header.h"
#include "GameConfig.h"
#include "GateMonitor.h"

DebugServer::DebugServer()
	: is_start_(false), is_stop_(false)
{
	thread_pool_ = new ThreadPool("DebugServer");
}


DebugServer::~DebugServer()
{
	SAFE_DELETE(thread_pool_);
}

void DebugServer::init()
{
	this->is_start_ = false;
	GC::instance()->init(GameConfig::DEBUG_INIT);
}

void DebugServer::start()
{
	this->is_start_ = true;
	this->is_stop_ = false;

	GM::instance()->start();
// 	while (is_start_)
// 	{
// 		thread_pool_->run(std::bind(&DebugServer::loop, this));
// 	}
// 	int thread_count = GC::instance()->MachineJson("thread_count").SafeGetInt();
// 	thread_pool_->start(thread_count);
	
}

void DebugServer::loop()
{
	while(is_stop_ == false)
		SLEEP_SEC(1);
}
