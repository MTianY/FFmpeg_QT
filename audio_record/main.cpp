#include "mainwindow.h"

#include <QApplication>

extern "C" {
// 设备相关
#include "libavdevice/avdevice.h"
}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  // 注册设备, 放在这里是想只执行一次
  avdevice_register_all();

  return a.exec();
}
