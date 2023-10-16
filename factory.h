#ifndef FACTORY_H
#define FACTORY_H

#include "producer.h"

class factory : public producer
{
public:
    factory(QWidget *parent = Q_NULLPTR); // constructor calls producer constructor and sets cost, count and cps to default values
};

#endif // FACTORY_H
