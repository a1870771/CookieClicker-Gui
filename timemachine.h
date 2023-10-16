#ifndef TIMEMACHINE_H
#define TIMEMACHINE_H

#include "producer.h"

class timeMachine : public producer
{
public:
    timeMachine(QWidget *parent = Q_NULLPTR); // constructor calls producer constructor and sets cost, count and cps to default values
};

#endif // TIMEMACHINE_H
