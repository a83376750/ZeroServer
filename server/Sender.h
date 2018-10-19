#pragma once

#include "Connector.h"

class Sender : public Connector
{
public:
	Sender();
	virtual ~Sender();
	virtual int connect_svc(int type);
	virtual int send(void *in, int size);
};

Sender::Sender()
{

}

Sender::~Sender()
{

}

int Sender::connect_svc(int type)
{
	JUDGE_RETURN(m_context == nullptr, -1);
	m_socket = zmq_socket(m_context, type);
	JUDGE_RETURN(m_socket == nullptr, -2);
	return 0;
}

int Sender::send(void *in, int size)
{
	JUDGE_RETURN(in == nullptr || size < 1, -1);
	return zmq_send(m_socket, in, size, 0);
}
