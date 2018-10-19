#pragma once
#include "ActorMonitor.h"

class BaseActor
{
public:
	friend class ActorMonitor;

private:
	BaseActor();
	BaseActor(const BaseActor &);
	BaseActor& operator=(const BaseActor &);
	~BaseActor();

public:
	static BaseActor& CreateActor();
	ActorMonitor* monitor();
};

BaseActor& BaseActor::CreateActor()
{

}

ActorMonitor* BaseActor::monitor()
{
	return ACTOR_MONITOR;
}
