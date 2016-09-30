#include "cdrawlayer.h"
#include "mapdata.h"
#include "common.h"
#include<QtMath>
#include<QPainter>
#include<QMessageBox>
#include"mainwindow.h"

CDrawLayer::CDrawLayer(QWidget *parent) : QWidget(parent)
{

}

void CDrawLayer::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.setPen(Qt::green);
    paint.drawLine(0,50,50,50);


    float nPixelWidth = MapData::Instance().m_nPixelX;
    float nPixelHeight = MapData::Instance().m_nPixelY;
    int nCellWidth = qCeil(nPixelWidth/CELLWIDTH);
    int nCellHeight = qCeil(nPixelHeight/CELLWIDTH);

    for(int i = 0; i < nCellWidth; i++ )
    {
         paint.drawLine(CELLWIDTH*i,this->height() - 0,CELLWIDTH*i,this->height() - nCellHeight*CELLWIDTH);
    }

    for(int i = 0; i < nCellHeight; i++ )
    {
         paint.drawLine(0,this->height() - CELLWIDTH*i,CELLWIDTH*nCellWidth,this->height() - CELLWIDTH*i);
    }

    //绘制块
    paint.setPen(Qt::red);
    for(int i = 0; i < nCellHeight; i++)
       for(int j = 0; j < nCellWidth; j++)
       {
           if(MapData::Instance().m_grid[i*nCellWidth + j] == 1)
           {
               paint.drawLine(j*CELLWIDTH,this->height() - i*CELLWIDTH,(j + 1)*CELLWIDTH,this->height() - (i + 1)*CELLWIDTH);
               paint.drawLine(j*CELLWIDTH,this->height() - (i + 1)*CELLWIDTH,(j + 1)*CELLWIDTH,this->height() - i*CELLWIDTH);

               //draw triangle
           }

       }



}

void CDrawLayer::mouseReleaseEvent(QMouseEvent  *event)
{
    if(event->button()&Qt::LeftButton)
    {
//        QMessageBox *msgBox = new QMessageBox(this);
//        msgBox->setText("The document has been modified.");
//         msgBox->exec();

        QPoint pt = QPoint(event->pos().x(),this->height() - event->pos().y());

        int cellIndex = pt.x()/CELLWIDTH + (pt.y()/CELLWIDTH)*MapData::Instance().m_nCellX;

        if(cellIndex < MapData::Instance().m_nCellX*MapData::Instance().m_nCellY)
        MapData::Instance().m_grid[cellIndex] = 1;
        this->repaint();

    }
    else if(event->button()&Qt::RightButton)
    {
        QPoint pt = QPoint(event->pos().x(),this->height() - event->pos().y());

        int cellIndex = pt.x()/CELLWIDTH + (pt.y()/CELLWIDTH)*MapData::Instance().m_nCellX;

        if(cellIndex < MapData::Instance().m_nCellX*MapData::Instance().m_nCellY)
        MapData::Instance().m_grid[cellIndex] = 0;
        this->repaint();
    }
    else
    {

    }
}
void CDrawLayer::mousePressEvent(QMouseEvent  *event)
{
    if(event->button()&Qt::LeftButton)
    {


    }
    else
    {

    }

}
void CDrawLayer::mouseMoveEvent(QMouseEvent  *event)
{
   QPoint pt = QPoint(event->pos().x(),this->height() - event->pos().y());

    m_pMainWindow->refreshXY(pt);

}
