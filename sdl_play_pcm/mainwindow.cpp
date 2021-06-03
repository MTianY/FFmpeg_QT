#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "playthread.h"

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

void MainWindow::on_pushButton_clicked()
{
  playthread *play = new playthread(this);
  play->start();
}
