
#include "ObjectPool.h"
#include "TimeValue.h"
#include "GameConfig.h"
#include "ProtoInner001.pb.h"
#include "Sender.h"

// extern "C"
// {
// #include "lua.h"
// #include "lualib.h"
// #include "lauxlib.h"
// }

// int traceback(lua_State *L)
// {
// 	const char *msg = lua_tostring(L, -1);
// 	if (msg)
// 	{
// 		luaL_traceback(L, L, msg, 1);
// 	}
// 	else
// 	{
// 		lua_pushliteral(L, "no message");
// 	}
// 	return 0;
// }

void LoadLuaTest()
{
// 	lua_State *l = luaL_newstate();
// 	luaL_openlibs(l);
// 	int err = luaL_dofile(l, "test.lua");
// 	if (err == 1)
// 	{
// 		const char *str = lua_tostring(l, -1);
// 		printf("load lua error:%s\n", str);
// 		traceback(l);
// 	}
// 	lua_close(l);
}

using namespace rapidjson;
void TestLoadConfig()
{
	Document *d = new Document();
	GC::instance()->LoadJsonFile("config/server/special_debug.json", *d);
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

#include "Reader.h"
void testZeromq()
{
// 	NET::Sender sender;
// 	sender.CreateDetail(1, "127.0.0.1", 9998);
// 	sender.ConnectSvc(ZMQ_STREAM);
// 	const char *str = "hello";
// 	sender.send((void*)str, 6);
// 
// 	NET::Reader reader;
// 	char *buffer = new char[1024];
// 	while (1)
// 	{
// 		int rc = reader.recv(buffer);
// 		if (rc == 0)
// 		{
// 			printf("%s\n", buffer);
// 			break;
// 		}
// 	}
}

// struct A
// {
// 	A() {}
// 	~A() {}
// 	void reset() {};
// };
// 
// #include <mutex>
// void testObjectPool()
// {
// 	ObjectPool<A, std::mutex> obj;
// 	obj.resize(2);
// 	A *i = obj.pop();
// 	obj.push(i);
// }

#include "ActorMonitor.h"
#include "ThreadPool.h"

void testThreadPool()
{
	ThreadPool threadPool;
	threadPool.SetMaxQueueSize(10);
	threadPool.start(10);
	auto task = bind(&ActorMonitor::Handle, ACTOR_MONITOR);
	int i = 10;
	while (i--)
	{
		threadPool.run(task);
		SLEEP(10000);
	}
	
	threadPool.stop();
}

#include "DebugServer.h"
void testDebugLoop()
{
	DS::instance()->init();
	DS::instance()->start();
}

void allTest()
{
	TestLoadConfig();
	testProtoMsg();
	testZeromq();
	LoadLuaTest();
	//testObjectPool();
	testThreadPool();
	testDebugLoop(); 
}

#include "SR.h"
#include <thread>



#include "ServerString.h"
void testString()
{
	SString s;
	s = "hello";
	SString t;
	t = "world";
	s.swap(t);
	// 	s.append("world");
	// 	printf("%s", s.c_str());
}

#include "Sort.h"

void testSort()
{
	int a = 0;
	int rand_count = rand() % 50;
	int *array = new int[rand_count];
	for(int i = 0; i < rand_count; ++i)
	{
		array[i] = rand() % 100;
	}

// 	printf("%lld\n", TimeValue::GetTime());
// 	GameSort::BucketSort(array, sizeof(array) / sizeof(int), 20);
	printf("%lld\n", TimeValue::GetTime());
	//GameSort::QuickSort(array, 0, ARRAY_LENGTH(array) - 1);
	GameSort::BubbleSort(array, rand_count);
	printf("%lld\n", TimeValue::GetTime());
	//GameSort::quickSort_b(array, 0, ARRAY_LENGTH(array) - 1);

	for(int i = 0; i < rand_count; ++i)
	{
		printf("%d\n", array[i]);
	}
}

void getMalloc(char *p)
{
	p = new char[100];
}

void getMal(char **p)
{
	*p = new char[100];
}

class A
{
public:
	A() { std::cout << "a" << std::endl; }
	virtual ~A() { std::cout << "~a" << std::endl; }
};

class B : public A
{
public:
	B() { this->reset(); }
	virtual ~B() { std::cout << "~b" << std::endl; }
	void reset()
	{
		//memset(this, 0, sizeof(*this));
	}
	int a;
};

void testLog()
{
// 	google::InitGoogleLogging(argv[0]);
// 	google::SetLogDestination(google::GLOG_INFO, "./log/");
// 	LOG(INFO) << "start";

//	LoadLuaTest();

// 	char *p = NULL;
// 	getMal(&p);
// 	strcpy_s(p, 100, "hello");

// 	char *str = new char[100];
// 	strcpy_s(str, 100, "hello");
// 	delete[] str;
// 
// 	strcpy_s(str, 100, "wolrd");
// 	printf("%s", str);

//	testSort();

//	testSR();
//  	DEBUG_SERVER->init();
//  	DEBUG_SERVER->start();
}

//main 函数之前会构造静态全局变量
//static A a;

typedef void(*free_fn)(void *p);
struct nn_c
{
	uint32_t n;
	size_t s;
	free_fn ffn;
};

void nn_i(uint8_t *buf, uint32_t val)
{
	buf[0] = (uint8_t)(((val) >> 24) & 0xff);
	buf[1] = (uint8_t)(((val) >> 16) & 0xff);
	buf[2] = (uint8_t)(((val) >> 8) & 0xff);
	buf[3] = (uint8_t)(val & 0xff);
}

void* getData(nn_c *self)
{
	return ((uint8_t*)(self + 1)) + 2 * sizeof(uint32_t);
}

#include "nn.h"
#include "pair.h"
void testMalloc()
{
	int s = sizeof(nn_c) + 2 * sizeof(uint32_t);
	nn_c *p = nullptr;
	int targetSize = 10;

	p = (nn_c*)malloc(s + targetSize);
	nn_i((uint8_t*)((uint32_t*)(p + 1)), 0);

	nn_i((uint8_t*)(((uint32_t*)(p + 1)) + 1), 0xdeadcafe);

	void *sData = getData(p);
}

void testgLog(char **argv)
{
	google::InitGoogleLogging(argv[0]);
	google::SetLogDestination(google::GLOG_INFO, "./log/");
}

#include "GateMonitor.h"
int main(int argc, char **argv)
{

	DS::instance()->init();
	DS::instance()->start();
	while (1) {}
 	return 0;
}