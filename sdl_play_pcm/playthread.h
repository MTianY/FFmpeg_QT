#ifndef PLAYTHREAD_H
#define PLAYTHREAD_H

#include <QThread>

class playthread : public QThread
{
  Q_OBJECT
public:
  void run();
  explicit playthread(QObject *parent = nullptr);
  ~playthread();

signals:

};

#endif // PLAYTHREAD_H
