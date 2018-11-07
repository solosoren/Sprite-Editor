#include "project.h"

Project::Project()
{
    canvas = new Canvas();
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
    frames.push_back(new QImage());
}
