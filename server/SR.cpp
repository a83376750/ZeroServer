#include <utility>
#include "SR.h"
#include "Header.h"
#include "BaseUnit.h"
#include "TimeValue.h"

///////////////////////////NanoSR///////////////////////////////////////
SERVER_NET::NanoSR::NanoSR(int domain, int protocol)
	:s_(domain, protocol)
{
	l_ptr_ = new TmpList<DynaObj, std::mutex>();
}

SERVER_NET::NanoSR::~NanoSR()
{
	SAFE_DELETE(l_ptr_);
}

void SERVER_NET::NanoSR::SendService()
{
	void *data = nullptr;
	int rc = 0;
	while (is_stop_.load() == false)
	{
		data = l_ptr_->pop_front();
		if (data == nullptr)
		{
			SLEEP(100);
			continue;
		}
		rc = s_.send(data, DEFAULT_BUFF_SIZE, 0);
	}

	if (data != nullptr)
		nn_freemsg(data);
}

void SERVER_NET::NanoSR::RecvService()
{
	char *data = new char[256];
	ZERO_MEMORY(data, 256);
	int rc = 0;
	while (is_stop_.load() == false)
	{
		int64_t pre = time(0);
		try
		{
			rc = s_.recv(data, DEFAULT_BUFF_SIZE, 0);
		}
		catch (const nn::exception &a)
		{
			std::cerr << "recv service error:" << a.what();
			continue;
		}
		
		if (rc <= 0)
		{
			SLEEP(100);
			continue;
		}

		int64_t aft = time(0);

		if (aft - pre > 10)
			std::cout << "error slow:" << aft - pre << std::endl;

		std::cout << (char*)data << std::endl;

		while (l_ptr_->size() > 1000)
		{
			SLEEP(100);
			std::cerr << "msgList is full sleep ....." << std::endl;
		}

		l_ptr_->push_back(std::move(&DynaObj(data, rc)));
	}

	if (data != nullptr)
		nn_freemsg(data);
}

int SERVER_NET::NanoSR::bind(const char *addr)
{
	return s_.bind(addr);
}

int SERVER_NET::NanoSR::connect(const char *addr)
{
	return s_.connect(addr);
}
