#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/icons/icons/startup.jpg");  // 设置启动图片
    QSplashScreen splash(pixmap);
    splash.show();
    MainWindow w;
    QTimer::singleShot(2000, &splash, [&](){
        w.show();
        splash.finish(&w);
    });
    return a.exec();
}
