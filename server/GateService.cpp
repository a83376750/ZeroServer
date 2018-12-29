#include "GateService.h"
#include "GameConfig.h"

using namespace SERVER_NET;
GateClientService::GateClientService()
	:client_sr_(AF_SP, NN_SURVEYOR)
{
	char socket_addr[128] = "\0";
	ServerDetail detail;
	GC::instance()->GetServerDetail(detail, SERVICE_NAME_GATE);
	SERVER_NET::AddrFrom(socket_addr, "tcp", detail.address.c_str(), detail.out_port);
	try
	{
		client_sr_.bind(socket_addr);
		printf("%s_%d", detail.address.c_str(), detail.out_port);
	}
	catch (const nn::exception &a)
	{
		std::cerr << "GateClientService bind error:" << a.what();
	}

	std::thread t(std::bind(&SERVER_NET::NanoSR::RecvService, &client_sr_));
	t.detach();
}


GateClientService::~GateClientService()
{
}

GateInnerService::GateInnerService()
	:inner_logic_sr_(AF_SP, NN_PULL),
	inner_recv_sr_(AF_SP, NN_PUSH)
{
	char socket_addr[128] = "\0";
	ServerDetail detail;
	GC::instance()->GetServerDetail(detail, SERVICE_NAME_GATE);
	SERVER_NET::AddrFrom(socket_addr, "tcp", detail.address.c_str(), detail.inner_port);
	try
	{
		inner_recv_sr_.bind(socket_addr);
	}
	catch (const nn::exception &a)
	{
		std::cerr << "GateInnerService bind error:" << a.what();
		return;
	}
	
	GC::instance()->GetServerDetail(detail, SERVICE_NAME_LOGIC);
	ZERO_MEMORY(socket_addr, ARRAY_LENGTH(socket_addr));
	SERVER_NET::AddrFrom(socket_addr, "tcp", detail.address.c_str(), detail.inner_port);

	try
	{
		inner_logic_sr_.connect(socket_addr);
	}
	catch (const nn::exception &a)
	{
		std::cerr << "GateInnerService connect error:" << a.what();
		return;
	}


// 	auto detail_vec = GC::instance()->GetServerDetail();
// 	for (auto it = detail_vec.begin(); it != detail_vec.end(); ++it)
// 	{
// 		GC::instance()->GetServerDetail(detail, SERVICE_NAME_LOGIC);
// 		ZERO_MEMORY(socket_addr, ARRAY_LENGTH(socket_addr));
// 		SERVER_NET::AddrFrom(socket_addr, "tcp", detail.address.c_str(), detail.inner_port);
// 		inner_logic_sr_.connect(socket_addr);
// 	}
}

GateInnerService::~GateInnerService()
{

}
