#include "mainwindow.h"
#include "ui_mainwindow.h"

extern "C" {
  // 格式相关
  #include "libavformat/avformat.h"
  // 工具类
  #include "libavutil/avutil.h"
}

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_auidioButton_clicked()
{
  // 录音逻辑

  // 1.获取输入格式对象
  const char *fmtName = "avfoundation";
  AVInputFormat *input_fmt = av_find_input_format(fmtName);
  if (!input_fmt) {
      qDebug() << "获取输入格式对象失败!"  << fmtName;
      return;
  }

  qDebug() << "获取输入格式对象成功:" << fmtName;

  // 2.打开设备

  // 上下文
  AVFormatContext *ctx = nullptr;

  // 设备名称
  const char *deviceName = "";
  // 选项
  AVDictionary *options;

  // @return 0 on success, a negative AVERROR on failure.
  int ret = avformat_open_input(&ctx, deviceName, input_fmt, &options);
  // 或者 options 传空, 用 nullptr
//  avformat_open_input(&ctx, deviceName, input_fmt, nullptr);

  if (ret < 0) {
      char errbuf[1024];
      av_strerror(ret, errbuf, sizeof(errbuf));
      qDebug() << "打开设备失败!" << errbuf;
      return;
  }

  qDebug() << ctx;
}
