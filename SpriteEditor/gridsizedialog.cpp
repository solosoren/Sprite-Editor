#include "gridsizedialog.h"
#include "ui_gridsizedialog.h"
#include <global.h>

GridSizeDialog::GridSizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GridSizeDialog)
{
    ui->setupUi(this);
}

GridSizeDialog::~GridSizeDialog()
{
    delete ui;
}

void GridSizeDialog::on_gridSizeSlider_valueChanged(int value)
{
    ui->gridSizeLabel->setText(QString::number(value));
    gridSizeX = value;
    gridSizeY = value;
}

void GridSizeDialog::on_okButton_clicked()
{
    this->close();
}
