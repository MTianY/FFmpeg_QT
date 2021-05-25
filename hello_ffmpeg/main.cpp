#include "mainwindow.h"

#include <QApplication>


// 引入 ffmpeg 头文件
extern "C" {
  #include <libavcodec/avcodec.h>
}


int main(int argc, char *argv[])
{

    qDebug() << av_version_info();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
