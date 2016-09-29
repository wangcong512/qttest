#include "background.h"
#include<QImage>
#include<QLabel>
#include<QPainter>
#include<QtMath>
#include "cdrawlayer.h"
#include"common.h"

BackGround::BackGround(QWidget *parent) : QWidget(parent)
  ,m_pMainWindow(0)
{

}
BackGround::~BackGround()
{

}

void BackGround::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.setPen(Qt::red);
    paint.drawLine(0,50,50,50);


}

void BackGround::init(QString mapName)
{


}

void BackGround::initTiled(QString mapName)
{
   int nPicIndex = 0;
   int pixelWidth = 1440;
   int pixelHeight = 900;
   int nTiledX = qCeil(pixelWidth/256.0);
   int nTiledY = qCeil(pixelHeight/256.0);
   m_nTiledX = nTiledX;
   m_nTiledY = nTiledY;

   MapData::Instance().m_nTiledX = nTiledX;
   MapData::Instance().m_nTIledY = nTiledY;
   MapData::Instance().m_nPixelX = pixelWidth;
   MapData::Instance().m_nPixelY = pixelHeight;
   MapData::Instance().m_nCellX = qCeil(pixelWidth/CELLWIDTH);
   MapData::Instance().m_nCellY = qCeil(pixelHeight/CELLWIDTH);
   MapData::Instance().loadData("");


   this->setGeometry(0,0,nTiledX*256,nTiledY*256);
   this->setFixedSize(pixelWidth,pixelHeight);
   //int localwidht = this->width();

   QString titedName = QString("%1/%2_%3.jpg").arg(mapName).arg(mapName).arg(nPicIndex);
   QImage tiledImage(titedName);
   do
   {
       bool bHasData = tiledImage.isNull();
       if(!bHasData)
       {
           QLabel *label = new QLabel(this);
           label->setPixmap(QPixmap::fromImage(tiledImage));

           label->setGeometry(qFloor(nPicIndex/nTiledY)*256,(nPicIndex%nTiledY)*256,tiledImage.width(),tiledImage.height());


       }
       else
          break;
       nPicIndex++;
       titedName = QString("%1/%2_%3.jpg").arg(mapName).arg(mapName).arg(nPicIndex);
       tiledImage.load(titedName);
       if(nPicIndex >= nTiledX*nTiledY)break;

   }while (!tiledImage.isNull());

   //

   CDrawLayer *layer = new CDrawLayer(this);
   layer->setMainWindow(m_pMainWindow);
   layer->setGeometry(0,0,nTiledX*256,nTiledY*256);
   layer->setFixedSize(pixelWidth,pixelHeight);
   layer->setMouseTracking(true);


}

int BackGround::getTiledX()
{
    return m_nTiledX;
}

int BackGround::getTiledY()
{
    return m_nTiledY;

}
