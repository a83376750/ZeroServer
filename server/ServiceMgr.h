#pragma once
#include <map>
#include "Singleton.h"

namespace nn {
	class socket;
}
typedef nn::socket n_socket;

namespace SERVER_NET {
	class NanoSR;
}

class ServiceMgr
{
public:
	typedef SERVER_NET::NanoSR NanoSR;
	typedef std::map<int, n_socket*> ServiceMap;
	ServiceMgr();
	~ServiceMgr();

public:
	void bind(NanoSR *s);
	void bind(n_socket *s);
	void unbind(n_socket *s);
	n_socket* get(int key);
	void clear();
	bool check(int key);

private:
	ServiceMap service_map_;
};

typedef Singleton<ServiceMgr> SM;

