#pragma once

#include "Header.h"
#include <google/protobuf/message.h>
#include "ObjectPool.h"
#include "List.h"
#include "BaseStruct.h"

class BaseUnit
{
public:
	typedef google::protobuf::Message gMessage;
	BaseUnit() = default;
	virtual ~BaseUnit() = default;

	//循环
	virtual void loop();
	//启动
	virtual void start();
	//关闭
	virtual void stop();
public:
	//执行消息
	virtual int HandleMsg(UnitMessage *msg) = 0;
	
public:
	//关闭消息队列
	void BeginStop();

	//将新消息添加到队列中
	void PushMsg(gMessage *msg);

	//对象池回收消息对象
	void RecoverMsg(UnitMessage *msg);

public:
	virtual bool IsEmpty() { return unitMsgList_.empty(); }

private:
	TmpList<UnitMessage, std::mutex> unitMsgList_;
	ObjectPool<UnitMessage, std::mutex> msgObjPool_;
	std::atomic_bool isStop_;
};

