#include "ConfigStruct.h"


ServerDetail::ServerDetail()
{
	ServerDetail::reset();
}

void ServerDetail::reset()
{
	conf_index = 0;
	inner_port = 0;
	out_port = 0;
	service_type = 0;
	detail.clear();
	service.clear();
	address.clear();
}

bool ServerDetail::need_connect() const
{
	if (this->inner_port <= 0)
	{
		return false;
	}

	if (this->address.empty() == true)
	{
		return false;
	}

	return true;
}

bool ServerDetail::need_reconnect_travel()
{
	return true;
}

bool ServerDetail::need_reconnect_channel()
{
	return true;
}

ServerDetail& ServerDetail::operator=(const ServerDetail &r)
{
	conf_index = r.conf_index;
	inner_port = r.inner_port;
	out_port = r.out_port;
	service_type = r.service_type;
	detail = r.detail;
	service = r.service;
	address = r.address;
	return *this;
}
