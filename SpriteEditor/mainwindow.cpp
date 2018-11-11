#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "frameview.h"
#include <QPixmap>
#include <QDialogButtonBox>
#include <gridsizedialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Open grid size dialog
    GridSizeDialog dialog;
    dialog.setModal(true);
    dialog.exec();

    ui->setupUi(this);

    initializeProject();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete project;
}

void MainWindow::initializeProject()
{
    project = new Project(gridSizeX, gridSizeY);

    project->setColorLabel(ui->leftColorSelectedLabel, ui->rightColorSelectedLabel);
    project->setFrameView(ui->frameTableWidget);

    ui->graphicsView->setScene(project->getCanvas());
    ui->animationView->setScene(project->getAnimation());

    on_penToolButton_clicked(); //set pen tool as initially selected
}

void MainWindow::highlightButton(Global::Tool tool)
{
    switch(tool)
    {
     case Global::Tool::pen:
        ui->penToolButton->setStyleSheet(Global::buttonHighlightFormat);

        ui->brushToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->lineToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->fillToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->eraserToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        break;
     case Global::Tool::brush:
        ui->brushToolButton->setStyleSheet(Global::buttonHighlightFormat);

        ui->penToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->lineToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->fillToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->eraserToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        break;
    case Global::Tool::line:
        ui->lineToolButton->setStyleSheet(Global::buttonHighlightFormat);

        ui->penToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->brushToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->fillToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->eraserToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        break;
    case Global::Tool::fill:
        ui->fillToolButton->setStyleSheet(Global::buttonHighlightFormat);

        ui->penToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->brushToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->lineToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->eraserToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        break;
    case Global::Tool::eraser:
        ui->eraserToolButton->setStyleSheet(Global::buttonHighlightFormat);

        ui->penToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->brushToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->lineToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        ui->fillToolButton->setStyleSheet(Global::buttonNonHighlightFormat);
        break;
    }
}

void MainWindow::on_toggleGridlinesButton_clicked()
{
    project->handleGridlinesToggled();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->fpsLabel->setText(QString::number(value));
    project->handleAnimationSliderValueChanged(value);
}

void MainWindow::on_penToolButton_clicked()
{
    project->setActiveTool(Global::Tool::pen);
    highlightButton(Global::Tool::pen);
}

void MainWindow::on_eraserToolButton_clicked()
{
    project->setActiveTool(Global::Tool::eraser);
    highlightButton(Global::Tool::eraser);
}


void MainWindow::on_brushToolButton_clicked()
{
    project->setActiveTool(Global::Tool::brush);
    highlightButton(Global::Tool::brush);
}


void MainWindow::on_lineToolButton_clicked()
{
    project->setActiveTool(Global::Tool::line);
    highlightButton(Global::Tool::line);
}


void MainWindow::on_fillToolButton_clicked()
{
    project->setActiveTool(Global::Tool::fill);
    highlightButton(Global::Tool::fill);
}

void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save file", QDir::homePath(), "*.ssp");
    project->save(filename);
}

void MainWindow::on_actionLoad_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath(), "*.ssp");
    project->load(filename);
}

void MainWindow::on_actionExport_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Choose Export Path", QDir::homePath(), "*.gif");
    project->exportGIF(filename);
}

void MainWindow::on_frameTableWidget_cellClicked(int row, int column)
{
    if (column == 0)
    {
        project->addNewFrame();
    }
    else
    {
        project->setCurrentFrame(column - 1);
    }
}
