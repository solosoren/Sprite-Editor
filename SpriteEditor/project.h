#ifndef PROJECT_H
#define PROJECT_H
#include <QPixmap>
#include <QLabel>
#include "canvas.h"
#include "tools.h"
#include "spriteanimation.h"
#include "colorlabel.h"

class Project: public QObject
{
    Q_OBJECT

public:
    Project();
    virtual ~Project();
    void setCurrentFrame(int frameNumber);
    void createNewFrame();
    Canvas* getCanvas();
    void handleGridlinesToggled();
    void setColorLabel(ColorLabel* label);

public slots:
    void handleImageUpdate(QImage image);
    void handleColorChanged(QColor color);

private:
    //SpriteAnimation animation;
    std::vector<QImage> frames;
    int currentFrame;
    Tools* tools;
    Canvas* canvas;
    ColorLabel* colorLabel;
    QColor selectedColor;
    void setColorLabelColor(QColor color);

};

#endif // PROJECT_H
