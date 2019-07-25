#ifndef TIMER_H
#define TIMER_H

#include <QThread>

class timer : public QThread
{
    Q_OBJECT
public:
    explicit timer(QObject *parent=nullptr);


    void run();  //function to run the timer


    bool stop; //stores the value true and false returned by the cpp file


    void stopTimer();  //function to terminate the timer


 signals:
    void numberChanged(int);


    void timerStopped(int);


};

#endif // TIMER_H


