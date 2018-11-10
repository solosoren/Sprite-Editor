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

    QObject::connect(canvas, SIGNAL(mouseLeftPressed(QPointF)),
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

void Project::setCurrentFrame(int frameNumber)
{
    currentFrame = frameNumber;
    canvas->setImage(frames[currentFrame]);
    tools->setImage(frames[currentFrame]);
}

void Project::nextFrame()
{
    int frameNumber = currentFrame < frames.size()-1 ? currentFrame+1 : 0;
    setCurrentFrame(frameNumber);
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
}


/*UI Helpers*/

void Project::setActiveTool(int tool)
{
    tools->setSelectedTool(tool);
}

SpriteAnimation* Project::getAnimation()
{
    return animation;
}

Canvas* Project::getCanvas()
{
    return canvas;
}

void Project::handleGridlinesToggled()
{
    canvas->toggleGridlines();
}

void Project::handleAnimationSliderValueChanged(int value)
{
    animation->setFrameRate(value);
}

void Project::setColorLabel(ColorLabel* leftLabel, ColorLabel* rightLabel)
{
    this->leftColorLabel = leftLabel;
    this->rightColorLabel = rightLabel;

    QObject::connect(leftColorLabel, SIGNAL(colorChanged(QColor, ColorLabel*)),
                     this, SLOT(handleColorChanged(QColor, ColorLabel*)));

    QObject::connect(rightColorLabel, SIGNAL(colorChanged(QColor, ColorLabel*)),
                     this, SLOT(handleColorChanged(QColor, ColorLabel*)));

    // Default starting color
    handleColorChanged(QColor(0, 0, 0), leftColorLabel);
    handleColorChanged(QColor(255, 255, 255), rightColorLabel);
}


/*Slots*/


void Project::handleColorChanged(QColor color, ColorLabel* label)
{
    if(label == leftColorLabel) {
        tools->setLeftSelectedColor(color.rgba());
    }
    if(label == rightColorLabel) {
        tools->setRightSelectedColor(color.rgba());
    }

    QImage image(1, 1, QImage::Format_ARGB32);
    image.setPixelColor(0, 0, color);
    label->setPixmap(QPixmap().fromImage(image.scaled(150, 50)));
}

void Project::updateImage()
{
    canvas->setImage(frames[currentFrame]);
}


/*File IO*/


void Project::save()
{

}

void Project::load(QString filename)
{

}

void Project::exportGIF(QString filename)
{

}
