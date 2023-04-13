#ifndef AUDIOTHREAD_H
#define AUDIOTHREAD_H

#include <QThread>

class AudioThread : public QThread {
public:
  explicit AudioThread(QObject *parent = nullptr);
  ~AudioThread();
private:
  void run();
};

#endif // AUDIOTHREAD_H
