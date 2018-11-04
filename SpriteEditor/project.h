#ifndef PROJECT_H
#define PROJECT_H
#include <QPixmap>
#include "canvas.h"

class Project
{
public:
    Project();
    void setPixel(int x, int y, QRgb rgbColor);
    void createNewFrame();
private:
    std::string editingMode;
    std::vector<Canvas> frames;
    int currentFrame;
    QRgb currentColor;
};

#endif // PROJECT_H
