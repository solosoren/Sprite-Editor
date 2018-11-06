#include "mainwindow.h"
#include <QApplication>
#include "ui_mainwindow.h"

/* tmp NEED TO BE CHANGED*/
const int PEN_TOOL = 0;
const int ERASER = 1;
const int LINE_TOOL = 2;
const int FILL_TOOL = 3;
const int BRUSH_TOOL = 4;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    window.show();

    return a.exec();
}
