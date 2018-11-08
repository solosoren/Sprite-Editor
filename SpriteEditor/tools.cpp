#include "tools.h"
#include <QDebug>

/* PUBLIC */
Tools::Tools(QImage* image) : currentImage(image){}

void Tools::setImage(QImage* image)
{
    currentImage = image;
}

void Tools::setSelectedTool(int tool)
{
    selectedTool = tool;
}

void Tools::setSelectedColor(QColor color)
{
    selectedColor = color;
}

void Tools::setBrushSize(int size)
{
    selectedBrushSize = size;
}

/* slots */

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


/* PRIVATE */

void Tools::useTool(QPointF point)
{
    switch(selectedTool)
    {
        case GLOBAL::PEN:
            penTool(point);
            break;
        case GLOBAL::ERASER:
            eraser(point);
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
    currentImage->setPixelColor(static_cast<int>(point.x()), static_cast<int>(point.y()), selectedColor.rgba());
}

void Tools::eraser(QPointF point) {
    currentImage->setPixelColor(static_cast<int>(point.x()), static_cast<int>(point.y()), QColor(255,255,255).rgba());
}


