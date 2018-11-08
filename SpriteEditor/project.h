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

    SpriteAnimation* getAnimation();

    void handleGridlinesToggled();

    void handleAnimationSliderValueChanged(int value);

    void setColorLabel(ColorLabel* label);

    void setActiveTool(int tool);

public slots:
    void updateImage();

    void handleColorChanged(QColor color);

private:
    std::vector<QImage> frames;
    int currentFrame;

    SpriteAnimation* animation;

    Tools* tools;

    Canvas* canvas;

    ColorLabel* colorLabel;
    void setColorLabelColor(QColor color);

};

#endif // PROJECT_H
