#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDialogButtonBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //FlowLayout* flowLayout = new FlowLayout;

    project.setColorLabel(ui->colorSelectedLabel);

    on_penToolButton_clicked();

    ui->graphicsView->setScene(project.getCanvas());
    ui->animationView->setScene(project.getAnimation());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::highlightButton(int button)
{
    switch(button)
    {
     case GLOBAL::PEN:
        ui->penToolButton->setStyleSheet(GLOBAL::buttonHighlightFormat);

        ui->brushToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->lineToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->fillToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->eraserToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        break;
     case GLOBAL::BRUSH:
        ui->brushToolButton->setStyleSheet(GLOBAL::buttonHighlightFormat);

        ui->penToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->lineToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->fillToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->eraserToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        break;
    case GLOBAL::LINE:
        ui->lineToolButton->setStyleSheet(GLOBAL::buttonHighlightFormat);

        ui->penToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->brushToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->fillToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->eraserToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        break;
    case GLOBAL::FILL:
        ui->fillToolButton->setStyleSheet(GLOBAL::buttonHighlightFormat);

        ui->penToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->brushToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->lineToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->eraserToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        break;
    case GLOBAL::ERASER:
        ui->eraserToolButton->setStyleSheet(GLOBAL::buttonHighlightFormat);

        ui->penToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->brushToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->lineToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        ui->fillToolButton->setStyleSheet(GLOBAL::buttonNonHighlightFormat);
        break;
    }
}

void MainWindow::on_toggleGridlinesButton_clicked()
{
    project.handleGridlinesToggled();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->fpsLabel->setText(QString::number(value));
    project.handleAnimationSliderValueChanged(value);
}

void MainWindow::on_penToolButton_clicked()
{
    project.setActiveTool(GLOBAL::PEN);
    highlightButton(GLOBAL::PEN);
}

void MainWindow::on_eraserToolButton_clicked()
{
    project.setActiveTool(GLOBAL::ERASER);
    highlightButton(GLOBAL::ERASER);
}


void MainWindow::on_brushToolButton_clicked()
{
    project.setActiveTool(GLOBAL::BRUSH);
    highlightButton(GLOBAL::BRUSH);
}


void MainWindow::on_lineToolButton_clicked()
{
    project.setActiveTool(GLOBAL::LINE);
    highlightButton(GLOBAL::LINE);
}


void MainWindow::on_fillToolButton_clicked()
{
    project.setActiveTool(GLOBAL::FILL);
    highlightButton(GLOBAL::FILL);
}

void MainWindow::on_newFrameButton_clicked()
{
    project.createNewFrame();
    //QDialogButtonBox button = new QDialogButtonBox(this);
    //ui->verticalLayout_4->addWidget();
}

void MainWindow::on_nextFrame_clicked()
{
    project.nextFrame();
}
