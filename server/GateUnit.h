#pragma once
#include "BaseUnit.h"

class GateUnit : public BaseUnit
{
public:
	GateUnit();
	virtual ~GateUnit();

	virtual int HandleMsg(UnitMessage *msg);
};

