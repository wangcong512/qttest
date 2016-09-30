#include "mainwindow.h"
#include "background.h"
#include <QApplication>

extern "C"{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#include"luaengine.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //app init
    LuaEngine::Instance().init();

    MainWindow w;
    w.show();



    return a.exec();
}
