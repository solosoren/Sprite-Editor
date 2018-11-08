#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "project.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(project.getCanvas());
    ui->animationView->setScene(project.getAnimation());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toggleGridlinesButton_clicked()
{
    project.handleGridlinesToggled();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    project.handleAnimationSliderValueChanged(value);
}
