#pragma once

#include "rapidjson.h"
#include "rapidjson/document.h"
#include "Singleton.h"
#include "Header.h"


class GameConfig
{
public:
	enum
	{
		MAX_VERSION_CNT = 2
	};
	GameConfig();
	~GameConfig();
	void init();
	void start();

	int LoadJsonFile(const char *path, rapidjson::Document &d);


	struct BasicConfig
	{
	public:
		BasicConfig();
		const rapidjson::Document& ConstJson() const;
		rapidjson::Document &RevertJson();

		const rapidjson::Value& Find(int key);
		const rapidjson::Value& ConstJsonName(const char* key) const;

		int CurVersion() const;
		int PrevVersion() const;
		int Validate(int key);

		void UpdateVersion();
		void RevertVersion();
		void ConvertJsonToMap(int key_flag = false);
		void LoadCombineFile(const std::string& path, int flag = false);

		const std::string& VersionNo()const;

	private:
		rapidjson::Document m_doc[MAX_VERSION_CNT];
		int m_curVer;
		std::string m_strVec[MAX_VERSION_CNT];
		rapidjson::Document m_null;
	};
	typedef std::map<int, BasicConfig> MapBasicConfig;
	typedef std::map<int, rapidjson::Document*> JsonMap;


	int LoadServerConfig(bool bStart = false);

private:
	rapidjson::Document m_serverConfig;
};

typedef Singleton<GameConfig> GameConfigSingle;
#define CONFIG_INSTANCE GameConfigSingle::instance()