#include "project.h"
#include <QDebug>

Project::Project()
{
    //frames.push_back(QImage(gridSizeX, gridSizeY, QImage:: QImage::Format_ARGB32));
    createNewFrame();
    currentFrame = 0;

    canvas = new Canvas(frames[currentFrame]);
    animation = new SpriteAnimation();
    tools = new Tools(frames[currentFrame]);

    QObject::connect(canvas, SIGNAL(mousePressed(QPointF)),
                     tools,  SLOT(handleMousePress(QPointF)) );

    QObject::connect(canvas, SIGNAL(mouseMoved(QPointF)),
                     tools,  SLOT(handleMouseMove(QPointF)) );

    QObject::connect(canvas, SIGNAL(mouseReleased(QPointF)),
                     tools,  SLOT(handleMouseRelease(QPointF)) );

    QObject::connect(tools, SIGNAL(imageUpdated()),
                     this,  SLOT(updateImage()) );
}

Project::~Project()
{
    delete canvas;
    delete tools;
    for (QImage* image : frames)
    {
        delete image;
    }
}

Canvas* Project::getCanvas()
{
    return canvas;
}

SpriteAnimation* Project::getAnimation()
{
    return animation;
}

void Project::setCurrentFrame(int frameNumber)
{
    currentFrame = frameNumber;
    canvas->setImage(frames[frameNumber]);
    tools->setImage(frames[frameNumber]);
}

void Project::createNewFrame()
{
    QImage* image = new QImage(gridSizeX, gridSizeY, QImage::Format_ARGB32);
    // Initializes empty grid
    for(int i = 0; i< gridSizeX; i++) {
        for(int j =0; j < gridSizeY; j++) {
            image->setPixelColor(i, j, QColor(255,255,255,0).rgba());
        }
    }
    frames.push_back(image);
    //canvas->setImage(frames[currentFrame]);
    //tools->setImage(frames[currentFrame]);
}

void Project::handleGridlinesToggled()
{
    canvas->toggleGridlines();
}

void Project::updateImage()
{
    canvas->setImage(frames[currentFrame]);
}


void Project::handleAnimationSliderValueChanged(int value)
{
    animation->setFrameRate(value);
}

void Project::setColorLabel(ColorLabel* label)
{
    colorLabel = label;

    QObject::connect(colorLabel, SIGNAL(colorChanged(QColor)),
                     this, SLOT(handleColorChanged(QColor)));

    // Default starting color
    handleColorChanged(QColor(255, 0, 0));
}

void Project::setActiveTool(int tool)
{
    tools->setSelectedTool(tool);
}

void Project::handleColorChanged(QColor color)
{
    tools->setSelectedColor(color.rgba());
    QImage image(1, 1, QImage::Format_ARGB32);
    image.setPixelColor(0, 0, color);
    colorLabel->setPixmap(QPixmap().fromImage(image.scaled(150, 50)));
}
