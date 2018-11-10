#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H

#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include "global.h"

class SpriteAnimation: public QGraphicsScene
{
    Q_OBJECT

private:
    std::vector<QImage*>* images;
    int frameRate;
    void startAnimation();

private slots:
    void displayFrame(QPixmap pixmap);

public:
    SpriteAnimation();
    void setImages(std::vector<QImage*>* images);
    void setFrameRate(int rate);
};

#endif // SPRITEANIMATION_H
