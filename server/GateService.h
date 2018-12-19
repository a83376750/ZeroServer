#pragma once

#include "SR.h"

class GateClientService
{
public:
	GateClientService();
	virtual ~GateClientService();

private:
	SERVER_NET::NanoSR client_sr_;			//客户端发来消息
};

class GateInnerService
{
public:
	typedef std::map<int, SERVER_NET::NanoSR*> SRMap;
	GateInnerService();
	virtual ~GateInnerService();
private:
	SERVER_NET::NanoSR inner_logic_sr_;		//主动发送到logic
	SRMap inner_map_sr_;					//主动发送到map		//之后处理,动态更新map
	SERVER_NET::NanoSR inner_recv_sr_;		//接受其他进程发来的消息
};

