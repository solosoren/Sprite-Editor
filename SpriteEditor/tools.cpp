#include "tools.h"
#include <QDebug>

/* PUBLIC */
Tools::Tools(QImage* image) : currentImage(image){
    painter = new QPainter(image);
}

void Tools::setImage(QImage* image)
{
    currentImage = image;
}

void Tools::setSelectedTool(int tool)
{
    selectedTool = tool;
}

void Tools::setLeftSelectedColor(QColor color)
{
    leftSelectedColor = color;
}

void Tools::setRightSelectedColor(QColor color)
{
    rightSelectedColor = color;
}

void Tools::setBrushSize(int size)
{
    selectedBrushSize = size;
}

/* slots */

void Tools::handleMousePress(QPointF point)
{
    startPoint = point;
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
            lineTool(point);
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
    QPen pen;
    pen.setColor(leftSelectedColor.rgba());
    painter->setPen(pen);
    painter->drawPoint(point.x(), point.y());
}

void Tools::eraser(QPointF point) {
    QPen pen;
    pen.setColor(QColor(255,255,255,0).rgba());
    painter->setPen(pen);
    painter->drawPoint(point.x(), point.y());
}

void Tools::lineTool(QPointF point) {
    QPen pen;
    pen.setColor(leftSelectedColor.rgba());
    painter->setPen(pen);
    painter->drawLine(startPoint.x(), startPoint.y(), point.x(), point.y());
}

