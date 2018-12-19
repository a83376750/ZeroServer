#include "FrameworkMgr.h"
#include "Theron/Framework.h"

FrameworkMgr::FrameworkMgr()
{
}


FrameworkMgr::~FrameworkMgr()
{
}

void FrameworkMgr::bind(const char *name, Theron::Framework *obj)
{
	if (name == nullptr)
		return;
	frame_map_[name] = obj;
}

void FrameworkMgr::unbind(const char *name)
{
	if(frame_map_.count(name) > 0)
		frame_map_.erase(name);
}

Theron::Framework* FrameworkMgr::pop(const char *name)
{
	if (frame_map_.count(name) < 0)
	{
		frame_map_[name] = new Theron::Framework();
	}

	return frame_map_[name];
}
