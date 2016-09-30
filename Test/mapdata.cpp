#include "mapdata.h"
#include<QFile>
#include<QFileDevice>
#include<QTextStream>
#include"luaengine.h"
#include<QDebug>

MapData::MapData(QObject *parent) : QObject(parent)
  ,m_grid(NULL)
{

}

MapData::~MapData()
{
    if(m_grid != 0) delete[] m_grid;
}

void MapData::loadData(QString path)
{
    delete [] m_grid;
    int gridCount = (m_nCellX + 1)*(m_nCellY + 1);
    m_grid = new char[gridCount];
    memset(m_grid,0,gridCount);


    lua_State *ls = LuaEngine::Instance().getStack();
    luaL_dofile(ls,"bk.lua");

    lua_getglobal(ls,"bk");
    int ret = lua_gettop(ls);
    if(ret > 0)
    {
        ret = lua_istable(ls,ret);
        if(ret == 1)
        {
//            lua_pushinteger(ls,1);
//            lua_gettable(ls,2);
//            int nValue = lua_tointeger(ls,-1);
//            if(nValue > 0)
//            {
//                lua_pop(ls,-1);
//            }

            lua_pushstring(ls,"tiled_data");
            lua_gettable(ls,-2);

            int nIndex = 0;

            lua_pushnil(ls);  /* first key */
            while (lua_next(ls, -2) != 0) {

              char temp_value = (char) lua_tointeger(ls,-1);

              MapData::Instance().m_grid[nIndex] = temp_value;


              nIndex++;


              lua_pop(ls,1);
            }




        }
        else
        {
            qDebug() << "not table";
        }

    }
    else
    {
        qDebug() << "not has value bk";
    }


}

void MapData::setGridValue(int nX,int nY,int value)
{

}

void MapData::saveData()
{

    QString strContent;
    m_strMapName = "bk";
    QString mapName = m_strMapName;

    QFile file(QString("%1.lua").arg(mapName));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    strContent.append(QString(" --init data\n"));
    strContent.append(QString("%1 = {\n").arg(mapName));
    strContent.append(QString(" tiled_data = {\n"));

    //点阵

    for(int i = 0; i < m_nCellY; i++)
    {
      strContent.append(QString(" "));
      for(int j = 0; j < m_nCellX; j++)
      {
          int nValue = m_grid[i*m_nCellX + j];
          strContent.append(QString("%1,").arg(nValue));
      }
      strContent.append(QString("\n"));
    }


    strContent.append(QString(" }\n"));

    strContent.append("}\n");


    QTextStream out(&file);
    out.setCodec("UTF-8");

    out<< strContent.toUtf8();

    while (!file.atEnd()) {
        QByteArray line = file.readLine();

    }

}
