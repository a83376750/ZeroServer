#pragma once

#include "zmq.h"
#include "Header.h"

class Connector 
{
public:
	enum ConnectType
	{
		CONNECT_TCP = 1,
		CONNECT_UDP
	};

	Connector();
	virtual ~Connector();

	int create_detail(int type, const char *ip, int port);
	virtual int set_opt(int sock_opt, void *opt_sub, int opt_size);
	virtual int connect_svc(int type);
private:
	int m_connectType;
	std::string m_address;

protected:
	void *m_socket;
	static void* m_context;
};

void *Connector::m_context = nullptr;

Connector::Connector()
{
	m_connectType = -1;
}

Connector::~Connector()
{

}

int Connector::create_detail(int type, const char *ip, int port)
{
	JUDGE_RETURN(ip == nullptr || port < 1, -2);
	if(m_context == nullptr)
		m_context = zmq_ctx_new();

	char address[256] = "\0";
	switch (type)
	{
		case ConnectType::CONNECT_TCP:
		{
			sprintf_s(address, "tcp://%s:%d", ip, port);
			break;
		}
		case ConnectType::CONNECT_UDP:
		{
			sprintf_s(address, "upd://%s:%d", ip, port);
			break;
		}
	}

	m_address.clear();
	m_address.append(address);
	return 0;
}

int Connector::set_opt(int sock_opt, void *opt_sub, int opt_size)
{
	JUDGE_RETURN(m_socket == nullptr, -1);
	return zmq_setsockopt(m_socket, sock_opt, opt_sub, opt_size);
}

int Connector::connect_svc(int type)
{
	printf("error base class:%d", type);
	return -1;
}
