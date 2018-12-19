#pragma once
#include "Theron/Actor.h"

class IMonitor
{
public:
	IMonitor() = default;
	virtual ~IMonitor() = default;

	virtual void start() = 0;
	virtual void stop() = 0;

	virtual IMonitor* get()
	{
		return nullptr;
	}


};

class Monitor : public IMonitor/*, public Theron::Actor*/
{
public:
	Monitor(const char *name)/* : framework_(FM::pop(name))Theron::Actor(framework_)*/
	{
		//RegisterHandler(this, &Monitor::handle);
	}
	virtual void start() {}
	virtual void stop() {}

	//virtual void handle(const std::string &message, const Theron::Address from) {};

private:
	//Theron::Framework *framework_;
};