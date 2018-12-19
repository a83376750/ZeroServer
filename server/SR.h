#pragma once

#include "ObjectPool.h"
#include "nn.hpp"
#include "bus.h"
#include "List.h"
#include "pipeline.h"

#include <mutex>


namespace nn {
	class socket;
}
typedef nn::socket n_socket;
class ServiceMgr;
class BaseUnit;
namespace SERVER_NET
{
	static void AddrFrom(char *out, const char *proto, const char *ip, int port)
	{
		sprintf(out, "%s://%s:%d", proto, ip, port);
	}

	class NanoSR
	{
	public:
		friend class ServiceMgr;
		enum { DEFAULT_BUFF_SIZE = 1024};

		NanoSR(int domain, int protocol);
		virtual ~NanoSR();
		NanoSR(const NanoSR&) = delete;
		NanoSR& operator=(const NanoSR&) = delete;
		
	public:
		void SendService();
		void RecvService();

	public:		
		int bind(const char *addr);
		int connect(const char *addr);

	private:
		n_socket s_;
		std::atomic_bool is_stop_;
		TmpList<DynaObj, std::mutex> *l_ptr_;
	};
}