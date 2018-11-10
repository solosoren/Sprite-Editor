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

    void nextFrame();

    void createNewFrame();

    void setActiveTool(int tool);

    SpriteAnimation* getAnimation();

    Canvas* getCanvas();

    void handleGridlinesToggled();

    void handleAnimationSliderValueChanged(int value);

    void setColorLabel(ColorLabel* leftLabel, ColorLabel* rightLabel);

    void save();

    void load(QString filename);

    void exportGIF(QString filename);

public slots:
    void updateImage();

    void handleColorChanged(QColor color, ColorLabel* label);

private:
    std::vector<QImage*> frames;
    int currentFrame;

    SpriteAnimation* animation;

    Tools* tools;

    Canvas* canvas;

    ColorLabel* leftColorLabel;
    ColorLabel* rightColorLabel;

    void setColorLabelColor(QColor color);

};

#endif // PROJECT_H
