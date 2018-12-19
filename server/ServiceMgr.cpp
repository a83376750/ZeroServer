#include "ServiceMgr.h"
#include "Header.h"
#include "nn.hpp"
#include "SR.h"

ServiceMgr::ServiceMgr()
{
}


ServiceMgr::~ServiceMgr()
{
}

void ServiceMgr::bind(n_socket *s)
{
	JUDGE_RETURN(s == nullptr, );
	if (service_map_.count(s->s) > 0)
		LOG(WARNING) << "service is exist, will be replace a new";
	service_map_[s->s] = s;
}

void ServiceMgr::bind(NanoSR *s)
{
	return bind(&s->s_);
}

void ServiceMgr::unbind(n_socket *s)
{
	JUDGE_RETURN(s == nullptr, );
	if (service_map_.count(s->s) > 0)
		service_map_.erase(s->s);
}

n_socket* ServiceMgr::get(int key)
{
	JUDGE_RETURN(check(key) == false, nullptr);
	return service_map_[key];
}

void ServiceMgr::clear()
{
	service_map_.clear();
}

bool ServiceMgr::check(int key)
{
	return service_map_.count(key) > 0;
}
