#include "tools.h"
 #include <QDebug>

/* PUBLIC */
Tools::Tools(QImage* image, QImage* previewImage) :
    currentImage(image),
    previewImage(previewImage)
{
    painter = new QPainter(image);
    previewPainter = new QPainter(previewImage);

    eraserPen.setColor(QColor(255,255,255,0).rgba()); // I don't think this is a good design
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
            fillTool(point);
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
    QPoint inputPos = point.toPoint();
    QColor tmpFillColor = currentImage->pixelColor(inputPos);
    qDebug() <<  "fill Color tt:" <<tmpFillColor;
    floodFill(inputPos, tmpFillColor);
    qDebug() << "fill Tool still alive";

}

void Tools::floodFill(QPoint currentPos, QColor prevColor)
{
    //qDebug() << "flood Fill still alive";

    /* check color equal */
    if(!((currentImage->pixelColor(currentPos)) == prevColor)) {
        //qDebug() << "current Color:" << prevColor;
        //qDebug() << "current Color:" << currentImage->pixelColor(currentPos);
        //qDebug() << "pixelColor still alive";
        return;
    }

    /* replace Color */
    painter->drawPoint(static_cast<int>(currentPos.x()), static_cast<int>(currentPos.y()));

    /* check in boundry */
    if(currentPos.x() == 0 || currentPos.x() == currentImage->width() || currentPos.y() == 0 || currentPos.y() == currentImage->height()) {
        // qDebug() << "poscheck still alive";
        return;
    }

    /* fill all four pos */
    QPoint westPos(currentPos.x() + 1, currentPos.y());
    QPoint eastPos(currentPos.x() - 1, currentPos.y());
    QPoint northPos(currentPos.x(), currentPos.y() + 1);
    QPoint southPos(currentPos.x(), currentPos.y() - 1);

    floodFill(westPos, prevColor);
    floodFill(eastPos, prevColor);
    floodFill(northPos, prevColor);
    floodFill(southPos, prevColor);
}
