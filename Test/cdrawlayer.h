#ifndef CDRAWLAYER_H
#define CDRAWLAYER_H

#include <QWidget>
#include <QMouseEvent>
#include"mainwindow.h"

class CDrawLayer : public QWidget
{
    Q_OBJECT
public:
    explicit CDrawLayer(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);

    void mouseReleaseEvent(QMouseEvent  *event);
    void mousePressEvent(QMouseEvent  *event);
    void mouseMoveEvent(QMouseEvent  *event);

    void setMainWindow(MainWindow* pMain)
    {
        m_pMainWindow = pMain;
    }

    MainWindow* m_pMainWindow;

signals:

public slots:
};

#endif // CDRAWLAYER_H
