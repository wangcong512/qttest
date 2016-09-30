#ifndef LUAENGINE_H
#define LUAENGINE_H

#include <QObject>

extern "C"{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

class LuaEngine : public QObject
{
    Q_OBJECT
public:
    explicit LuaEngine(QObject *parent = 0);
    ~LuaEngine();
    static LuaEngine& Instance()
    {
        static LuaEngine instance;
        return instance;
    }
    void init();
    void unInit();
    lua_State* getStack();

signals:

public slots:


private:
   lua_State *L;
};

#endif // LUAENGINE_H
