#pragma once
#include "Connector.h"

class Reader : public Connector
{
public:
	Reader();
	virtual ~Reader();

	virtual int connect_svc(int type);
	virtual int recv(void *out);
};

Reader::Reader()
{

}

Reader::~Reader()
{

}

int Reader::connect_svc(int type)
{

}

int Reader::recv(void *out)
{
	zmq_msg_t msg;
	zmq_recv(m_socket, out)
}
