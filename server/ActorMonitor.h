#pragma once

#include "Header.h"
#include "Singleton.h"

class ActorMonitor
{
public:
	ActorMonitor() {}
	~ActorMonitor() {}
	void Init();

	bool IsStart();
	bool IsExit();

	void Handle();

};

void ActorMonitor::Init()
{

}

bool ActorMonitor::IsStart()
{
	return true;
}

bool ActorMonitor::IsExit()
{
	return false;
}

void ActorMonitor::Handle()
{
	printf("hello world\n");
}

typedef Singleton<ActorMonitor> s_ActorMonitor;
#define ACTOR_MONITOR s_ActorMonitor::instance()