#include "spriteanimation.h"


SpriteAnimation::SpriteAnimation()
{
    this->images = nullptr;
    frameRate = 0;
}

void SpriteAnimation::setImages(std::vector<QImage*>* images)
{
    this->images = images;
}


void SpriteAnimation::setFrameRate(int rate)
{
    int oldRate = frameRate;
    frameRate = rate;
    if (oldRate == 0) { startAnimation(); }
}

void SpriteAnimation::startAnimation()
{
    int frameIndex = 0;
    int frameCount = 0;
    if (images != nullptr)
    {
        while (frameRate > 0 && images->size() > 0)
        {
            QImage  image   = *((*images)[frameIndex++ % images->size()]);
            QPixmap pixmap  = Global::convertImageToPixmap(image);
            QTimer::singleShot(frameCount++ * (1000 / frameRate), this, SLOT(displayFrame(pixmap)));
        }
    }
}

void SpriteAnimation::displayFrame(QPixmap pixmap)
{
    this->clear();
    this->addPixmap(pixmap);
}
