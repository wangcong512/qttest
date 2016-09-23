#include "background.h"
#include<QImage>
#include<QLabel>
#include<QPainter>
#include<QtMath>

BackGround::BackGround(QWidget *parent) : QWidget(parent)
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
   int pixelWidth = 935;
   int pixelHeight = 623;
   int nTiledX = qCeil(pixelWidth/256.0);
   int nTiledY = qCeil(pixelHeight/256.0);
   m_nTiledX = nTiledX;
   m_nTiledY = nTiledY;
   QString titedName = QString("%1/%2_%3.jpg").arg(mapName).arg(mapName).arg(nPicIndex);
   QImage tiledImage(titedName);
   do
   {
       bool bHasData = tiledImage.isNull();
       if(!bHasData)
       {
           QLabel *label = new QLabel(this);
           label->setPixmap(QPixmap::fromImage(tiledImage));

          label->setGeometry(nPicIndex%nTiledX,nPicIndex/nTiledY,tiledImage.width(),tiledImage.height());


       }
       else
          break;
       nPicIndex++;
       titedName = QString("%1/%2_%3.jpg").arg(mapName).arg(mapName).arg(nPicIndex);
       if(nPicIndex >= nTiledX*nTiledY)break;

   }while (!tiledImage.isNull());


}
