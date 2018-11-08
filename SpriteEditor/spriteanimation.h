#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include "mainwindow.h"

using namespace GLOBAL;

class SpriteAnimation: public QGraphicsScene
{
    Q_OBJECT

private:
    std::vector<QImage*>* images;
    int frameRate;
    void animate();

private slots:
    void displayFrame(QPixmap pixmap);

public:
    SpriteAnimation();
    void setImages(std::vector<QImage*>* images);
};

#endif // SPRITEANIMATION_H
