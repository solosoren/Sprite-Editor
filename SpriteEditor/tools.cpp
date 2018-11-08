#include "tools.h"
#include <QDebug>

Tools::Tools(QImage& image) : currentImage(image)
{

}

void Tools::setImage(QImage& image)
{
    currentImage = image;
}


void Tools::startPos(QPointF start, QImage initImage){
    startPoint = start;
    tempImage = initImage;
    currentImage = initImage;
}

void Tools::endPos(QPointF end)
{
    currentPoint = end;
}

void Tools::setSelectedTool(int tool)
{
    selectedTool = tool;
}

void Tools::useTool(QPointF point)
{
    switch(selectedTool)
    {
        case GLOBAL::PEN:
            penTool(point);
            break;
        case GLOBAL::ERASER:
            //eraser();
            break;
        case GLOBAL::LINE:
            //lineTool();
            break;
        case GLOBAL::FILL:
            //fillTool();
            break;
        case GLOBAL::BRUSH:
            //brushTool();
            break;
    }
}

void Tools::penTool(QPointF point)
{
    this->currentImage.setPixelColor(point.x(), point.y(), selectedColor.rgba());
}

/* SLOTS */

void Tools::handleMousePress(QPointF point)
{
    useTool(point);
    emit imageUpdated();
}

void Tools::handleMouseMove(QPointF point)
{
    useTool(point);
    emit imageUpdated();
}

void Tools::handleMouseRelease(QPointF point)
{
    qInfo() << "TOOLS: Handled Release Press at: " << point;
}

void Tools::setSelectedColor(QColor color)
{
    selectedColor = color;
}
