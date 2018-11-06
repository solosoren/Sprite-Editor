#ifndef TOOLS_H
#define TOOLS_H

#include <QObject>
#include <QColor>
#include <QPainter>
#include <vector>

#include "toollist.h"

// KUNAAL: Needs to be static if it's outside the tools class. I don't see why this needs
//         to be accessible to any other class.I think you should put this within the Tools class.
static int selectedTool = 0;
static QColor selectedColor;

class Tools : public QObject
{
    Q_OBJECT

    public:
        Tools();

        /* position */
        std::vector<QImage> startPos(QPointF startPos, QImage initImage);
        std::vector<QImage> endPos(QPointF endPos);

        /* tools selection */
        void setTool(int tool);
        void setColor(QColor color);

    private:
        /* field */
        QPainter doPaint;
        QImage tmpImage;
        QImage currentImage;
        QPoint currentPos;

        /* functions */
        void useTool(int tool);
        void penTool();
        void eraser();
        void lineTool();
        void fillTool();
        void brushTool();

};

#endif // TOOLS_H
