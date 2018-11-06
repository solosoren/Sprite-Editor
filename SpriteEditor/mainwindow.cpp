#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Canvas *canvas = new Canvas();

    ui->graphicsView->setScene(canvas);

}

MainWindow::~MainWindow()
{
    delete ui;
}
