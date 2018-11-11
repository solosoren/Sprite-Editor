#include "project.h"
#include <QDebug>


Project::Project()
{
    addNewFrame();
    previewImage = createNewFrame();
    currentFrame = 0;

    canvas = new Canvas(frames[currentFrame]);
    animation = new SpriteAnimation();
    animation->setImages(&frames);
    //animationThread = new QThread();
   //animation->moveToThread(animationThread);
    //animationThread->start();

    tools = new Tools(frames[currentFrame], previewImage);



    QObject::connect(canvas, SIGNAL(mousePressed(int, QPointF)),
                     tools,  SLOT(handleMousePress(int, QPointF)) );

    QObject::connect(canvas, SIGNAL(mouseMoved(int, QPointF)),
                     tools,  SLOT(handleMouseMove(int, QPointF)) );

    QObject::connect(canvas, SIGNAL(mouseReleased(int, QPointF)),
                     tools,  SLOT(handleMouseRelease(int, QPointF)) );

    QObject::connect(tools, SIGNAL(imageUpdated()),
                     this,  SLOT(updateImage()) );

    QObject::connect(tools, SIGNAL(previewImageUpdated()),
                     this,  SLOT(updatePreviewImage()) );
}

Project::~Project()
{
    delete canvas;
    delete tools;
    for (QImage* image : frames) { delete image; }

   // animationThread->wait();
   // delete animationThread;
    delete animation;
    delete frameView;
}

void Project::setFrameView(QTableWidget* widget)
{
    this->frameView = new FrameView(widget, &frames);
}

void Project::setCurrentFrame(int frameNumber)
{
    frameView->updateFrame(currentFrame);
    currentFrame = frameNumber;
    canvas->setImage(frames[currentFrame]);
    tools->setImage(frames[currentFrame]);
}

//void Project::nextFrame()
//{
//    int frameNumber = currentFrame < frames.size()-1 ? currentFrame+1 : 0;
//    qInfo() << frameNumber;
//    setCurrentFrame(frameNumber);
//}

QImage* Project::createNewFrame()
{
    QImage* image = new QImage(Global::gridSizeX, Global::gridSizeY, QImage::Format_ARGB32);
    // Initializes empty grid
    for(int i = 0; i< Global::gridSizeX; i++)
    {
        for(int j =0; j < Global::gridSizeY; j++)
        {
            image->setPixelColor(i, j, QColor(255,255,255,0).rgba());
        }
    }
    return image;
}

void Project::addNewFrame()
{
    frames.push_back(createNewFrame());
    if (frames.size() > 1)
    {
        setCurrentFrame(frames.size() - 1);
        frameView->addFrame();
    }
}


/*UI Helpers*/


void Project::setActiveTool(Global::Tool tool)
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
    if(label == leftColorLabel)
    {
        tools->setLeftSelectedColor(color.rgba());
    }
    if(label == rightColorLabel)
    {
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

void Project::updatePreviewImage()
{
    canvas->setImage(previewImage);
}


/*File IO*/


void Project::save(QString filename)
{
    qInfo() << filename;
}

void Project::load(QString filename)
{
    qInfo() << filename;
}

void Project::exportGIF(QString filename)
{
    qInfo() << filename;
}
