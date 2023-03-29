#include "mainwindow.h"
#include "ui_mainwindow.h"

#import "audiothread.h"


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


void MainWindow::on_auidioButton_clicked()
{

   AudioThread *audioThread = new AudioThread(this);
   // 启动线程(会自动销毁)
   audioThread -> start();

}
