/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <videoslider.h>
#include "videowidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *playerWidget;
    QWidget *openFilePage;
    QPushButton *openFileBtn;
    QWidget *videoPage;
    VideoWidget *videoWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *playAndStop;
    QPushButton *playBtn;
    QPushButton *stopBtn;
    QHBoxLayout *progress;
    videoSlider *progressSlider;
    QLabel *curTime;
    QLabel *label_2;
    QLabel *totolTime;
    QHBoxLayout *vol;
    QPushButton *volBtn;
    videoSlider *volSlider;
    QLabel *volLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(839, 575);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        playerWidget = new QStackedWidget(centralwidget);
        playerWidget->setObjectName(QString::fromUtf8("playerWidget"));
        openFilePage = new QWidget();
        openFilePage->setObjectName(QString::fromUtf8("openFilePage"));
        openFileBtn = new QPushButton(openFilePage);
        openFileBtn->setObjectName(QString::fromUtf8("openFileBtn"));
        openFileBtn->setGeometry(QRect(370, 200, 80, 24));
        playerWidget->addWidget(openFilePage);
        videoPage = new QWidget();
        videoPage->setObjectName(QString::fromUtf8("videoPage"));
        videoWidget = new VideoWidget(videoPage);
        videoWidget->setObjectName(QString::fromUtf8("videoWidget"));
        videoWidget->setGeometry(QRect(20, 20, 791, 451));
        playerWidget->addWidget(videoPage);

        verticalLayout->addWidget(playerWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        playAndStop = new QHBoxLayout();
        playAndStop->setObjectName(QString::fromUtf8("playAndStop"));
        playBtn = new QPushButton(centralwidget);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));

        playAndStop->addWidget(playBtn);

        stopBtn = new QPushButton(centralwidget);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));

        playAndStop->addWidget(stopBtn);


        horizontalLayout->addLayout(playAndStop);

        progress = new QHBoxLayout();
        progress->setObjectName(QString::fromUtf8("progress"));
        progressSlider = new videoSlider(centralwidget);
        progressSlider->setObjectName(QString::fromUtf8("progressSlider"));
        progressSlider->setMinimumSize(QSize(200, 0));
        progressSlider->setOrientation(Qt::Horizontal);

        progress->addWidget(progressSlider);

        curTime = new QLabel(centralwidget);
        curTime->setObjectName(QString::fromUtf8("curTime"));

        progress->addWidget(curTime);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        progress->addWidget(label_2);

        totolTime = new QLabel(centralwidget);
        totolTime->setObjectName(QString::fromUtf8("totolTime"));

        progress->addWidget(totolTime);


        horizontalLayout->addLayout(progress);

        vol = new QHBoxLayout();
        vol->setObjectName(QString::fromUtf8("vol"));
        volBtn = new QPushButton(centralwidget);
        volBtn->setObjectName(QString::fromUtf8("volBtn"));

        vol->addWidget(volBtn);

        volSlider = new videoSlider(centralwidget);
        volSlider->setObjectName(QString::fromUtf8("volSlider"));
        volSlider->setMinimumSize(QSize(100, 0));
        volSlider->setValue(99);
        volSlider->setOrientation(Qt::Horizontal);

        vol->addWidget(volSlider);

        volLabel = new QLabel(centralwidget);
        volLabel->setObjectName(QString::fromUtf8("volLabel"));

        vol->addWidget(volLabel);


        horizontalLayout->addLayout(vol);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 839, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openFileBtn->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        playBtn->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276", nullptr));
        stopBtn->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        curTime->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        totolTime->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        volBtn->setText(QCoreApplication::translate("MainWindow", "\351\235\231\351\237\263", nullptr));
        volLabel->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
