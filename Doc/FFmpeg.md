# FFmpeg

## 命令简介

FFmpeg 的 `bin` 目录提供了三个命令:

- ffmpeg
- ffplay
- ffprobe

### ffmpeg

主要作用: `对音视频进行编解码`.

```shell
# 将 MP3 文件转成 WAV 文件
ffmpeg -i xx.mp3 yy.wav
```

通用命令格式:

```shell
ffmpeg arg1 arg2 -i arg3 arg4 arg5
```

- arg1 全局参数
- arg2 输入文件参数
- arg3 输入文件
- arg4 输出文件参数
- arg5 输出文件

### ffprobe

主要作用: `查看音视频的参数信息`.

```shell
# 查看 MP3 文件的采样率, 比特率, 时长等信息
ffprobe xx.mp3
```

通用格式:

```shell
ffprobe [OPTIONS] [INPUT_FILE]
```

- OPTIONS: 参数
- INPUT_FILE: 输入文件

### ffplay

主要作用: `播放音视频`

```shell
# 播放 MP3 文件
ffplay xx.mp3
```

通用格式:

```shell
ffplay [options] input_file
```

- options: 参数
- input_file: 输入文件

## 通过命令行录音

### 1. 查看可用设备

```shell
# 查看当前平台的可用设备
ffmpeg -devices
```

