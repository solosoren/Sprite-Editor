#include "canvas.h"
#include <QDebug>

Canvas::Canvas(QImage* image, QObject *parent):
    image(image),
    QGraphicsScene (parent)
{
    /* Initializations */
    enableDebugging = false;
    enableGridLines = false;
    setStickyFocus(true);

    updatePixmap();
}

void Canvas::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) {
    QPointF pointPressed = convertToPoint(mouseEvent->scenePos());
    pointDebugMessage("Clicked mouse at ", pointPressed);

    if(mouseEvent->button() == Qt::LeftButton) {
        emit mouseLeftPressed(pointPressed);
    }
    else if(mouseEvent->button() == Qt::RightButton) {
        emit mouseRightPressed(pointPressed);
    }
}

void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent) {
    QPointF pointMoved = convertToPoint(mouseEvent->scenePos());
    pointDebugMessage("Mouse moved to ", pointMoved);
    emit mouseMoved(pointMoved);
}

void Canvas::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent) {
    QPointF pointReleased = convertToPoint(mouseEvent->scenePos());
    pointDebugMessage("Released mouse at ", pointReleased);
    emit mouseReleased(pointReleased);
}

void Canvas::updatePixmap() {
    //Instead of scaling pixmap, scale qimage
    if(enableGridLines) {
        pixmap = convertImageToPixmapWithGridLines(*image);
    }
    else {
        pixmap = convertImageToPixmap(*image);
    }

    this->clear();
    this->addPixmap(pixmap);
}

void Canvas::pointDebugMessage(QString message, QPointF point) {
    if(enableDebugging) {
         qInfo() << "CANVAS: "<< message << point;
    }
}

QPointF Canvas::convertToPoint(QPointF scaledPos) {
    int rX = scaledPos.x();
    int rY = scaledPos.y();

    int xPos =(int) (rX * gridSizeX) / windowSizeX;
    int yPos = (int) (rY * gridSizeY) / windowSizeY;
    if(xPos < 0) {
        xPos = 0;
    }
    if(yPos < 0) {
        yPos = 0;
    }
    if(xPos >= gridSizeX) {
        xPos= gridSizeX - 1;
    }
    if(yPos >= gridSizeY) {
        yPos = gridSizeY - 1;
    }
    return QPointF(xPos, yPos);
}

void Canvas::setImage(QImage* image) {
    this->image = image;
    updatePixmap();
}

void Canvas::toggleGridlines() {
    enableGridLines = !enableGridLines;
    updatePixmap();
}
