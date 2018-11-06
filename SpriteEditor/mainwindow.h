#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

friend int main(int argc, char *argv[]);
};

namespace GLOBAL{

    // Window sizes
    static int windowSizeX = 600;
    static int windowSizeY = 600;

    // Grid sizes
    static int gridX = 8;
    static int gridY = 8;

    static QPixmap convertImageToPixmap(QImage image) {
         return QPixmap().fromImage(image.scaled(windowSizeX,windowSizeY));
    }

    /* tmp NEED TO BE CHANGED*/
    const int PEN_TOOL = 0;
    const int ERASER = 1;
    const int LINE_TOOL = 2;
    const int FILL_TOOL = 3;
    const int BRUSH_TOOL = 4;
}

#endif // MAINWINDOW_H
