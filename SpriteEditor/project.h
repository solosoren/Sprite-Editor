#ifndef PROJECT_H
#define PROJECT_H
#include <QPixmap>
#include "canvas.h"
#include "tools.h"

class Project
{
public:
    Project();
    void setCurrentFrame(int frameNumber);
    void createNewFrame();
private:
    std::string editingMode;
    std::vector<QImage> frames;
    int currentFrame;
    Tools tools;
};

#endif // PROJECT_H
