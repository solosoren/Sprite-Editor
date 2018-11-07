#include "project.h"

Project::Project()
{
    canvas = new Canvas();
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
    for (QImage* image : frames)
    {
        delete image;
    }
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
    frames.push_back(canvas->makeNewEmptyImage());
}
