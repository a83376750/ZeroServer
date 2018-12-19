#include "GateUnit.h"

GateUnit::GateUnit()
{
}


GateUnit::~GateUnit()
{
}

int GateUnit::HandleMsg(UnitMessage *msg)
{
	JUDGE_RETURN(msg == nullptr, -1);
	size_t msgNum = msg->GetMsgNum();


	switch (msgNum)
	{


		default:
		{
			return -1;
		}
	}
	return 0;
}
