#include "canvas.h"
#include <QDebug>

Canvas::Canvas()
{
    // Initializations
    sizeX = 32;
    sizeY = 32;
    image = QImage(sizeX, sizeY, QImage::Format_RGB32);

    // Testing setting individual pixels
    for(int i = 0; i< sizeX; i++) {
        for(int j =0; j < sizeY; j++) {
            image.setPixel(i, j, qRgb(100,100, 200));
        }
    }

    pixmap = pixmap.fromImage(image);

    //TODO: Figure out how to make scaling work
//    pixmap.scaled(200, 300);

    qInfo() << "Pixmap defined " << pixmap;

}

QPixmap Canvas::getPixmap() {
    qInfo() << "Returning QPixmap " << pixmap;
    return pixmap;
}

