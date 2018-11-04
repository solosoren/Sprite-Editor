#ifndef CANVAS_H
#define CANVAS_H
#include <QPixmap>

class Canvas  : public QObject
{
    Q_OBJECT

    public:
        Canvas();
        QPixmap getPixmap();

    private:
        QPixmap pixmap;
        QImage image;
        int sizeX;
        int sizeY;
};

#endif // CANVAS_H
