#pragma once
#include "Connector.h"

namespace SERVER_NET
{
	class Reader : public Connector
	{
	public:
		Reader();
		virtual ~Reader();

		virtual int ConnectSvc(int type);
		virtual int recv(void *out);
	};

	Reader::Reader()
	{

	}

	Reader::~Reader()
	{

	}

	int Reader::ConnectSvc(int type)
	{
		return 0;
	}

	int Reader::recv(void *out)
	{
// 		zmq_msg_t msg;
// 		int rc = zmq_msg_init(&msg);
// 		JUDGE_RETURN(rc == -1, rc);
// 
// 		rc = zmq_msg_recv(&msg, socket_, 0);
// 		JUDGE_RETURN(rc == -1, rc);

		return 0;
	}
}