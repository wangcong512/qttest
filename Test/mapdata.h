#ifndef MAPDATA_H
#define MAPDATA_H

#include <QObject>

class MapData : public QObject
{
    Q_OBJECT
public:
    explicit MapData(QObject *parent = 0);
    virtual ~MapData();

    int m_nTiledX;
    int m_nTIledY;
    int m_nPixelX;
    int m_nPixelY;
    int m_nCellX;
    int m_nCellY;
    char *m_grid;//地图数据
    QString m_strMapName;

    void loadData(QString path);
    void saveData();
    void setGridValue(int nX,int nY,int value);

    static MapData& Instance()
    {
        static MapData instance;
        return instance;
    }

signals:

public slots:
};

#endif // MAPDATA_H
