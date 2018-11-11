#include "tools.h"

/* PUBLIC */
Tools::Tools(QImage* image, QImage* previewImage) :
    currentImage(image),
    previewImage(previewImage)
{
    painter = new QPainter(image);
    previewPainter = new QPainter(previewImage);

    eraserPen.setColor(QColor(255,255,255,0).rgba());
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
    previewPainter->drawLine(static_cast<int>(startPoint.x()), static_cast<int>(startPoint.y()), static_cast<int>(point.x()), static_cast<int>(point.y()));
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
            if (mouseEventType == MouseEventType::press || mouseEventType == MouseEventType::move)
            {
                penTool(point);
            }
            emit imageUpdated();
            break;

        case Global::Tool::eraser:
            if (mouseEventType == MouseEventType::press || mouseEventType == MouseEventType::move)
            {
                eraser(point);
            }
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
            if (mouseEventType == MouseEventType::press)
            {
                fillTool(point);
            }
            emit imageUpdated();
            break;

        case Global::Tool::brush:
            //brushTool();
            break;
    }
}

void Tools::penTool(QPointF point)
{
    painter->drawPoint(static_cast<int>(point.x()), static_cast<int>(point.y()));
}

void Tools::eraser(QPointF point)
{
    painter->setPen(eraserPen);
    painter->drawPoint(static_cast<int>(point.x()), static_cast<int>(point.y()));
}

void Tools::lineTool(QPointF point)
{
    painter->drawLine(static_cast<int>(startPoint.x()), static_cast<int>(startPoint.y()), static_cast<int>(point.x()), static_cast<int>(point.y()));
}

void Tools::fillTool(QPointF point)
{
    int x = static_cast<int>(point.x());
    int y = static_cast<int>(point.y());

    QColor tmpFillColor = currentImage->pixelColor(x, y);
    floodFill(x, y, tmpFillColor);
}

void Tools::floodFill(int x, int y, QColor prevColor)
{
    /* base check */
    if (x < 0 || x >= currentImage->width() || y < 0 || y >= currentImage->height()){
        return;
    }

    /* check color equal */
    if(!((currentImage->pixelColor(x,y)) == prevColor)) {
        return;
    }

    /* replace Color */
    painter->drawPoint(x, y);

    /* fill all four pos */
    floodFill(x+1, y, prevColor);
    floodFill(x-1, y, prevColor);
    floodFill(x, y+1, prevColor);
    floodFill(x, y-1, prevColor);
}
