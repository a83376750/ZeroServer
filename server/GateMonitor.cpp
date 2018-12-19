#include "GateMonitor.h"
#include "GateUnit.h"


GateMonitor::GateMonitor()
	:Monitor("GateMonitor")
{
	unit_ = new GateUnit();
}


GateMonitor::~GateMonitor()
{
	SAFE_DELETE(unit_);
}

void GateMonitor::start()
{

}

void GateMonitor::stop()
{

}
