#include "luaengine.h"

LuaEngine::LuaEngine(QObject *parent) : QObject(parent)
{


    /* create state */
    L =  luaL_newstate();
    /*load Lua base libraries*/
    luaL_openlibs(L);
    /*load the script*/
    //luaL_dofile(L,"bk.lua");
    /*call the add function*/

    /*cleanup Lua*/

}

LuaEngine::~LuaEngine()
{
    lua_close(L);
}

void LuaEngine::init()
{

}

void LuaEngine::unInit()
{}

lua_State* LuaEngine::getStack()
{
    return L;
}
