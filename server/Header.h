#pragma once

#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define GAME_SPACE_BEGIN namespace game_space {
#define GAME_SPACE_END }

#define SERVICE_NAME_LOG    		"log"
#define SERVICE_NAME_LOGIC  		"logic"
#define SERVICE_NAME_SAND   		"sand"
#define SERVICE_NAME_MAP    		"map"
#define SERVICE_NAME_CHAT   		"chat"
#define SERVICE_NAME_AUTH   		"auth"
#define SERVICE_NAME_GATE   		"gate"

#define ZERO_MEMORY(DES, LENGTH) ::memset(DES, 0, LENGTH)
#define ARRAY_LENGTH(ARRAY)	(sizeof(ARRAY) / sizeof(ARRAY[0]))
#define DYNAMIC_CAST(TYPE, DES_VAR, SRC_VAR) TYPE DES_VAR = dynamic_cast<TYPE>(SRC_VAR)

#define JUDGE_RETURN(CONDITION, RETURN) \
    if (CONDITION)\
    {\
        return RETURN;\
    }

#define JUDGE_CONTINUE(CONDITION) \
    if (CONDITION)\
    {\
        continue;\
    }

#define JUDGE_BREAK(CONDITION) \
    if (CONDITION)\
    {\
        break;\
    }

#define SAFE_DELETE(P)	\
	if (P != 0) \
	{ \
		delete P; \
		P = nullptr; \
	}


struct ServerDetail
{
	int m_index;
	int m_type;
	int m_isTravel;

	string m_name;
	string m_machine;
	set<int> m_sceneList;

	int m_lineId;  // 网关从0开始, 兼容没分线的
	string m_address;
	string m_domain;
	int m_innerPort;
	int m_outerPort;
	int m_travelPort;

	ServerDetail()
	{
		ServerDetail::reset();
	}

	void reset()
	{
		this->m_index = -1;
		this->m_type = 0;
		this->m_name.clear();
		this->m_machine.clear();
		this->m_sceneList.clear();
		this->m_lineId = 0;
		this->m_address.clear();
		this->m_domain.clear();
		this->m_innerPort = 0;
		this->m_outerPort = 0;
		this->m_travelPort = 0;
		this->m_isTravel = false;
	}

	bool need_connect() const
	{
		if (this->m_innerPort <= 0)
		{
			return false;
		}

		if (this->m_address.empty() == true)
		{
			return false;
		}

		return true;
	}
	bool need_reconnect_travel()
	{
		return true;
	}
	bool need_reconnect_channel()
	{
		return true;
	}
};

struct NullMutex
{
	NullMutex() {}
	~NullMutex() {}
	virtual void lock() {}
	virtual void unlock() {}
};