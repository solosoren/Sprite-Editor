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
    static int gridX = 8;
    static int gridY = 8;

    static QPixmap convertImageToPixmap(QImage image) {
         return QPixmap().fromImage(image.scaled(windowSizeX,windowSizeY));
    }

    /* tmp NEED TO BE CHANGED*/
    const int PEN_TOOL = 0;
    const int ERASER = 1;
    const int LINE_TOOL = 2;
    const int FILL_TOOL = 3;
    const int BRUSH_TOOL = 4;
}

#endif // GLOBAL_H
