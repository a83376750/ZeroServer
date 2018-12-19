#pragma once

#include "Singleton.h"
#include "GateService.h"
#include "Monitor.h"

class GateUnit;
class GateMonitor : public Monitor
{
public:
	GateMonitor();
	virtual ~GateMonitor();
	
	virtual void start();
	virtual void stop();


private:
	GateClientService gcs_;
	GateInnerService gis_;

	GateUnit *unit_;
};

typedef Singleton<GateMonitor> GM;
