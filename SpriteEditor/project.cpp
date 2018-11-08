#include "project.h"

Project::Project()
{
    frames.push_back(QImage(gridSizeX, gridSizeY, QImage:: QImage::Format_ARGB32));
    currentFrame = 0;
    canvas = new Canvas(frames[currentFrame]);
    animation = new SpriteAnimation();

    tools = new Tools(frames[currentFrame]);

    QObject::connect(canvas, SIGNAL(mousePressed(QPointF)),
                     tools, SLOT(handleMousePress(QPointF)) );

    QObject::connect(canvas, SIGNAL(mouseMoved(QPointF)),
                     tools, SLOT(handleMouseMove(QPointF)) );

    QObject::connect(canvas, SIGNAL(mouseReleased(QPointF)),
                     tools, SLOT(handleMouseRelease(QPointF)) );
    QObject::connect(tools, SIGNAL(updateImage(QImage)),
                     this, SLOT(handleImageUpdate(QImage)) );
}

Project::~Project()
{
    delete canvas;
    delete tools;
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
}
void Project::createNewFrame()
{
    QImage image(gridSizeX, gridSizeY, QImage::Format_ARGB32);
    canvas->initializeEmptyImage(image);
    frames.push_back(image);
}

void Project::handleGridlinesToggled()
{
    canvas->toggleGridlines();
}

void Project::handleImageUpdate(QImage image) {

    frames[currentFrame] = image;
    canvas->setImage(image);
}

void Project::handleAnimationSliderValueChanged(int value)
{
    animation->setFrameRate(value);
}
