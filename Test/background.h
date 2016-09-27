#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QWidget>
#include "mapdata.h"
#include"mainwindow.h"

class BackGround : public QWidget
{
    Q_OBJECT
public:
    explicit BackGround(QWidget *parent = 0);
    ~BackGround();
public:
    void init(QString mapName);
    void initTiled(QString mapName);
    void paintEvent(QPaintEvent *event);
    int getTiledX();
    int getTiledY();
    void setMainWindow(MainWindow* pMain)
    {
        m_pMainWindow = pMain;
    }

    MainWindow* m_pMainWindow;


signals:

public slots:

private:
    int m_nTiledX;
    int m_nTiledY;
    int m_nPixelX;
    int m_nPixelY;

};

#endif // BACKGROUND_H
