#include "audiothread.h"
#include <QFile>

extern "C" {
  // 格式相关
  #include "libavformat/avformat.h"
  // 工具类
  #include "libavutil/avutil.h"
}


AudioThread::AudioThread(QObject *parent) : QThread(parent)
{

}

AudioThread::~AudioThread() {

}

// 当线程启动时(start), 会自动调用 run 函数
// run 函数中代码是在子线程执行的
// 耗时操作放在 run 函数中
void AudioThread::run() {
  // 录音逻辑

  // 1.获取输入格式对象
  const char *fmtName = "avfoundation";
  AVInputFormat *input_fmt = av_find_input_format(fmtName);
  if (!input_fmt) {
//      qDebug() << "获取输入格式对象失败!"  << fmtName;
      return;
  }

  // 2.打开设备
  // 上下文
  AVFormatContext *ctx = nullptr;

  // 设备名称
  const char *deviceName = ":0";
  // 选项
//  AVDictionary *options;

  // @return 0 on success, a negative AVERROR on failure.
  int ret = avformat_open_input(&ctx, deviceName, input_fmt, nullptr);
  // 或者 options 传空, 用 nullptr
//  avformat_open_input(&ctx, deviceName, input_fmt, nullptr);
  if (ret < 0) {
      char errbuf[1024];
      av_strerror(ret, errbuf, sizeof(errbuf));
      return;
  }

  // 3. 采集数据
  // 文件名
  const char *fileName = "/Users/Maty/Desktop/out.pcm";
  // 创建文件
  QFile file(fileName);
  // 打开文件
  // WriteOnly 只写, 文件不存在则创建新的文件, 文件存在则清空文件内容
  if (!file.open(QFile::WriteOnly)) {
//     qDebug() << "文件打开失败!" << fileName;
     // 关闭设备
     avformat_close_input(&ctx);
  }


  // 数据包
  AVPacket pkt;
  // 这只采集一次
//  av_read_frame(ctx, &pkt);

  // 暂定采集次数 50 次
  int count = 50;

  // 不断的采集数据
  //0 if OK, < 0 on error or end of file. On error, pkt will be blank
  // av_read_frame 等于 0 则表示采集成功
  while (count-- > 0 &&  av_read_frame(ctx, &pkt) == 0) {
      // 将采集的数据写入文件
      file.write((const char *)pkt.data, pkt.size);
    }

  // 4. 释放资源
  // 关闭文件
  file.close();
  // 关闭设备
  avformat_close_input(&ctx);
}
