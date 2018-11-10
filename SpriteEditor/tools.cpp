#include "tools.h"


/* PUBLIC */
Tools::Tools(QImage* image, QImage* previewImage) :
    currentImage(image),
    previewImage(previewImage)
{
    painter = new QPainter(image);
    previewPainter = new QPainter(previewImage);
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
    leftPen.setColor(color.rgba());
}

void Tools::setRightSelectedColor(QColor color)
{
    rightPen.setColor(color.rgba());
}

void Tools::setBrushSize(int size)
{
    selectedBrushSize = size;
}


/* slots */


void Tools::handleMousePress(int button, QPointF point)
{
    setButton(button);
    useTool(point, MouseEventType::press);
}

void Tools::handleMouseMove(int button, QPointF point)
{
    setButton(button);
    useTool(point, MouseEventType::move);
}

void Tools::handleMouseRelease(int button, QPointF point)
{
    setButton(button);
    useTool(point, MouseEventType::release);
}


/* PRIVATE */


void Tools::createLinePreview(QPointF point)
{
    previewImage = new QImage();
    QPoint paintPos(0,0);
    previewPainter->setPen(activePen); //for some reason this needs to be reset here, to work correctly.
    previewPainter->drawImage(paintPos, *currentImage); //draw the current image to the preview image.
    previewPainter->drawLine(startPoint.x(), startPoint.y(), point.x(), point.y());
}

void Tools::setButton(int button)
{
    if (button == Qt::RightButton) { activePen = rightPen; }
    else if (button == Qt::LeftButton) { activePen = leftPen; }
}

void Tools::useTool(QPointF point, MouseEventType mouseEventType)
{
    painter->setPen(activePen);
    switch(selectedTool)
    {
        case Global::Tool::pen:
            penTool(point);
            emit imageUpdated();
            break;
        case Global::Tool::eraser:
            eraser(point);
            emit imageUpdated();
            break;
        case Global::Tool::line:
            if (mouseEventType == MouseEventType::press)
            {
                startPoint = point;
                emit imageUpdated();
            }
            else if (mouseEventType == MouseEventType::move)
            {
                createLinePreview(point);
                emit previewImageUpdated();
            }
            else if (mouseEventType == MouseEventType::release)
            {
                lineTool(point);
                emit imageUpdated();
            }
            break;
        case Global::Tool::fill:
            //fillTool();
            break;
        case Global::Tool::brush:
            //brushTool();
            break;
    }
}

void Tools::penTool(QPointF point)
{
    painter->drawPoint(point.x(), point.y());
}

void Tools::eraser(QPointF point)
{
    painter->drawPoint(point.x(), point.y());
}

void Tools::lineTool(QPointF point)
{
    painter->drawLine(startPoint.x(), startPoint.y(), point.x(), point.y());
}

