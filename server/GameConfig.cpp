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

void GameConfig::init()
{

}

void GameConfig::start()
{

}

int GameConfig::LoadJsonFile(const char *path, Document &d)
{
	JUDGE_RETURN(path == nullptr, EXIT_FAILURE);
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
		return EXIT_FAILURE;
	}
	fclose(fp);
	return 0;
}

int GameConfig::LoadServerConfig(bool bStart /*= false*/)
{
	std::string path = "server/machine.json";
	JUDGE_RETURN(LoadJsonFile(path.c_str(), m_serverConfig) == false, 0);


}

GameConfig::BasicConfig::BasicConfig()
{

}

const Document & GameConfig::BasicConfig::ConstJson() const
{
	return m_doc[m_curVer];
}

Document & GameConfig::BasicConfig::RevertJson()
{
	return m_doc[((m_curVer + 1) % MAX_VERSION_CNT)];
}

const Value& GameConfig::BasicConfig::Find(int key)
{
	return m_null;
}

const Value& GameConfig::BasicConfig::ConstJsonName(const char* key) const
{
	if (key != nullptr)
	{
		return ConstJson()[key];
	}
// 	else
// 	{
// 		return ConstJson().Get<Value>();
// 	}
}

int GameConfig::BasicConfig::CurVersion() const
{
	return m_curVer;
}

int GameConfig::BasicConfig::PrevVersion() const
{
	return ((m_curVer + 1) % MAX_VERSION_CNT);
}

int GameConfig::BasicConfig::Validate(int key)
{
	return 0;
}

void GameConfig::BasicConfig::UpdateVersion()
{
	m_curVer = (m_curVer + 1) % MAX_VERSION_CNT;

}

void GameConfig::BasicConfig::RevertVersion()
{
	m_curVer = (m_curVer + MAX_VERSION_CNT - 1) % MAX_VERSION_CNT;
}

void GameConfig::BasicConfig::ConvertJsonToMap(int key_flag /*= false*/)
{

}

void GameConfig::BasicConfig::LoadCombineFile(const std::string& path, int flag /*= false*/)
{

}

const std::string& GameConfig::BasicConfig::VersionNo() const
{
	return m_strVec[CurVersion()];
}
