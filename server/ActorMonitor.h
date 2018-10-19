#pragma once

#include "Header.h"
#include "Singleton.h"

class ActorMonitor
{
public:
	void init();

	bool isStart();
	bool isExit();
};

void ActorMonitor::init()
{

}

bool ActorMonitor::isStart()
{

}

bool ActorMonitor::isExit()
{

}

typedef Singleton<ActorMonitor> s_ActorMonitor;
#define ACTOR_MONITOR s_ActorMonitor::instance()