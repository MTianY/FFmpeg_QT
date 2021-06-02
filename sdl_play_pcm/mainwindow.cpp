#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <SDL2/SDL.h>
#include <QDebug>
#include <QFile>

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

void showVersion() {
  SDL_version sdl_ver;
  SDL_VERSION(&sdl_ver);
  qDebug() << sdl_ver.major << sdl_ver.minor << sdl_ver.patch;
}

void MainWindow::on_pushButton_clicked()
{
   showVersion();

   // 1.初始化 Audio 子系统
   if(SDL_Init(SDL_INIT_AUDIO) != 0) {
      qDebug() << "SDL_Init error" << SDL_GetError();
      return;
   }

   // 2.打开设备
   // 音频参数
   SDL_AudioSpec spec;
   // 采样率
   spec.freq = 44100;
   // 格式
   // 有符号, 16 位, 小端
   spec.format = AUDIO_S16LSB;
   // 声道数
   spec.channels = 2;

   if(SDL_OpenAudio(&spec, nullptr)) {
       qDebug() <<"SDL_OpenAudio error" << SDL_GetError();
       // 清除所有子系统
       SDL_Quit();
       return;
   }

   // 3.打开文件
   QFile file("");
   if(!file.open(QFile::ReadOnly)) {
       qDebug() << "file open error" << "";
       // 关闭设备
       SDL_CloseAudio();
       // 清除子系统
       SDL_Quit();
       return;
     }

   /*
    SDL 播放音频有 2 中模式:
    1.Push(推): 程序主动推送数据给音频设备
    2.Pull(拉): 音频设备主动向程序拉取数据
   */

   // 4.开始播放
   // 传 1 表示暂停, 0 则表示不要暂停即播放
   SDL_PauseAudio(0);

   // 清除所有子系统
   SDL_Quit();

}
