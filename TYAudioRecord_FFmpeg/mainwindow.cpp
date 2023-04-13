#include "mainwindow.h"
#include "ui_mainwindow.h"

// 导入 ffmpeg 头文件
extern "C" {
  #include "libavdevice/avdevice.h"
  #include "libavformat/avformat.h"
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


// 开始录音
void MainWindow::on_startAudioRecord_clicked() {

  if (!_audioThread) {
       // 创建线程执行录音耗时操作
       _audioThread = new AudioThread(this);
       // 开启线程, 执行里面的 run()
       _audioThread->start();

       ui->startAudioRecord->setText("停止录音");

    } else {

      // 结束线程, 调用后线程会中断
      _audioThread->isInterruptionRequested();

      ui->startAudioRecord->setText("开始录音");
    }

}
