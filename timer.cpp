#include "timer.h"
#include <QtCore>
timer::timer(QObject *parent):QThread (parent){


}
void timer :: run()
{
    for(int i=120;i>=0;i--){

       QMutex mutex;
       mutex.lock();




        emit numberChanged(i);
        this->msleep(1000);
    if( this -> stop){

      emit timerStopped(i);
  }
}
}
void timer::stopTimer(){
  int i=1;
  for(i;i=1;i++){
      if (stop=true){
          break;
       }
  }
}



