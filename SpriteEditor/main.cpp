#include "mainwindow.h"
#include <QApplication>
#include "framecontroller.h"
#include "canvas.h"
#include "ui_mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    //ported from mainwindow
    Canvas canvas;
    //FrameController* frameController = new FrameController(&window);
    FrameController frameController(&window);
    frameController.addPixmap(canvas.getPixmap());
    window.ui->graphicsView->setScene(&frameController);

    QObject::connect(&frameController, SIGNAL(pixelClicked(QPoint, QRgb)),
                     &canvas,          SLOT(setPixel(QPoint, QRgb)) );

    window.show();

    return a.exec();
}
