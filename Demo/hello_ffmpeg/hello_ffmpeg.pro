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
# 默认链接动态库, 假设找不到动态库,则找静态库链接
# 如果需要指定链接静态库, 则添加 -static 参数
# LIBS += -L /usr/local/Cellar/ffmpeg/4.3.2_1/lib -static\
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
