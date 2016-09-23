#include"background.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDockWidget>
#include <QToolBar>
#include<QMessageBox>
#include<QLabel>
#include <QDebug>
#include<QImageReader>
#include <QPainter>
#include <QColor>
#include<QFileDialog>
 #include <QtCore>
#include <QtMath>
#include<QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //init ui

    QAction *newAct = new QAction(tr("&New"), this);
     newAct->setShortcuts(QKeySequence::New);
     newAct->setStatusTip(tr("Create a new file"));
     connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

     QAction* openAct = new QAction(tr("&Open..."), this);
     openAct->setShortcuts(QKeySequence::Open);
     openAct->setStatusTip(tr("Open an existing file"));
     connect(openAct, &QAction::triggered, this, &MainWindow::open);

     QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
     fileMenu->addAction(newAct);
     fileMenu->addSeparator();
     fileMenu->addAction(openAct);

     fileMenu->addSeparator();

     QToolBar *fileToolBar = this->addToolBar(tr("&File"));
     fileToolBar->addAction(newAct);
     fileToolBar->addAction(openAct);
     fileToolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea);
     addToolBar(Qt::TopToolBarArea, fileToolBar);

     setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
     setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
     setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
     setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

    // QWidget *centralWidget = new QWidget(this);
    //setCentralWidget(centralWidget);

     QLabel *imageLabel = new QLabel;
     QImage image("bk.jpg");

     QSize size = image.size();

     qDebug() <<"size:width"<<size.width();

     imageLabel->setPixmap(QPixmap::fromImage(image));


    QScrollArea* scrollArea = findChild<QScrollArea*>("scrollArea");
    scrollArea->setBackgroundRole(QPalette::Dark);

    BackGround *bk = new BackGround(this);
    bk->initTiled("bk");
    scrollArea->setWidget(bk);


    qDebug() << "Supported formats:" << QImageReader::supportedImageFormats();


    QLineF line(10.0, 80.0, 90.0, 20.0);

    QPainter *parnter =  new QPainter(scrollArea);
    parnter->setPen(QColor(255,0,0));
    parnter->drawLine(line);


    m_strBkName = "bk.jpg";



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.setPen(Qt::red);
    paint.drawLine(0,50,50,50);
}

void MainWindow::newFile()
{

    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setText("The document has been modified.");
     msgBox->exec();

}
void MainWindow::open()
{
//    QMessageBox *msgBox = new QMessageBox(this);
//    msgBox->setText("The document has been modified.");
//     msgBox->exec();


    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "D:/",
                                                     tr("Images (*.png *.xpm *.jpg)"));

}

void MainWindow::on_pushButton_3_clicked()
{
    QImage  image(m_strBkName);
    //块图片生成
    int start_pos = m_strBkName.indexOf(".");
    int end_pos = m_strBkName.lastIndexOf("/");
    if(end_pos == -1) end_pos = 0;
    QString suffix = m_strBkName.mid(start_pos);
    int nSuffixLen = suffix.length();

    QString strPathDirName = m_strBkName.mid(0,start_pos);
    QString strFileName = m_strBkName.mid(end_pos + 1,start_pos - end_pos - 1);
    if(end_pos == 0) strFileName = m_strBkName.mid(end_pos,start_pos - end_pos);
    QDir *temp = new QDir;
    bool exist = temp->exists(strPathDirName);
    if(exist)
        //QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹已经存在！"));
        ;
    else
    {
        bool ok = temp->mkdir(strPathDirName);
//        if( ok )
//            QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹创建成功！"));
    }

    float nTiledWidth = 256.0;
    float nTiledHeight = 256.0;
    int nBlockIndex = 0;
    QString strBlockName;
    float nCellX = qCeil(image.width()/nTiledWidth);
    int nCellY = qCeil(image.height()/nTiledHeight);

    for(int i = 0; i < nCellX;i++)
        for(int j = 0;j < nCellY;j++)

        {
            int tempWidth = 256;
            int tempHeight = 256;
           if((i+1)*nTiledWidth >image.width()) tempWidth = image.width() - i*nTiledWidth;
           if((j+1)*nTiledHeight >image.height()) tempHeight = image.height() - j*nTiledHeight;

            QImage block =  image.copy(i*256,j*256,tempWidth,tempHeight);
            strBlockName.sprintf("%s/%s_%d%s",strPathDirName.toUtf8().data(),strFileName.toUtf8().data(),nBlockIndex,suffix.toUtf8().data());
            //block.save(QString((QTextStream(&strBlockName) << strPathDirName << "_"<< nBlockIndex<<suffix).string()->data()));
            block.save(strBlockName);
            nBlockIndex++;


        }









}
