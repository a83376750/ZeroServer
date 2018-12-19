#pragma once

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class LuaMonitor
{
public:
	LuaMonitor();
	~LuaMonitor();


protected:
// 	static lua_State* CreateVirLuaSys();
// 	static bool LoadLuaFile(lua_State *l, const char *path);
// 	static void CloseVirLuaSys(lua_State *l);
};

