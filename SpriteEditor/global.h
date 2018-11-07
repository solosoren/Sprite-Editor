#ifndef GLOBAL_H
#define GLOBAL_H

#include <QPixmap>

/* define tools */
const int PEN_TOOL = 0;
const int ERASER = 1;
const int LINE_TOOL = 2;
const int FILL_TOOL = 3;
const int BRUSH_TOOL = 4;

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
        QPixmap scaledMap = QPixmap().fromImage(image.scaled(windowSizeX,windowSizeY));
        QImage scaledImage = scaledMap.toImage();

        // "pixel" grid size = (windowSizeX / gridX) and (windowSizeY / gridY)
        for(int x = 0; x < windowSizeX; x++) {
            // Vertical
            if((x % (windowSizeX / gridSizeX)) == 0) {
                for(int y = 0; y < windowSizeY; y++) {
                    scaledImage.setPixelColor(x, y, QColor(0, 0, 0));
                }
            }

            // Horizontal
            for(int y = 0; y < windowSizeY; y+=(windowSizeY/ gridSizeY)) {
                scaledImage.setPixelColor(x, y, QColor(0,0,0));
            }
        }

        return QPixmap().fromImage(scaledImage);
    }

    /* tmp NEED TO BE CHANGED*/
    const int PEN_TOOL = 0;
    const int ERASER = 1;
    const int LINE_TOOL = 2;
    const int FILL_TOOL = 3;
    const int BRUSH_TOOL = 4;
}

#endif // GLOBAL_H
