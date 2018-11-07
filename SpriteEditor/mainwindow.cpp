#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "project.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(project.getCanvas());

}

MainWindow::~MainWindow()
{
    delete ui;
}
