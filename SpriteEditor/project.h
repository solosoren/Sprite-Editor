#ifndef PROJECT_H
#define PROJECT_H
#include <QPixmap>
#include "canvas.h"
#include "tools.h"
#include "spriteanimation.h"

class Project
{
public:
    Project();
    ~Project();
    void setCurrentFrame(int frameNumber);
    void createNewFrame();
    Canvas* getCanvas();
private:
    //SpriteAnimation animation;
    std::vector<QImage*> frames;
    int currentFrame;
    Tools tools;
    Canvas* canvas;

friend class SpriteAnimation;
};

#endif // PROJECT_H
