#pragma once

#include "SR.h"

class GateClientService
{
public:
	GateClientService();
	virtual ~GateClientService();

private:
	SERVER_NET::NanoSR client_sr_;			//�ͻ��˷�����Ϣ
};

class GateInnerService
{
public:
	typedef std::map<int, SERVER_NET::NanoSR*> SRMap;
	GateInnerService();
	virtual ~GateInnerService();
private:
	SERVER_NET::NanoSR inner_logic_sr_;		//�������͵�logic
	SRMap inner_map_sr_;					//�������͵�map		//֮����,��̬����map
	SERVER_NET::NanoSR inner_recv_sr_;		//�����������̷�������Ϣ
};

