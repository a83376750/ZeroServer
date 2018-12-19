#include "BaseUnit.h"

void BaseUnit::start()
{
	std::thread t(&BaseUnit::loop, this);
	t.detach();
}

void BaseUnit::stop()
{
	LOG(INFO) << "BaseUnit is stop";
}

void BaseUnit::BeginStop()
{
	isStop_.store(true);
}

void BaseUnit::PushMsg(UnitMessage::gMessage *msg)
{
	UnitMessage *m = msgObjPool_.pop();
	m->SetMsg(msg);
	unitMsgList_.push_back(m);
}
void BaseUnit::RecoverMsg(UnitMessage *msg)
{
	JUDGE_RETURN(msg == nullptr, );
	msg->reset();
	msgObjPool_.push(msg);
}

void BaseUnit::loop()
{
	UnitMessage *msg = nullptr;
	while (1)
	{
		msg = unitMsgList_.pop_front();
		if (msg == nullptr)
		{
			if (isStop_.load() == true)
				break;
			SLEEP(100);
			continue;
		}
		else if (isStop_.load() == true)
		{
			std::cout << "is waiting msg... " << std::endl;
		}

		int ret = HandleMsg(msg);
		LOG(INFO) << "ret:" << ret;
	}

	stop();
}