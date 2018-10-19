#include "LuaMonitor.h"



LuaMonitor::LuaMonitor()
{
}


LuaMonitor::~LuaMonitor()
{
}

lua_State* LuaMonitor::CreateVirLuaSys()
{
	lua_State *l = luaL_newstate();
	luaL_openlibs(l);
	return l;
}

bool LuaMonitor::LoadLuaFile(lua_State *l, const char *path)
{
	if (l == nullptr || path == nullptr)
		return false;
	return luaL_dofile(l, path) == LUA_OK;
}

void LuaMonitor::CloseVirLuaSys(lua_State *l)
{
	if (l == nullptr)
		return;
	lua_close(l);
}
