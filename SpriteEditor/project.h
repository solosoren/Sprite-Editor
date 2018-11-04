#ifndef PROJECT_H
#define PROJECT_H
#include <QPixmap>

class Project
{
public:
    Project();
    void setPixel(int x, int y, QRgb rgbColor);
private:
    std::string editingMode;
};

#endif // PROJECT_H
