#include "spriteanimation.h"

SpriteAnimation::SpriteAnimation(std::vector<QImage*>& images)
{
    images = images;
    imagesDidChange = false;
    frameRate = 0;
}

void SpriteAnimation::imagesDidUpdate()
{
    imagesDidChange = true;
    animate();
}

// SetFrameRate Slot

void SpriteAnimation::animate()
{
    int frameIndex = 0;
    int frameCount = 0;
    while (!imagesDidChange && frameRate > 0 && images->size() > 0)
    {
       QImage  image   = *((*images)[frameIndex]);
       QPixmap pixmap  = convertImageToPixmap(image);
       QTimer::singleShot(frameCount++ * (1000 / frameRate), this, SLOT(displayFrame(pixmap&)));
    }
}

void SpriteAnimation::displayFrame(QPixmap* pixmap)
{

}
