#ifndef GLOBAL_H
#define GLOBAL_H

#include <QPixmap>

namespace GLOBAL{

    // Window sizes
    static int windowSizeX = 600;
    static int windowSizeY = 600;

    // Grid sizes
    static int gridSizeX = 8;
    static int gridSizeY = 8;

    static QPixmap convertImageToPixmap(QImage image) {
         return QPixmap().fromImage(image.scaled(windowSizeX,windowSizeY));
    }

    static QPixmap convertImageToPixmapWithGridLines(QImage image) {
        QImage scaledImage = image.scaled(windowSizeX, windowSizeY);

        // "pixel" grid size = (windowSizeX / gridX) and (windowSizeY / gridY)
        for(int x = 0; x < windowSizeX; x++) {
            // Vertical
            if((x % (windowSizeX / gridSizeX)) == 0) {
                for(int y = 0; y < windowSizeY; y++) {
                    scaledImage.setPixelColor(x, y, QColor(0, 0, 0).rgba());
                }
            }

            // Horizontal
            for(int y = 0; y < windowSizeY; y+=(windowSizeY/ gridSizeY)) {
                scaledImage.setPixelColor(x, y, QColor(0, 0, 0).rgba());
            }
        }

        return QPixmap().fromImage(scaledImage);
    }

    const QString buttonHighlightFormat = QString("background-color: %1").arg(QColor(Qt::green).name());
    const QString buttonNonHighlightFormat = QString("background-color: %1").arg(QColor(Qt::white).name());

    /* tmp NEED TO BE CHANGED*/
    const int PEN = 0;
    const int ERASER = 1;
    const int LINE = 2;
    const int FILL = 3;
    const int BRUSH = 4;
}

#endif // GLOBAL_H
