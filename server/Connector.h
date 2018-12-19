#pragma once

#include "Header.h"

namespace SERVER_NET
{
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

		int CreateDetail(int type, const char *ip, int port);
		virtual int SetOpt(int sock_opt, void *opt_sub, int opt_size);
		virtual int ConnectSvc(int type);
	private:
		int connect_type_;
		std::string address_;

	protected:
		void *socket_;
		static void* context_;
	};

	void *Connector::context_ = nullptr;

	Connector::Connector()
	{
		connect_type_ = -1;
	}

	Connector::~Connector()
	{

	}

	int Connector::CreateDetail(int type, const char *ip, int port)
	{
// 		JUDGE_RETURN(ip == nullptr || port < 1, -2);
// 		if (context_ == nullptr)
// 			context_ = zmq_ctx_new();
// 
// 		char address[256] = "\0";
// 		switch (type)
// 		{
// 		case ConnectType::CONNECT_TCP:
// 		{
// 			sprintf_s(address, "tcp://%s:%d", ip, port);
// 			break;
// 		}
// 		case ConnectType::CONNECT_UDP:
// 		{
// 			sprintf_s(address, "upd://%s:%d", ip, port);
// 			break;
// 		}
// 		}
// 
// 		address_.clear();
// 		address_.append(address);
		return 0;
	}

	int Connector::SetOpt(int sock_opt, void *opt_sub, int opt_size)
	{
// 		JUDGE_RETURN(socket_ == nullptr, -1);
// 		return zmq_setsockopt(socket_, sock_opt, opt_sub, opt_size);
		return 0;
	}

	int Connector::ConnectSvc(int type)
	{
		printf("error base class:%d", type);
		return -1;
	}
}