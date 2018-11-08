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
    Tools(QImage& image);

    void setImage(QImage& image);

    void startPos(QPointF start, QImage initImage);
    void endPos(QPointF end);

    void setSelectedTool(int tool);
    void setSelectedColor(QColor color);


private:
    /* field */
    int selectedTool;
    QColor selectedColor;
    QPainter painter;
    QImage tempImage;
    QImage& currentImage;
    QPointF startPoint;
    QPointF currentPoint;


    /* functions */
    void useTool(QPointF point);
    void penTool(QPointF point);
    void eraser(QPointF point);
    void lineTool(QPointF point);
    void fillTool(QPointF point);
    void brushTool(QPointF point);

signals :
    void imageUpdated();

public slots:
    void handleMousePress(QPointF point);
    void handleMouseMove(QPointF point);
    void handleMouseRelease(QPointF point);

};

#endif // TOOLS_H
