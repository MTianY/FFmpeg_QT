#include "audiothread.h"
#include "QFile"
#include "QDebug"

// 导入 ffmpeg 头文件
extern "C" {
  #include "libavdevice/avdevice.h"
  #include "libavformat/avformat.h"
  #include "libavutil/avutil.h"
}

AudioThread::AudioThread(QObject *parent) : QThread(parent) {
  // 监听线程结束时(finished), 调用 deleteLater 回收内存
  connect(this, &AudioThread::finished,
          this, &AudioThread::deleteLater);
}

AudioThread::~AudioThread() {

  // 内存回收之前, 正常结束线程
  requestInterruption();

  // QT 特性函数, 防止回收过快
  quit();
  wait();

  qDebug() << this << "析构";
}

// 耗时操作放到子线程
void AudioThread::run() {
  // 1. 注册设备 (放到 main 函数位置了)

  // 2. 获取输入格式对象
  // 参数传设备名字
  const char *fmtName = "avfoundation";
  AVInputFormat *inputFormat = av_find_input_format(fmtName);

  if (!inputFormat) {
      qDebug() << "获取输入对象格式失败" <<fmtName;
      return;
    }

  // 3. 打开设备

  // 格式上下文, 可以利用上下文操作设备, 要初始化
  AVFormatContext *ctx = nullptr;
  // 设备名称
  const char *deviceName = ":0";
  // 参数, 暂时不需要
  AVDictionary *options = nullptr;
  // avformat_open_input 权限问题会造成闪退
  int ret = avformat_open_input(&ctx, deviceName, inputFormat, &options);
  if (ret < 0) {
      char errbuf[1024];
      av_strerror(ret, errbuf, sizeof(errbuf));
      qDebug() << "打开设备失败" << errbuf;
      return;
    }

  // 4. 采集数据

  // 存储采集的数据
  // 文件名
  const char* fileName = "~/Desktop/FFmpeg_QT/Demo/out.pcm";
  QFile file(fileName);

  // 打开文件
  // WriteOnly, 只写, 如果文件不存在, 则创建文件. 如果文件存在, 则清空内容.
  file.open(QFile::WriteOnly);

  if (!file.open(QFile::WriteOnly)) {
      qDebug() << "文件打开失败" << fileName;
      // 关闭设备
      avformat_close_input(&ctx);
      return;
    }

  // 数据包
  AVPacket pkt;
  // 采集一次数据 0 if OK, < 0 on error or end of file
//  av_read_frame(ctx, &pkt);

  // 多次采集

  while (!isInterruptionRequested()) {

      ret = av_read_frame(ctx, &pkt);
      if (ret == 0) { // 读取成功
          // 将数据写入文件 (先放入内存缓冲区, 缓冲区满了再放入文件, 减少 IO 操作)
          file.write((const char *)pkt.data, pkt.size);
        } else {
          // AVERROR(EAGAIN) -35错误

          char errbuf[1024];
          av_strerror(ret, errbuf, sizeof(errbuf));
          qDebug() << "av_read_frame 错误" << errbuf << ret;
        }


    }

}
