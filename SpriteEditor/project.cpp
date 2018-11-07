#include "project.h"
#include <QDebug>

Project::Project()
{
    canvas = new Canvas();

    QObject::connect(canvas, SIGNAL(mousePressed(QPointF)),
                     this, SLOT(handleMousePress(QPointF)) );

    QObject::connect(canvas, SIGNAL(mouseMoved(QPointF)),
                     this, SLOT(handleMouseMove(QPointF)) );

    QObject::connect(canvas, SIGNAL(mouseReleased(QPointF)),
                     this, SLOT(handleMouseRelease(QPointF)) );
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

//SLOTS

void Project::handleMousePress(QPointF point)
{
    //qInfo() << "Handled Mouse Press at: " << point;
}

void Project::handleMouseMove(QPointF point)
{
    //qInfo() << "Handled Move Press at: " << point;
}

void Project::handleMouseRelease(QPointF point)
{
    //qInfo() << "Handled Release Press at: " << point;
}
