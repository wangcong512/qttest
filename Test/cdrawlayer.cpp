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
    paint.setPen(Qt::red);
    paint.drawLine(0,50,50,50);


    float nPixelWidth = MapData::Instance().m_nPixelX;
    float nPixelHeight = MapData::Instance().m_nPixelY;
    int nCellWidth = qCeil(nPixelWidth/CELLWIDTH);
    int nCellHeight = qCeil(nPixelHeight/CELLWIDTH);

    for(int i = 0; i < nCellWidth; i++ )
    {
         paint.drawLine(CELLWIDTH*i,0,CELLWIDTH*i,nCellHeight*CELLWIDTH);
    }

    for(int i = 0; i < nCellHeight; i++ )
    {
         paint.drawLine(0,CELLWIDTH*i,CELLWIDTH*nCellWidth,CELLWIDTH*i);
    }


}

void CDrawLayer::mouseReleaseEvent(QMouseEvent  *event)
{
    if(event->button()&Qt::LeftButton)
    {
        QMessageBox *msgBox = new QMessageBox(this);
        msgBox->setText("The document has been modified.");
         msgBox->exec();
    }
    else
    {

    }
}
void CDrawLayer::mousePressEvent(QMouseEvent  *event)
{

}
void CDrawLayer::mouseMoveEvent(QMouseEvent  *event)
{
   QPoint pt =  event->pos();

    m_pMainWindow->refreshXY(pt);

}
