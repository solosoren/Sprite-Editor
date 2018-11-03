#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    int sizeX = 600;
//    int sizeY = 600;

//    QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32);

//    for(int i = 0; i<sizeX; i++) {
//        for(int j =0; j < sizeY; j++) {
//            image.setPixel(i, j, qRgb(100,100, 200));
//        }
//    }

//    QGraphicsScene *graphics = new QGraphicsScene(this);

//    graphics->addPixmap(QPixmap::fromImage(image));
//    ui->graphicsView->setScene(graphics);
}

MainWindow::~MainWindow()
{
    delete ui;
}
