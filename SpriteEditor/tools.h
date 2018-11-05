#ifndef TOOLS_H
#define TOOLS_H

#include <QObject>
#include <QColor>
#include <QPainter>
#include <vector>

// KUNAAL: Needs to be static if it's outside the tools class. I don't see why this needs
//         to be accessible to any other class.I think you should put this within the Tools class.
static int selectedTool = 0;

class Tools : public QObject
{
    Q_OBJECT

    public:
        Tools();

        std::vector<QPointF> startPos(QPointF StartPos);
        std::vector<QObject> endPos(QPointF endPos);


    private:
        /* define tools */
        const int PEN_TOOL = 0;
        const int ERASER = 1;
        const int LINE_TOOL = 2;
        const int FILL_TOOL = 3;
        const int BRUSH_TOOL = 4;

        QColor currentColor;
        QPainter doPaint;
        QImage tmpImage;
        QImage currentImage;


};

#endif // TOOLS_H
