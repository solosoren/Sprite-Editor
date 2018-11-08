#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPixmap>
#include "project.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_toggleGridlinesButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow* ui;
    Project project;

friend int main(int argc, char *argv[]);
};

#endif // MAINWINDOW_H
