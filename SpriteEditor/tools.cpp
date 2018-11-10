#include "tools.h"


/* PUBLIC */
Tools::Tools(QImage* image) : currentImage(image){
    painter = new QPainter(image);
}

Tools::~Tools()
{
    delete painter;
}

void Tools::setImage(QImage* image)
{
    currentImage = image;
    delete painter;
    painter = new QPainter(image);
}

void Tools::setSelectedTool(Global::Tool tool)
{
    selectedTool = tool;
}

void Tools::setLeftSelectedColor(QColor color)
{
    leftSelectedColor = color;
    leftPen.setColor(color.rgba());
}

void Tools::setRightSelectedColor(QColor color)
{
    rightSelectedColor = color;
    rightPen.setColor(color.rgba());
}

void Tools::setBrushSize(int size)
{
    selectedBrushSize = size;
}


/* slots */


void Tools::handleMousePress(QPointF point)
{
    switch(selectedTool)
    {
        case Global::Tool::pen:
            penTool(point);
            break;
        case Global::Tool::eraser:
            eraser(point);
            break;
        case Global::Tool::line:
            startPoint = point;
            break;
        case Global::Tool::fill:
            //fillTool();
            break;
        case Global::Tool::brush:
            //brushTool();
            break;
    }
    emit imageUpdated();
}

void Tools::handleMouseMove(QPointF point)
{
    switch(selectedTool)
    {
        case Global::Tool::pen:
            penTool(point);
            break;
        case Global::Tool::eraser:
            eraser(point);
            break;
        case Global::Tool::line:
            //startPoint = point;
            break;
        case Global::Tool::fill:
            //fillTool();
            break;
        case Global::Tool::brush:
            //brushTool();
            break;
    }
    emit imageUpdated();
}

void Tools::handleMouseRelease(QPointF point)
{
    switch(selectedTool)
    {
        case Global::Tool::pen:
            penTool(point);
            break;
        case Global::Tool::eraser:
            eraser(point);
            break;
        case Global::Tool::line:
            lineTool(point);
            break;
        case Global::Tool::fill:
            //fillTool();
            break;
        case Global::Tool::brush:
            //brushTool();
            break;
    }
    emit imageUpdated();
}


/* PRIVATE */


void Tools::penTool(QPointF point)
{
    painter->setPen(leftPen);
    painter->drawPoint(point.x(), point.y());
}

void Tools::eraser(QPointF point)
{
    painter->setPen(leftPen);
    painter->drawPoint(point.x(), point.y());
}

void Tools::lineTool(QPointF point)
{
    painter->setPen(leftPen);
    painter->drawLine(startPoint.x(), startPoint.y(), point.x(), point.y());
}

