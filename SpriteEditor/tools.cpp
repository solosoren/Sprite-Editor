#include "tools.h"
#include <QDebug>

Tools::Tools(QImage image){
    this->currentImage = image;

}

/* slots */
/* position */
void Tools::startPos(QPointF start, QImage initImage){
    startPoint = start;
    tmpImage = initImage;
    currentImage = initImage;
}

void Tools::endPos(QPointF end) {
    currentPoint = end;
}

/* tools selection */
void Tools::setTool(int tool) {
    //selectedTool = tool;
}
void Tools::setColor(QColor color) {
    //selectedColor = color;
}

/* signals */
QImage Tools::sendImage() {
    return currentImage;
}

void Tools::useTool(int tool) {
    switch(tool) {
        case PEN_TOOL:
            //penTool();
            break;
        case ERASER:
            //eraser();
            break;
        case LINE_TOOL:
            //lineTool();
            break;
        case FILL_TOOL:
            //fillTool();
            break;
        case BRUSH_TOOL:
            //brushTool();
            break;
    }
}

void Tools::penTool(int x, int y) {
    this->currentImage.setPixelColor(x, y, QColor(200, 150, 200).rgba());
}

/* SLOTS */

/* mouse pos */
void Tools::handleMousePress(QPointF point)
{
    penTool(point.x(), point.y());
    emit updateImage(currentImage);
    qInfo() << "TOOLS: Handled Mouse Press at: " << point;
}

void Tools::handleMouseMove(QPointF point)
{
    qInfo() << "TOOLS: Handled Move Press at: " << point;
}

void Tools::handleMouseRelease(QPointF point)
{
    qInfo() << "TOOLS: Handled Release Press at: " << point;
}

/* color */

/* tool selection */
