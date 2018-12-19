#pragma once
#include <string>
#include <vector>

class ServerDetail
{
public:
	ServerDetail();
	ServerDetail& operator=(const ServerDetail &r);
	void reset();

	bool need_connect() const;
	bool need_reconnect_travel();
	bool need_reconnect_channel();

public:
	int conf_index;
	int inner_port;
	int out_port;
	int service_type;
	std::string detail;
	std::string service;
	std::string address;
};
typedef std::vector<ServerDetail> ServerDetailVec;
