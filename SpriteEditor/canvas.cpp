#include "canvas.h"
#include <QDebug>

Canvas::Canvas()
{
    /* Initializations */

    // Window sizes
    sizeX = 600;
    sizeY = 600;

    // Qimage size is the size of the grid
    image = QImage(5, 5, QImage::Format_RGB32);

    // Testing setting individual pixels
    for(int i = 0; i< 2; i++) {
        for(int j =0; j < 2; j++) {
            image.setPixel(i, j, qRgb(100*i,100*j, 200));
        }
    }

    //Instead of scaling pixmap, scale qimage
    pixmap = pixmap.fromImage(image.scaled(sizeX,sizeY));

    qInfo() << "Pixmap defined " << pixmap;

}

QPixmap Canvas::getPixmap() {
    qInfo() << "Returning QPixmap " << pixmap;
    return pixmap;
}

/***SLOTS***/

void Canvas::setPixel(QPoint pos, QRgb rgb)
{
    image.setPixel(pos, rgb);
    qInfo() << "setPixel Called" << pos;
}
