#include "project.h"

Project::Project()
{

}

void Project::createNewFrame()
{
    frames.push_back(Canvas());
}

void Project::setPixel(int x, int y, QRgb rgbColor)
{
    frames[currentFrame].setPixel(x, y, rgbColor);
}
