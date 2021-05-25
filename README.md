# FFmpeg Demo 文档

## 一. QT 中集成 FFmpeg 库

### 1. 找到 ffmpeg 库所在路径

本人 Mac 下路径如下:

```c
/usr/local/Cellar/ffmpeg/
```

### 2.创建一个 QT 项目

1. 项目名: hello_ffmpeg
2. 配置`hello_ffmpeg.pro` 文件, 引入 FFmpeg 库

- 配置 FFmpeg 库头文件路径
- 配置 FFmpeg 库文件路径(链接库文件)

代码如下:

```c++
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# 头文件路径
INCLUDEPATH += /usr/local/Cellar/ffmpeg/4.3.2_1/include

# 库文件路径 (链接库文件)
LIBS += -L /usr/local/Cellar/ffmpeg/4.3.2_1/lib \
        -lavcodec \
        -lavdevice \
        -lavfilter \
        -lavformat \
        -lavresample \
        -lavutil \
        -lpostproc \
        -lswresample \
        -lswscale
```
  
  ### 测试 FFmpeg 是否导入 QT 成功
  
  在 `main.cpp` 中, 代码如下:
  
  ```c++
  #include "mainwindow.h"

  #include <QApplication>


  // 引入 ffmpeg 头文件
  extern "C" {
     #include <libavcodec/avcodec.h>
  }


  int main(int argc, char *argv[])
 {
    
    // 打印 FFmpeg 版本
    qDebug() << av_version_info();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
 }
  ```
  
  打印如下:
  
  ```c++
  23:05:15: Starting /Users/Maty/Desktop/FFmpeg_QT/build-hello_ffmpeg-Desktop_x86_darwin_generic_mach_o_64bit-Debug/hello_ffmpeg.app/Contents/MacOS/hello_ffmpeg ...
4.3.2
23:05:25: /Users/Maty/Desktop/FFmpeg_QT/build-hello_ffmpeg-Desktop_x86_darwin_generic_mach_o_64bit-Debug/hello_ffmpeg.app/Contents/MacOS/hello_ffmpeg exited with code 0
  ```

---

