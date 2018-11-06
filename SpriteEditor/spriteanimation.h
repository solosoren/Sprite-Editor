#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H
#include <QObject>
#include <QPixmap>
#include <QTimer>
#include "mainwindow.h"

using namespace GLOBAL;

class SpriteAnimation: public QObject
{
    Q_OBJECT

private:
    std::vector<QImage*>* images;
    int frameRate;
    bool imagesDidChange;
    void animate();

private slots:
    void displayFrame(QPixmap* pixmap);

public:
    SpriteAnimation(std::vector<QImage*>& images);
    void imagesDidUpdate();

};

#endif // SPRITEANIMATION_H
