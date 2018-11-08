#include "spriteanimation.h"

SpriteAnimation::SpriteAnimation()
{
    imagesDidChange = false;
    frameRate = 0;
}

void SpriteAnimation::setImages(std::vector<QImage*>* images)
{
    images = images;
    imagesDidChange = true;
    animate();
}

// SetFrameRate Slot

void SpriteAnimation::animate()
{
    int frameIndex = 0;
    int frameCount = 0;
    while (true)
    {
        if (frameRate > 0 && images->size() > 0)
        {
            QImage  image   = *((*images)[frameIndex++ % images->size()]);
            QPixmap pixmap  = convertImageToPixmap(image);
            QTimer::singleShot(frameCount++ * (1000 / frameRate), this, SLOT(displayFrame(pixmap)));
        }
    }
}

void SpriteAnimation::displayFrame(QPixmap pixmap)
{
    this->addPixmap(pixmap);
}
