#include "project.h"

Project::Project()
{

}

void Project::createNewFrame()
{
    frames.push_back(Canvas());
}

void Project::setCurrentFrame(int frameNumber)
{
    currentFrame = frameNumber;
    //put current frame onto display...
}
