#pragma once

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

class Monitor : public IMonitor
{
public:
	Monitor(const char *name)
	{
		
	}
	virtual void start() {}
	virtual void stop() {}
private:
};