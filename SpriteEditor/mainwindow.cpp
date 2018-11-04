#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Canvas canvas;

    QGraphicsScene *graphics = new QGraphicsScene(this);

    graphics->addPixmap(canvas.getPixmap());
    ui->graphicsView->setScene(graphics);

}

MainWindow::~MainWindow()
{
    delete ui;
}
