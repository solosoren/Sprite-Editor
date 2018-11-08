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

    void on_penToolButton_clicked();

    void on_eraserToolButton_clicked();

    void on_brushToolButton_clicked();

    void on_lineToolButton_clicked();

    void on_fillToolButton_clicked();

private:
    Ui::MainWindow* ui;
    Project project;
    void highlightButton(int button);

friend int main(int argc, char *argv[]);
};

#endif // MAINWINDOW_H
