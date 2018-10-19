#pragma once
#include "Singleton.h"

class DebugServer
{
public:
	DebugServer();
	~DebugServer();

	void Init();
	void Start();
};

typedef Singleton<DebugServer> DebugServerSingle;
#define DEBUG_SERVER    (DebugServerSingle::instance())