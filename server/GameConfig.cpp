#include "GameConfig.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/filereadstream.h"

#include <iostream>
#include <string>
#include <stream.h>
#include <fstream>

using namespace rapidjson;

GameConfig::GameConfig()
{
	
}

GameConfig::~GameConfig()
{
}

void GameConfig::init(int init_type)
{
	if (DEBUG_INIT == init_type)
	{
		DebugInit();
	}
	else
	{
		FormalInit();
	}

	start();
}

void GameConfig::DebugInit()
{
	LoadAllFile();
}

void GameConfig::FormalInit()
{
	LoadAllFile();
}

void GameConfig::LoadAllFile(const char *folder)
{
	if (strcmp(folder, "all") == 0)
	{
		LoadMachineConf();
		LoadServerConf(true);




	}
	else if (strcmp(folder, "server") == 0)
	{
		LoadServerConf(true);
	}

}

void GameConfig::start()
{

}

int GameConfig::LoadJsonFile(const char *path, GameConfig::Doc &d)
{
	JUDGE_RETURN(path == nullptr, -1);
	char buffer[4096];
	FILE *fp = nullptr;
	fopen_s(&fp, path, "r");
	if (!fp) 
	{
		printf("Schema file '%s' not found\n", path);
		return -1;
	}
	FileReadStream fs(fp, buffer, sizeof(buffer));
	d.ParseStream(fs);
	if (d.HasParseError())
	{
		printf("path:%s error code:%d", path, d.GetParseError());
		fclose(fp);
		return -1;
	}
	fclose(fp);
	return 0;
}

GameConfig::BasicConfig::BasicConfig()
{

}

const GameConfig::Doc & GameConfig::BasicConfig::ConstJson() const
{
	return doc_[curVer_];
}

GameConfig::Doc & GameConfig::BasicConfig::RevertJson()
{
	return doc_[((curVer_ + 1) % MAX_VERSION_CNT)];
}

const GameConfig::Json& GameConfig::BasicConfig::Find(int key)
{
	return null_json_;
}

const GameConfig::Json& GameConfig::BasicConfig::ConstJsonName(const char* key) const
{
	return ConstJson()[key];
}

int GameConfig::BasicConfig::CurVersion() const
{
	return curVer_;
}

int GameConfig::BasicConfig::PrevVersion() const
{
	return ((curVer_ + 1) % MAX_VERSION_CNT);
}

int GameConfig::BasicConfig::Validate(int key)
{
	return 0;
}

void GameConfig::BasicConfig::UpdateVersion()
{
	curVer_ = (curVer_ + 1) % MAX_VERSION_CNT;

}

void GameConfig::BasicConfig::RevertVersion()
{
	curVer_ = (curVer_ + MAX_VERSION_CNT - 1) % MAX_VERSION_CNT;
}

void GameConfig::BasicConfig::ConvertJsonToMap(int key_flag /*= false*/)
{

}

void GameConfig::BasicConfig::LoadCombineFile(const std::string& path, int flag /*= false*/)
{

}

const std::string& GameConfig::BasicConfig::VersionNo() const
{
	return str_vec_[CurVersion()];
}

void GameConfig::GetServerDetail(ServerDetail &out_detail, const char *service_name, int index /*= -1*/)
{
	for (auto it = server_vec_.begin(); it != server_vec_.end(); ++it)
	{
		if (strcmp((*it).service.c_str(), service_name) == 0)
		{
			if (index == -1)
			{
				out_detail = *it;
				return;
			}
			else if((*it).conf_index == index)
			{
				out_detail = *it;
				return;
			}
		}
	}
}

int GameConfig::ServiceType(const std::string &service_name)
{
	if (service_name == SERVICE_NAME_GATE)
		return SERVER_GATE;
	if (service_name == SERVICE_NAME_AUTH)
		return SERVER_AUTH;
	if (service_name == SERVICE_NAME_SAND)
		return SERVER_SAND;
	if (service_name == SERVICE_NAME_CHAT)
		return SERVER_CHAT;
	if (service_name == SERVICE_NAME_LOGIC)
		return SERVER_LOGIC;
	if (service_name == SERVICE_NAME_LOG)
		return SERVER_LOG;
	if (service_name == SERVICE_NAME_MAP)
		return SERVER_MAP;
	return -1;
}

int GameConfig::LoadServerConf(bool bStart /*= false*/)
{
	JUDGE_RETURN(LoadJsonFile(special_path_.c_str(), server_conf_) < 0, -1);

	Json server_list = server_conf_["server_list"].GetArray();

	int i = 0;
	for(auto it = server_list.Begin(); it != server_list.End(); ++it, ++i)
	{
		ServerDetail detail;
		detail.service = (*it)["service"].GetString();
		detail.detail = (*it)["name"].GetString();
		detail.inner_port = (*it)["inner_port"].SafeGetInt();
		detail.out_port = (*it)["outer_port"].SafeGetInt();
		if((*it).HasMember("address") == true)
			detail.address = (*it)["address"].GetString();
		else
			detail.address = INNER_ADDRESS;
		detail.service_type = this->ServiceType(detail.service);
		detail.conf_index = i;

		server_vec_.emplace_back(detail);
	}
	return 0;
}

const ServerDetailVec& GameConfig::GetServerDetail()
{
	return server_vec_;
}

GameConfig::Json& GameConfig::MachineJson(const char *key)
{
	return machine_conf_[key];
}

int GameConfig::LoadMachineConf()
{
	std::string basePath = "config/server/";
	std::string path = basePath + "machine.json";
	JUDGE_RETURN(LoadJsonFile(path.c_str(), machine_conf_) < 0, -1);

	special_path_ = basePath + "special_" + machine_conf_["special"].GetString() + ".json";
	return 0;
}
