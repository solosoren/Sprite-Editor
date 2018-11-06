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
    static int gridX = 5;
    static int gridY = 5;

    static QPixmap convertImageToPixmap(QImage image) {
         return QPixmap().fromImage(image.scaled(windowSizeX,windowSizeY));
    }
}

#endif // MAINWINDOW_H
