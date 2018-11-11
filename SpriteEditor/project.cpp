#include "project.h"


Project::Project()
{
    addNewFrame();
    previewImage = createNewFrame();
    currentFrame = 0;

    canvas = new Canvas(frames[currentFrame]);
    animation = new SpriteAnimation();
    animation->setImages(&frames);

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

QImage* Project::createNewFrame()
{
    QImage* image = new QImage(Global::gridSizeX, Global::gridSizeY, QImage::Format_ARGB32);
    // Initializes empty grid
    for(int i = 0; i< Global::gridSizeX; i++)
    {
        for(int j =0; j < Global::gridSizeY; j++)
        {
            image->setPixelColor(i, j, QColor(255,255,255,255).rgba());
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
    frameView->updateFrame(currentFrame);
}

void Project::updatePreviewImage()
{
    canvas->setImage(previewImage);
}


/*File IO*/


void Project::save(QString filename)
{
    if ( ! filename.contains(".ssp")) {filename = filename.append(".ssp");}
    QFile saveFile(filename);
    saveFile.open((QIODevice::WriteOnly | QIODevice::Text));
    QTextStream writer(&saveFile);

    writer << Global::gridSizeX << " " << Global::gridSizeY << '\n';
    writer << frames.size() << '\n';

    for (QImage* image : frames)
    {
        for (int y = 0; y < Global::gridSizeY; y++)
        {
            for (int x = 0; x < Global::gridSizeX; x++)
            {
                QColor color = image->pixelColor(x,y);
                writer << color.red() << " " << color.green() << " "
                       << color.blue() << " " << color.alpha() << " ";

            }
            writer << '\n';
        }
    }
    saveFile.close();
}

void Project::load(QString filename)
{
    QFile loadFile(filename);
    loadFile.open((QIODevice::ReadOnly | QIODevice::Text));
    QTextStream reader(&loadFile);
    loadFile.close();
}

void Project::exportGIF(QString filename)
{
    //
}
