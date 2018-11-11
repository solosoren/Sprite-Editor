#include "canvas.h"


Canvas::Canvas(int frameSize, QImage* image, QObject *parent):
    framePixelSize(frameSize),
    image(image),
    QGraphicsScene (parent)
{
    /* Initializations */
    enableDebugging = false;
    enableGridLines = false;
    setStickyFocus(true);

    updatePixmap();
}

void Canvas::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    QPointF pointPressed = convertToPoint(mouseEvent->scenePos());
    emit mousePressed(mouseEvent->button(), pointPressed);
}

void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    QPointF pointMoved = convertToPoint(mouseEvent->scenePos());
    emit mouseMoved(mouseEvent->button(), pointMoved);
}

void Canvas::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    QPointF pointReleased = convertToPoint(mouseEvent->scenePos());
    emit mouseReleased(mouseEvent->button(),pointReleased);
}

void Canvas::updatePixmap()
{
    //Instead of scaling pixmap, scale qimage
    if( enableGridLines)
    {
        pixmap = Global::convertImageToPixmapWithGridLines(*image);
    }
    else
    {
        pixmap = Global::convertImageToPixmap(*image, 0);
    }

    this->clear();
    this->addPixmap(pixmap);
}

QPointF Canvas::convertToPoint(QPointF scaledPos)
{
    int rX = scaledPos.x();
    int rY = scaledPos.y();

    int xPos =(int) (rX * framePixelSize) / windowSize;
    int yPos = (int) (rY * framePixelSize) / windowSize;

    if (xPos < 0) { xPos = 0; }
    if (yPos < 0) { yPos = 0; }
    if (xPos >= framePixelSize) { xPos = framePixelSize - 1; }
    if (yPos >= framePixelSize) { yPos = framePixelSize - 1; }

    return QPointF(xPos, yPos);
}

void Canvas::setImage(QImage* image)
{
    this->image = image;
    updatePixmap();
}

void Canvas::toggleGridlines()
{
    enableGridLines = !enableGridLines;
    updatePixmap();
}
