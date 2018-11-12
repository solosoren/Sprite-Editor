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
    Project(int frameSize);

    virtual ~Project();

    void setFrameView(QTableWidget* tableWidget);

    void setCurrentFrame(int frameNumber);

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

    int framePixelSize;

    FrameView* frameView;

    Tools* tools;

    Canvas* canvas;

    ColorLabel* leftColorLabel;
    ColorLabel* rightColorLabel;

    void setColorLabelColor(QColor color);
    void setNewFrameSize(int frameSize);

};

#endif // PROJECT_H
