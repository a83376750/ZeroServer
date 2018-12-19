#pragma once

#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stdint.h>
#include <thread>
#include <chrono>

#include "glog/logging.h"


using namespace std;

#define SERVICE_NAME_LOG    		"log"
#define SERVICE_NAME_LOGIC  		"logic"
#define SERVICE_NAME_SAND   		"sand"
#define SERVICE_NAME_MAP    		"map"
#define SERVICE_NAME_CHAT   		"chat"
#define SERVICE_NAME_AUTH   		"auth"
#define SERVICE_NAME_GATE   		"gate"

#define INNER_ADDRESS				"127.0.0.1"

#define ZERO_MEMORY(DES, LENGTH) ::memset(DES, 0, LENGTH)
#define ARRAY_LENGTH(ARRAY)	(sizeof(ARRAY) / sizeof(ARRAY[0]))
#define DYNAMIC_CAST(TYPE, DES_VAR, SRC_VAR) TYPE DES_VAR = dynamic_cast<TYPE>(SRC_VAR)
#define SLEEP_SEC(s) std::this_thread::sleep_for(std::chrono::seconds(s));
#define SLEEP(s) std::this_thread::sleep_for(std::chrono::milliseconds(s));

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

enum SERVER_TYPE
{
	SERVER_DAEMON = 0,
	SERVER_LOGIC = 1,
	SERVER_CHAT = 2,
	SERVER_LOG = 3,
	SERVER_MAP = 4,
	SERVER_SAND = 5,
	SERVER_GATE = 6,
	SERVER_AUTH = 7,

	SERVER_TYPE_END
};
