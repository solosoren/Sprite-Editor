#include "project.h"

Project::Project()
{
    frames.push_back(QImage(gridSizeX, gridSizeY, QImage:: QImage::Format_ARGB32));
    canvas = new Canvas(frames[0]);

    tools = new Tools();

    QObject::connect(canvas, SIGNAL(mousePressed(QPointF)),
                     tools, SLOT(handleMousePress(QPointF)) );

    QObject::connect(canvas, SIGNAL(mouseMoved(QPointF)),
                     tools, SLOT(handleMouseMove(QPointF)) );

    QObject::connect(canvas, SIGNAL(mouseReleased(QPointF)),
                     tools, SLOT(handleMouseRelease(QPointF)) );
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
