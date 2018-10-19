
#include "ObjectPool.h"
#include "TimeValue.h"
#include "GameConfig.h"
#include "ProtoInner001.pb.h"
#include "Sender.h"

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

void LoadLuaTest()
{
	lua_State *l = luaL_newstate();
	luaL_openlibs(l);
	luaL_dofile(l, "test.lua");
	lua_close(l);
}

using namespace rapidjson;
void TestLoadConfig()
{
	Document *d = new Document();
	CONFIG_INSTANCE->LoadJsonFile("config/server/special_debug.json", *d);
	Value &server_list = (*d)["server_list"];
	Value server_list_arr = server_list.GetArray();

	for (auto it = server_list_arr.Begin(); it != server_list_arr.End(); ++it)
		printf("%s\n", (*it)["service"].GetString());
}

void testProtoMsg()
{
	ProtoServerDetail *detail = new ProtoServerDetail;
	detail->set_id(1);
	detail->set_name("hello");
	printf("%s", detail->Utf8DebugString().c_str());
	delete detail;
}

void testZeromq()
{
	Sender sender;
	sender.create_detail(1, "127.0.0.1", 9998);
	sender.connect_svc(ZMQ_STREAM);

}

struct A
{
	A() {}
	~A() {}
	void reset() {};
};

#include <mutex>
void testObjectPool()
{
	ObjectPool<A, NullMutex> obj;
	obj.resize(2);
	A *i = obj.pop();
	obj.push(i);
}

#include "SpinLock.h"
void testSpinLock()
{
	SpinLock l;
	l.lock();
	l.unlock();
}

int main()
{
	TestLoadConfig();
	testProtoMsg();
	testZeromq();
	LoadLuaTest();
	testObjectPool();
	testSpinLock();
	return 0;
}