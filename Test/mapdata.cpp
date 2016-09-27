#include "mapdata.h"
#include<QFile>
#include<QFileDevice>
#include<QTextStream>

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
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    strContent.append(QString(" --init data\n"));
    strContent.append(QString("%1 = {\n").arg(mapName));
    strContent.append(QString(" tiled_data = {\n"));

    //点阵

    for(int i = 0; i < m_nCellX; i++)
    {
      strContent.append(QString(" "));
      for(int j = 0; j < m_nCellY; j++)
      {
          strContent.append(QString("%1,").arg(0));
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
