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

    // PLEASE REQUEST THE PUBLIC FUNCTION OR SLOT HERE BEFORE EDIT
    // SO THAT I CAN KEEP TRACK ALL THE PROGRESS
    // LEAVE YOUR REQUEST HERE:
    //

public:
    Tools(QImage* image);
    void setImage(QImage* image);

    // LOOK AT THIS - MAY CHANGE THOS TO SLOTS
    void setSelectedTool(int tool);
    void setSelectedColor(QColor color);
    void setBrushSize(int size); // NEW!

public slots:
    void handleMousePress(QPointF point);
    void handleMouseMove(QPointF point);
    void handleMouseRelease(QPointF point);

signals :
    void imageUpdated();

private:
    /* field */
    int selectedTool;
    QColor selectedColor;
    int selectedBrushSize;

    QPainter* painter;
    QImage* tempImage;
    QImage* currentImage;

    QPointF startPoint;
    QPointF currentPoint;

    /* functions */
    void useTool(QPointF point);
    void penTool(QPointF point);
    void eraser(QPointF point);
    void lineTool(QPointF point);
    void fillTool(QPointF point);
    void brushTool(QPointF point);
};

#endif // TOOLS_H
