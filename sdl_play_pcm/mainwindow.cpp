#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <SDL2/SDL.h>
#include <QDebug>

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

void showVersion() {
  SDL_version sdl_ver;
  SDL_VERSION(&sdl_ver);
  qDebug() << sdl_ver.major << sdl_ver.minor << sdl_ver.patch;
}

void MainWindow::on_pushButton_clicked()
{
   showVersion();
}
