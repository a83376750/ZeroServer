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

	//ѭ��
	virtual void loop();
	//����
	virtual void start();
	//�ر�
	virtual void stop();
public:
	//ִ����Ϣ
	virtual int HandleMsg(UnitMessage *msg) = 0;
	
public:
	//�ر���Ϣ����
	void BeginStop();

	//������Ϣ��ӵ�������
	void PushMsg(gMessage *msg);

	//����ػ�����Ϣ����
	void RecoverMsg(UnitMessage *msg);

public:
	virtual bool IsEmpty() { return unitMsgList_.empty(); }

private:
	TmpList<UnitMessage, std::mutex> unitMsgList_;
	ObjectPool<UnitMessage, std::mutex> msgObjPool_;
	std::atomic_bool isStop_;
};

