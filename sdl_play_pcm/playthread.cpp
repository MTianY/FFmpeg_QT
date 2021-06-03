#include "playthread.h"
#include <QDebug>
#include <QFile>
#include <SDL2/SDL.h>

#define BUFFER_SIZE 4096

playthread::playthread(QObject *parent) : QThread(parent)
{
  connect(this, &playthread::finished,
          this, &playthread::deleteLater);
}

playthread::~playthread() {
  disconnect();
  requestInterruption();
  quit();
  wait();

  qDebug() << this << "析构了";
}


void showVersion() {
  SDL_version sdl_ver;
  SDL_VERSION(&sdl_ver);
  qDebug() << sdl_ver.major << sdl_ver.minor << sdl_ver.patch;
}

// 读到数据的大小
int bufferLen;
// 读取到的数据
char *bufferData;

// 等待音频设备回调数据(会回调多次)
/**
 * param: stream 需要往 stream 中填充的 PCM 数据
 * param: len 希望填充的大小(字节数)(samples * format * channel / 8)
 */
void pull_audio_data(void *userdata, Uint8 *stream, int len) {
  // 这和 run 方法里不是一个线程

  // 1. 清空 stream
  SDL_memset(stream, 0, len);

  // 2. 文件数据还没准备好,直接 return
  if (bufferLen <= 0) return;

  // 取len, bufferLen 的最小值
  len = (len > bufferLen) ? bufferLen : len;

  // 3. 填充数据
  SDL_MixAudio(stream, (Uint8 *)bufferData, len, SDL_MIX_MAXVOLUME);
  bufferData += len;
  bufferLen += len;
}

void playthread::run() {
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
  // 回调音频设备数据
  spec.callback = pull_audio_data;

  // 音频缓存区的样本数量(这个值必须是 2 的幂)
  spec.samples = 4096;

  if(SDL_OpenAudio(&spec, nullptr)) {
      qDebug() <<"SDL_OpenAudio error" << SDL_GetError();
      // 清除所有子系统
      SDL_Quit();
      return;
  }

  // 3.打开文件
  QFile file("/Users/Maty/Desktop/44100_2_s16le.pcm");
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


  // 5.读数据
  // 存放从文件中读取的数据
  char data[BUFFER_SIZE];
  // 线程不结束,就一直执行
  while(!isInterruptionRequested()) {
      bufferLen = file.read(data, BUFFER_SIZE);

      if (bufferLen <= 0) {
          break;
        }

      // 读取到了数据
      bufferData = data;

      // 延迟下, 神操作..看不懂
      // 等待音频数据填充完毕
      // 只要音频数据还没填充完,就等待
      while(bufferLen > 0) {
          SDL_Delay(1);
        }

    }

  // 关闭文件
  file.close();

  // 关闭设备
  SDL_CloseAudio();

  // 清除所有子系统
  SDL_Quit();
}
