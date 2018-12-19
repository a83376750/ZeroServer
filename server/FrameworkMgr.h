#pragma once
#include <map>

namespace Theron
{
	class Framework;
}
class FrameworkMgr
{
public:
	typedef std::map<const char*, Theron::Framework*> FrameMap;

public:
	FrameworkMgr();
	~FrameworkMgr();

	void bind(const char *name, Theron::Framework *obj);
	void unbind(const char *name);

	Theron::Framework* pop(const char *name);
private:
	FrameMap frame_map_;
};

typedef Singleton<FrameworkMgr> FM;

