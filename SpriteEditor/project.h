#ifndef PROJECT_H
#define PROJECT_H
#include <QPixmap>
#include "canvas.h"

class Project
{
public:
    Project();
    void setCurrentFrame(int frameNumber);
    void createNewFrame();
private:
    std::string editingMode;
    std::vector<Canvas> frames;
    int currentFrame;
    QRgb currentColor;
};

#endif // PROJECT_H
