#include "mainwindow.h"

#include <QApplication>

// 导入 ffmpeg 头文件
extern "C" {
  #include "libavdevice/avdevice.h"
}

int main(int argc, char *argv[])
{

  // 注册设备 (这里保证只注册一次)
  avdevice_register_all();

  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
