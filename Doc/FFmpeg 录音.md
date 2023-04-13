# FFmpeg 实现录音功能

## FFmpeg 命令行操作

> 仅 Mac 平台

查看可用设备:

```sh
ffmpeg -devices

输出:
Devices:
 D. = Demuxing supported
 .E = Muxing supported
 --
  E audiotoolbox    AudioToolbox output device
 D  avfoundation    AVFoundation input device
 D  lavfi           Libavfilter virtual input device
  E sdl,sdl2        SDL2 output device
 D  x11grab         X11 screen capture, using XCB
```

查看 avfoundation 支持的设备:

```sh
ffmpeg -list_devices true -f avfoundation -i ''

输出:
[AVFoundation indev @ 0x7fba6c0043c0] AVFoundation video devices:
[AVFoundation indev @ 0x7fba6c0043c0] [0] FaceTime HD Camera
[AVFoundation indev @ 0x7fba6c0043c0] [1] Capture screen 0
[AVFoundation indev @ 0x7fba6c0043c0] AVFoundation audio devices:
[AVFoundation indev @ 0x7fba6c0043c0] [0] Built-in Microphone
```

指定设备进行录音

```sh
// :0 表示使用 0 号音频设备
// 0:2 表示使用0 号视频设备和 2 号音频设备
ffmpeg -f avfoundation -i :0 out.wav
```

## FFmpeg 代码实现
## 录音功能的主要步骤:

- 注册设备
- 获取输入格式对象
- 打开设备
- 采集数据
- 释放资源

### 1. 注册设备

> avdevice_register_all
            
### 2. 获取输入格式对象

> av_find_input_format

### 3. 打开设备

> avformat_open_input

### 4. 采集数据

> av_read_frame

### 5. 释放资源

>avformat_close_input


//This app has crashed because it attempted to access privacy-sensitive data without a usage description.  The app's Info.plist must contain an NSMicrophoneUsageDescription key with a string value explaining to the user how the app uses this data.

