#ifndef PROJECT_H
#define PROJECT_H

#include <QPixmap>
#include <QLabel>
#include <QThread>
#include <QFileDialog>
#include <QTextStream>
#include "canvas.h"
#include "tools.h"
#include "spriteanimation.h"
#include "colorlabel.h"
#include "frameview.h"


class Project: public QObject
{
    Q_OBJECT

public:
    Project();

    virtual ~Project();

    void setFrameView(QTableWidget* tableWidget);

    void setCurrentFrame(int frameNumber);

    void nextFrame();

    QImage* createNewFrame();

    void addNewFrame();

    void setActiveTool(Global::Tool tool);

    SpriteAnimation* getAnimation();

    Canvas* getCanvas();

    void handleGridlinesToggled();

    void handleAnimationSliderValueChanged(int value);

    void setColorLabel(ColorLabel* leftLabel, ColorLabel* rightLabel);

    void save(QString filename);

    void load(QString filename);

    void exportGIF(QString filename);

public slots:
    void updateImage();

    void handleColorChanged(QColor color, ColorLabel* label);

    void updatePreviewImage();

private:
    std::vector<QImage*> frames;
    QImage* previewImage;
    int currentFrame;

    SpriteAnimation* animation;
    QThread* animationThread;

    FrameView* frameView;

    Tools* tools;

    Canvas* canvas;

    ColorLabel* leftColorLabel;
    ColorLabel* rightColorLabel;

    void setColorLabelColor(QColor color);

};

#endif // PROJECT_H
