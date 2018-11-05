#include "spriteanimation.h"

SpriteAnimation::SpriteAnimation(std::vector<QImage*>& images)
{
    images = images;
    frameRate = 0;
}

// SetFrameRate Slot

void SpriteAnimation::animate()
{
    int frameIndex = 0;
    while (!imagesDidChange && frameRate > 0)
    {
       QImage  image   = *((*images)[frameIndex]);
       QPixmap pixmap  = convertImageToPixmap(image);
       QTimer::singleShot(1000 / frameRate, this, SLOT(displayFrame()));
       // displayPixmap using qtimer * framerate
    }
}
