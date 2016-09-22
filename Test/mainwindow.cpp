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
    scrollArea->setWidget(imageLabel);


    qDebug() << "Supported formats:" << QImageReader::supportedImageFormats();


    QLineF line(10.0, 80.0, 90.0, 20.0);

    QPainter *parnter =  new QPainter(scrollArea);
    parnter->setPen(QColor(255,0,0));
    parnter->drawLine(line);



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
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setText("The document has been modified.");
     msgBox->exec();
}
