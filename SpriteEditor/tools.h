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
    Tools();

    /* slots */
    /* position */
    void startPos(QPointF start, QImage initImage);
    void endPos(QPointF end);
    /* tools selection */
    void setTool(int tool);
    void setColor(QColor color);

    /* signals */
    QImage sendImage();


private:
    /* field */
    static int selectedTool;
    static QColor selectedColor;
    QPainter doPaint;
    QImage tmpImage;
    QImage currentImage;
    QPointF startPoint;
    QPointF currentPoint;


    /* functions */
    void useTool(int tool);
    void penTool();
    void eraser();
    void lineTool();
    void fillTool();
    void brushTool();

public slots:
    void handleMousePress(QPointF point);
    void handleMouseMove(QPointF point);
    void handleMouseRelease(QPointF point);

};

#endif // TOOLS_H
