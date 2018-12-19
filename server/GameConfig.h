#pragma once

#include "rapidjson.h"
#include "rapidjson/document.h"
#include "Singleton.h"
#include "Header.h"
#include "ConfigStruct.h"

class GameConfig
{
public:
	typedef rapidjson::Document Doc;
	typedef rapidjson::Value Json;
	enum
	{
		MAX_VERSION_CNT = 2,

		DEBUG_INIT = 1,
		FORMAL_INIT = 2,
	};
	struct BasicConfig
	{
	public:
		BasicConfig();
		const Doc& ConstJson() const;
		Doc &RevertJson();

		const Json& Find(int key);
		const Json& ConstJsonName(const char* key) const;

		int CurVersion() const;
		int PrevVersion() const;
		int Validate(int key);

		void UpdateVersion();
		void RevertVersion();
		void ConvertJsonToMap(int key_flag = false);
		void LoadCombineFile(const std::string& path, int flag = false);

		const std::string& VersionNo()const;

	private:
		Doc doc_[MAX_VERSION_CNT];
		int curVer_;
		std::string str_vec_[MAX_VERSION_CNT];
		Doc null_json_;
	};
	typedef std::map<int, BasicConfig> MapBasicConfig;
	typedef std::map<int, Doc*> JsonMap;

	GameConfig();
	~GameConfig();
	void init(int init_type);
	void start();

	void DebugInit();
	void FormalInit();
	void LoadAllFile(const char *folder = "all");

	int LoadJsonFile(const char *path, Doc &d);
//////////////////////////////////////////////////////////////////////////
public:
	struct ServerInfo
	{
		std::string server_flag;
		int64_t server_id;
	};
	ServerInfo server_info_;
	ServerDetailVec server_vec_;

	void GetServerDetail(ServerDetail &out_detail, const char *service_name, int index = -1);
	int ServiceType(const std::string &service_name);
	int LoadServerConf(bool bStart = false);
	const ServerDetailVec& GetServerDetail();
private:
	Doc server_conf_;
//////////////////////////////////////////////////////////////////////////
public:
	Json& MachineJson(const char *key);
	int LoadMachineConf();

private:
	Doc machine_conf_;
	std::string special_path_;
};

typedef Singleton<GameConfig> GC;
