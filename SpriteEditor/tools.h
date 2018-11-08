#ifndef TOOLS_H
#define TOOLS_H

#include <QObject>
#include <QColor>
#include <QPainter>
#include <vector>
#include "global.h"

/* only receive one Pos
 * only return one Qimage */

class Tools : public QObject
{
    Q_OBJECT

public:
    Tools(QImage image);

    /* slots */
    /* position */
    void startPos(QPointF start, QImage initImage);
    void endPos(QPointF end);
    /* tools selection */
    void setTool(int tool);
    void setColor(QColor color);

    /* signals */
    QImage sendImage();

    QColor getSelectedColor();
    void setSelectedColor(QColor newColor);


private:
    /* field */
    static int selectedTool;
    QColor selectedColor;
    QPainter doPaint;
    QImage tmpImage;
    QImage currentImage;
    QPointF startPoint;
    QPointF currentPoint;


    /* functions */
    void useTool(int tool);
    void penTool(int x, int y);
    void eraser();
    void lineTool();
    void fillTool();
    void brushTool();

signals :
    void updateImage(QImage);

public slots:
    void handleMousePress(QPointF start);
    void handleMouseMove(QPointF end);
    void handleMouseRelease(QPointF end);

};

#endif // TOOLS_H
