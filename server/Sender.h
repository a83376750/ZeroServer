#pragma once

#include "Connector.h"

namespace SERVER_NET
{
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
// 		JUDGE_RETURN(context_ == nullptr, -1);
// 		socket_ = zmq_socket(context_, type);
// 		JUDGE_RETURN(socket_ == nullptr, -2);
		return 0;
	}

	int Sender::send(void *in, int size)
	{
// 		JUDGE_RETURN(in == nullptr || size < 1, -1);
// 		return zmq_send(socket_, in, size, 0);
		return 0;
	}
}