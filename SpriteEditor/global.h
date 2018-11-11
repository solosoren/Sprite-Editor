#ifndef GLOBAL_H
#define GLOBAL_H

#include <QPixmap>


namespace Global
{

    // Window sizes
    static int windowSizeX = 600;
    static int windowSizeY = 600;
    static int animationWindowSize = 295;
    static int frameWindowSize = 150;

    // Grid sizes
    static int gridSizeX = 32;
    static int gridSizeY = 32;

    static QPixmap convertImageToPixmap(QImage image, int window)
    {
        if (window == 0)
        {
            return QPixmap().fromImage(image.scaled(windowSizeX, windowSizeY));
        }
        else if (window == 1)
        {
            return QPixmap().fromImage(image.scaled(animationWindowSize, animationWindowSize));
        }
        return QPixmap().fromImage(image.scaled(frameWindowSize, frameWindowSize));

    }

    static QPixmap convertImageToPixmapWithGridLines(QImage image)
    {
        QImage scaledImage = image.scaled(windowSizeX, windowSizeY);

        // "pixel" grid size = (windowSizeX / gridX) and (windowSizeY / gridY)
        for(int x = 0; x < windowSizeX; x++)
        {
            // Vertical
            if((x % (windowSizeX / gridSizeX)) == 0)
            {
                for(int y = 0; y < windowSizeY; y++)
                {
                    scaledImage.setPixelColor(x, y, QColor(0, 0, 0).rgba());
                }
            }

            // Horizontal
            for(int y = 0; y < windowSizeY; y+=(windowSizeY/ gridSizeY))
            {
                scaledImage.setPixelColor(x, y, QColor(0, 0, 0).rgba());
            }
        }

        return QPixmap().fromImage(scaledImage);
    }

    const QString buttonHighlightFormat = QString("background-color: %1").arg(QColor(Qt::green).name());
    const QString buttonNonHighlightFormat = QString("background-color: %1").arg(QColor(Qt::white).name());

    enum class Tool
    {
        pen,
        eraser,
        line,
        fill,
        brush,
    };
}

#endif // GLOBAL_H
